#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> AdjList;

int dfsNumberCounter, dfsRoot, rootChildren;
vi dfs_num, dfs_low, dfs_parent, articulation_vertex;

set<ii> listBridge;

void articulationPointAndBridge(int u) {
	int j;
	dfs_num[u] = dfs_low[u] = dfsNumberCounter++;
	for(j=0;j<AdjList[u].size();j++) {
		int v = AdjList[u][j];
		if(dfs_num[v] == unvisited) {
			dfs_parent[v] = u;
			if(u == dfsRoot) {rootChildren++;}

			articulationPointAndBridge(v);

			if(dfs_low[v] >= dfs_num[u]) {
				articulation_vertex[u] = true;
			}
			if(dfs_low[v] > dfs_num[u]) {
				int minim = min(u,v);
				int maks = max(u,v);
				listBridge.insert(ii(minim,maks));
			}
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}else if(v != dfs_parent[u]){
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

class UnionFind{
private: 
	vi rank,p,setSize;
	int numset,i;
public:
	UnionFind(int n){
		numset=n; setSize.assign(n,1); rank.assign(n,0); p.assign(n,0);
		for(i=0;i<n;i++){p[i]=i;}
	}

	int findSet(int i){return (p[i]==i) ? i : (p[i]=findSet(p[i]));}
	bool isSameSet(int i, int j){return findSet(i)==findSet(j);}
	void unionSet(int i, int j){
		if(!isSameSet(i,j)){
			numset--;
			int x=findSet(i), y=findSet(j);
			if(rank[x] > rank[y]){p[y]=x; setSize[x]+=setSize[y];}
			else{
				p[x]=y;
				setSize[y]+=setSize[x];
				if(rank[x]==rank[y]){rank[y]++;}
			}
		}
	}
	int numDisjointSet(){return numset;}
	int sizeSetOf(int i){return setSize[findSet(i)];}
};

int main() {
	int V,E,i,a,b;
	scanf("%d %d",&V,&E);
	AdjList.assign(V,vi());
	//add adge
	vii listEdge;
	for(i=0;i<E;i++){
		scanf("%d %d",&a,&b);
		AdjList[a].push_back(b); AdjList[b].push_back(a);
		listEdge.pb(ii(a,b));
	}

	dfsNumberCounter = 0; dfs_num.assign(V,unvisited); dfs_low.assign(V,0);
	dfs_parent.assign(V,0); articulation_vertex.assign(V,0);
	// printf("bridges:\n");
	for(i=0;i<V;i++) {
		if(dfs_num[i] == unvisited) {
			dfsRoot = i; rootChildren = 0; articulationPointAndBridge(i);
			articulation_vertex[dfsRoot] = (rootChildren > 1);
		}
	}

	UnionFind UF(V);
	for(i=0;i<E;i++){
		ii edge = listEdge[i];
		int x = edge.first, y = edge.second;
		int minim = min(x,y);
		int maks = max(x,y);
		if(listBridge.find(ii(minim,maks)) == listBridge.end()){
			UF.unionSet(minim, maks);
		}
	}
	printf("%d\n",UF.sizeSetOf(0));
	
	return 0;
}