#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
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
int main(){
	int V,E,i,j,k, test=1;
	int a,b,c,sum;
	while(scanf("%d %d",&V,&E),(V||E)){
		printf("Scenario #%d\n",test++);
		int sum = 0;
		for(i=0;i<E;i++){scanf("%d %d %d",&a,&b,&c); a--;b--; EdgeList.push_back(make_pair(c,ii(a,b))); sum+=c;}
		int awal,akhir,cnt;
		scanf("%d %d %d",&awal,&akhir,&cnt); awal--; akhir--;
		//kruskal
		int mst = 0;
		sort(EdgeList.begin(), EdgeList.end());
		reverse(EdgeList.begin(), EdgeList.end());
		UnionFind UF(V);
		AdjList.assign(V,vii());
		for(i=0;i<E;i++){
			iii front = EdgeList[i];
			int berat = front.first; a = front.second.first; b = front.second.second;
			if(!UF.isSameSet(a,b)){
				mst+=berat;
				//printf("yang gabung: %d %d berat: %d\n",a+1,b+1,berat);
				UF.unionSet(a,b); AdjList[a].push_back(ii(b,berat)); AdjList[b].push_back(ii(a,berat));
			}
		}
		//cari maximin
		vi dist;
		dist.assign(V,inf);
		queue<int> q;
		//dist[awal] = 0;
		q.push(awal);
		while(!q.empty()){
			int u = q.front(); q.pop();
			for(i=0;i<AdjList[u].size();i++){
				ii v = AdjList[u][i];
				//printf("v: %d berat: %d\n",v.first,v.second);
				if(dist[v.first]==inf){dist[v.first] = min(dist[v.first],min(dist[u],v.second)); q.push(v.first);}
			}
		}
		dist[awal] = 0;
		
		int maximin = dist[akhir] - 1;
		int ans = cnt/maximin;
		if(cnt%maximin!=0){ans++;}
		printf("Minimum Number of Trips = %d\n\n",ans);
		EdgeList.clear(); AdjList.clear();
	}
	return 0;
}