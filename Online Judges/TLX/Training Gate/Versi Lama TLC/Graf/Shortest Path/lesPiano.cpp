#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vii> AdjList;
vi dist;

int main() {
	int V,E,u,v,w,i,j,a,b;
	scanf("%d %d %d %d",&V,&E,&a,&b);
	dist.assign(V+1,inf); AdjList.assign(V+1,vii());
	for(i=0;i<E;i++){scanf("%d %d %d",&u,&v,&w); AdjList[u].pb(ii(v,w)); AdjList[v].pb(ii(u,w));}
	//dijkstra
	priority_queue<ii, vii, greater<ii> > pq; 
	dist[a] = 0;
	pq.push(ii(dist[a],a));
	while(!pq.empty()){
		ii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		if(d > dist[u]){continue;}
		for(i=0;i<AdjList[u].size();i++){
			ii v = AdjList[u][i];
			if(dist[u] + v.second < dist[v.first]){
				dist[v.first] = dist[u] + v.second;
				pq.push(ii(dist[v.first],v.first));
			}
		}
	}
	printf("%d\n",dist[b]);
	return 0;
}