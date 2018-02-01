#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<iii> EdgeList;


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

vector<vii> AdjList;
vi dist;


int main(){
	int V,E,i,j,u,v,w,q,test=1;
	while(scanf("%d %d %d",&V,&E,&q),(V||E||q)){
		if(test>1){printf("\n");}
		printf("Case #%d\n",test++);
		AdjList.assign(V,vii());
		for(i=0;i<E;i++){scanf("%d %d %d",&u,&v,&w); u--;v--; EdgeList.push_back(make_pair(w,ii(u,v)));
			//printf("i: %d u: %d v: %d w: %d\n",i,u,v,w);
		}
		sort(EdgeList.begin(), EdgeList.end());
		UnionFind UF(V);
		for(i=0;i<E;i++){
			iii front = EdgeList[i];
			int a = front.second.first, b = front.second.second, berat = front.first;
			//printf("a: %d b: %d berat: %d\n",a,b,berat);
			if(!UF.isSameSet(a,b)){
				//printf("yang digabung: %d %d\n",a,b);
				UF.unionSet(a,b);
				AdjList[a].push_back(ii(b,berat)); AdjList[b].push_back(ii(a,berat));
			}
		}
		while(q--){
			//printf("q: %d\n",q);
			int a,b;
			dist.assign(V,0);
			scanf("%d %d",&a,&b); a--; b--;
			queue<int> que;
			que.push(a);
			while(!que.empty()){
				int u = que.front(); que.pop();
				for(i=0;i<AdjList[u].size();i++){
					ii v = AdjList[u][i];
					if(dist[v.first]==0){
						dist[v.first] = max(dist[v.first], max(v.second, dist[u]));
						que.push(v.first);
					}	
				}
			}
			if(dist[b]==0){printf("no path\n");}
			else{printf("%d\n",dist[b]);}
		}
		
		EdgeList.clear();
	}
	return 0;
}