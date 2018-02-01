#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
typedef vector <int> vi;
typedef pair <int,int> ii;
typedef vector <ii> vii;

vector <vii> AdjList;
vi dist;

int main(){
	int v,e,s,t,tc,i,j,u,v2,w;
	scanf("%d",&tc);
	for(i=1;i<=tc;i++){
		scanf("%d %d %d %d",&v,&e,&s,&t);
		AdjList.assign(v,vii()); dist.assign(v,inf);
		for(j=0;j<e;j++){
			scanf("%d %d %d",&u,&v2,&w);
			AdjList[u].push_back(ii(v2,w));
			AdjList[v2].push_back(ii(u,w));
		}
		priority_queue <ii,vii,greater<ii> > pq; pq.push(ii(0,s));
		dist[s]=0;
		while(!pq.empty()){
			ii front=pq.top(); pq.pop();
			int d=front.first, v1=front.second;
			if(d > dist[v1]){continue;}
			for(j=0;j<AdjList[v1].size();j++){
				ii pair=AdjList[v1][j];
				if(dist[pair.first] > pair.second+dist[v1]){
					dist[pair.first]=pair.second+dist[v1];
					pq.push(ii(dist[pair.first],pair.first));
				}
			}
		}
		printf("Case #%d: ",i);
		if(dist[t]!=inf){printf("%d\n",dist[t]);}
		else{printf("unreachable\n");}
		AdjList.clear();
		dist.clear();
	}
	return 0;
}