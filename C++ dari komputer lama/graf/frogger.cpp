#include <bits/stdc++.h>
using namespace std;
#define unvisited -1
#define visited 1
typedef pair<int,double> ii;
typedef pair<double,ii> iii;
typedef vector <double> vi;
typedef vector <ii> vii;

vector <iii> EdgeList;
vector <vii> AdjList;
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

vi dist;
vi bfs_num;
int main(){
	int n,i,j,x[200],y[200],E,jarak,tc=1;
	queue <int> q;
	double hasil;
	while(scanf("%d",&n),n){
		
		UnionFind UF(n); AdjList.assign(n,vii());
		for(i=0;i<n;i++){scanf("%d %d",&x[i],&y[i]);}
		for(i=0;i<n-1;i++){
			for(j=i+1;j<n;j++){	
				hasil = hypot(x[i]-x[j], y[i]-y[j]);
				EdgeList.push_back(make_pair(hasil,ii(i,j)));
			}
		}
		sort(EdgeList.begin(), EdgeList.end());
		E = EdgeList.size();
		for(i=0;i<E;i++){
			iii front = EdgeList[i];
			int node1 = front.second.first, node2 = front.second.second;
			if(!UF.isSameSet(node1,node2)){
				UF.unionSet(node1,node2);
				AdjList[node1].push_back(ii(node2,front.first));
				AdjList[node2].push_back(ii(node1,front.first));
			}
		}
		dist.assign(n,0); bfs_num.assign(n,unvisited);
		q.push(0);
		while(!q.empty()){
			int front = q.front(); q.pop();
			for(i=0;i<AdjList[front].size();i++){
				ii v = AdjList[front][i];
				if(bfs_num[v.first]==unvisited){
					dist[v.first] = max(v.second,max(dist[v.first],dist[front]));
					bfs_num[v.first]=visited;
					q.push(v.first);
				}
			}
		}
		printf("Scenario #%d\n",tc++);
		printf("Frog Distance = %.3lf\n\n",dist[1]);
		EdgeList.clear(); AdjList.clear(); dist.clear(); bfs_num.clear();
	}
	return 0;
}