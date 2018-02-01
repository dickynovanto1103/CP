#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
typedef vector <int> vi;
typedef pair<int,int> ii;
typedef vector <ii> vii;

vector <vii> AdjList;
vi dist;
int main(){
	int tc,V,E,u,v,w,exit,time,i,j,k,ans;
	scanf("%d",&tc);
	while(tc--){
		ans=0;
		k=1;
		scanf("%d %d %d %d",&V,&exit,&time,&E);
		AdjList.assign(V+10,vii());//karena dari 1 cellnya
		//printf("test %d\n",k++);
		for(i=0;i<E;i++){
			scanf("%d %d %d",&u,&v,&w);
			AdjList[u].push_back(ii(v,w));
			//printf("test %d\n",k++);
		}
		//printf("coba\n");
		//dijkstra
		for(i=1;i<=V;i++){//traversal satu"tiap node
			priority_queue <ii,vii,greater <ii> > pq; pq.push(ii(0,i));
			dist.assign(V+10,inf);
			dist[i]=0;
			while(!pq.empty()){
				ii front=pq.top(); pq.pop();
				int d=front.first, v1=front.second;
				if(d > dist[v1]){continue;}
				for(j=0;j<AdjList[v1].size();j++){
					ii pair=AdjList[v1][j];
					if(dist[pair.first] > pair.second + dist[v1]){
						dist[pair.first]=pair.second + dist[v1];
						pq.push(ii(dist[pair.first],pair.first));
					}
				}
			}
			if(dist[exit]<=time){ans++;}
		}
		printf("%d\n",ans);
		if(tc){printf("\n");}
		AdjList.clear();
		dist.clear();
	}
	return 0;
}