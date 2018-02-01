#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
typedef vector <int> vi;
typedef pair <int,int> ii;
typedef vector <ii> vii;

vector <vii> AdjList;
vi dist;

int main(){
	int V,E,a,b,u,v,w,i;
	scanf("%d %d %d %d",&V,&E,&a,&b);
	dist.assign(V+1,inf);
	AdjList.assign(V+1,vii());
	for(i=0;i<E;i++){
		scanf("%d %d %d",&u,&v,&w);
		AdjList[u].push_back(ii(v,w));
		AdjList[v].push_back(ii(u,w));
	}
	//dijkstra
	priority_queue <ii,vii,greater <ii> > pq; pq.push(ii(0,a));
	dist[a]=0;
	while(!pq.empty()){
		ii front = pq.top(); pq.pop();
		int d= front.first, v1 = front.second;
		if(d > dist[v1]){continue;}
		for(i=0;i<AdjList[v1].size();i++){
			ii pair = AdjList[v1][i];
			if(dist[pair.first] > pair.second + dist[v1]){
				dist[pair.first] = pair.second + dist[v1];
				pq.push(ii(dist[pair.first],pair.first));
			}
		}
	}
	printf("%d\n",dist[b]);
	return 0;
}