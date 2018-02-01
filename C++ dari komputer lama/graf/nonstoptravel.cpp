#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000

int p[12][12];

void printpath(int i,int j){
	if(i!=j) printpath(i,p[i][j]);
	printf(" %d",j);
}

int main(){
	int V,totalneighbor,v,w,awal,akhir,tc=1,i,j,k;
	int dist[12][12];
	
	while(scanf("%d",&V),V){
		for(i=1;i<=V;i++){
			for(j=1;j<=V;j++){
				dist[i][j]=inf;
				p[i][j]=i;
			}
		}

		for(i=1;i<=V;i++){
			dist[i][i]=0;
			scanf("%d",&totalneighbor);
			while(totalneighbor--){scanf("%d %d",&v,&w); dist[i][v]=w;}
		}
		scanf("%d %d",&awal,&akhir);	
		for(k=1;k<=V;k++){
			for(i=1;i<=V;i++){
				for(j=1;j<=V;j++){
					if(dist[i][j] > dist[i][k] + dist[k][j]){
						dist[i][j] = dist[i][k] + dist[k][j];
						//dist[j][i] = dist[i][k] + dist[k][j];
						p[i][j]=p[k][j];
					}
				}
			}
		}
		printf("Case %d: Path =",tc++);
		printpath(awal,akhir);
		printf("; %d second delay\n",dist[awal][akhir]);
	}
	

	return 0;
}