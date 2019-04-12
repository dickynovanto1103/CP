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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 2e5 + 5;

vector<vi> AdjList;

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

int main(){
	vii edgeList;
	int n,m,i,j;
	int deg[maxn];
	AdjList.assign(maxn, vi());
	memset(deg, 0, sizeof deg);
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		a--; b--;
		edgeList.pb(ii(a,b));
		deg[a]++; deg[b]++;
		AdjList[a].pb(b); AdjList[b].pb(a);
	}
	int maks = 0, idx;
	for(i=0;i<n;i++){
		if(maks < deg[i]){
			maks = deg[i];
			idx = i;
		}
	}
	UnionFind UF(n);
	for(i=0;i<AdjList[idx].size();i++){
		int v = AdjList[idx][i];
		UF.unionSet(idx, v);
		printf("%d %d\n",idx+1,v+1);
	}
	for(i=0;i<m;i++){
		ii edge = edgeList[i];
		int a = edge.first, b = edge.second;
		// printf("a: %d b: %d\n",a+1,b+1);
		if(!UF.isSameSet(a,b)){
			UF.unionSet(a,b);
			printf("%d %d\n",a+1,b+1);
			if(UF.numDisjointSet() == 1){break;}
		}
	}

	return 0;
};