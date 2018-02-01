#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000


int main(){
	int tc,i,j,u,v,s,d,V,E,k,a;
	int dist[110][110];

	scanf("%d",&tc);
	for(i=1;i<=tc;i++){
		scanf("%d %d",&V,&E);
		for(a=0;a<100;a++){
			for(j=0;j<100;j++){
				dist[a][j]=inf;
			}
		}
		for(a=0;a<V;a++) dist[a][a]=0;
		//memset(dist, inf, sizeof dist);
		for(j=0;j<E;j++){
			scanf("%d %d",&u,&v);
			dist[u][v]=dist[v][u]=1;
		}
		scanf("%d %d",&s,&d);
		//floyd warshall
		for(k=0;k<V;k++){
			for(a=0;a<V;a++){
				for(j=0;j<V;j++){
					dist[a][j]=min(dist[a][j],dist[a][k] + dist[k][j]);
				}
			}
		}
		int ans=-1;
		for(j=0;j<V;j++){
			//printf("dist[%d][%d] = %d + dist[%d][%d] = %d\n",s,j,dist[s][j],j,d,dist[j][d]);
			ans=max(ans,dist[s][j] + dist[j][d]);
		}
		printf("Case %d: %d\n",i,ans);

	}
	return 0;
}