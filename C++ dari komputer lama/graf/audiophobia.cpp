#include <bits/stdc++.h>

using namespace std;
#define unvisited -1
#define visited 1
typedef pair<int,int> ii;
typedef pair<double,ii> iii;
typedef vector <int> vi;
typedef vector <ii> vii;

vector <iii> EdgeList;
int awal,akhir,ans;
vector <vii> AdjList;
vi dist, dfs_num;

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
	int V,E,i,j,Q,u,v,w,tc=1;
	queue <int> q;
	while(scanf("%d %d %d",&V,&E,&Q), ((V || E) || Q)){
		if(tc>1){printf("\n");}
		UnionFind UF(V+1);
		AdjList.assign(V+1,vii());
		
		for(i=0;i<E;i++){
			scanf("%d %d %d",&u,&v,&w);
			EdgeList.push_back(make_pair(w,ii(u,v)));
		}
		sort(EdgeList.begin(),EdgeList.end());

		for(i=0;i<E;i++){
			iii front = EdgeList[i];
			int bil=front.first;
			if(!UF.isSameSet(front.second.first,front.second.second)){
				UF.unionSet(front.second.first,front.second.second);
				AdjList[front.second.first].push_back(ii(front.second.second,bil));
				AdjList[front.second.second].push_back(ii(front.second.first,bil));
			}
		}
		/*for(i=1;i<=V;i++){
			printf("node %d:",i);
			for(j=0;j<AdjList[i].size();j++){
				ii v = AdjList[i][j];
				printf(" %d(%d)",v.first,v.second);
			}
			printf("\n");
		}*/
		printf("Case #%d\n",tc++);
		
		for(i=0;i<Q;i++){
			dist.assign(V+1,0); dfs_num.assign(V+1,unvisited);
			scanf("%d %d",&awal,&akhir);
			q.push(awal); dist[awal]=0; dfs_num[awal]=visited;
			while(!q.empty()){
				int top = q.front(); q.pop();
				for(j=0;j<AdjList[top].size();j++){
					ii v = AdjList[top][j];
					if(dfs_num[v.first]==unvisited){
						dist[v.first] = max(max(dist[v.first],dist[top]),v.second);
						dfs_num[v.first]=visited;
						q.push(v.first);
					}
				}
			}
			if(dfs_num[akhir]==visited){printf("%d\n",dist[akhir]);}
			else{printf("no path\n");}
			dist.clear(); dfs_num.clear();
		}
		EdgeList.clear();
		AdjList.clear();
		dfs_num.clear();
	}
	return 0;
}