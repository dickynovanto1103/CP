#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
typedef vector<int> vi;
typedef pair <int,int> ii;
typedef vector <ii> vii;

vector <vii> AdjList;
vi dist;

int main(){
	int V,E,s,u,v,w,i,j;

	
	scanf("%d %d %d",&V,&E,&s);
	AdjList.assign(V,vii());
	dist.assign(V,inf);
	for(i=0;i<E;i++){
		scanf("%d %d %d",&u,&v,&w);
		AdjList[u].push_back(ii(v,w));
	}
	//dijkstra
	dist[s]=0;
	priority_queue <ii,vii,greater<ii> > pq; pq.push(ii(dist[s],s));//coba dimodif
	while(!pq.empty()){
		ii front=pq.top(); pq.pop();
		int d=front.first,v1=front.second;
		if(d > dist[v1]){continue;}//biar nanti otomatis ke pop sendiri -> lazy deletion
		for(i=0;i<AdjList[v1].size();i++){
			ii pair=AdjList[v1][i];
			if(dist[pair.first] > pair.second+dist[v1]){
				dist[pair.first]=pair.second+dist[v1];
				pq.push(ii(dist[pair.first],pair.first));
			}
		}
	}
	for(i=0;i<V;i++){
		printf("node %d dist %d\n",i,dist[i]);
	}
	return 0;
}