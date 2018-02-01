#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
int dist[100][100];
int p[100][100];

void printpath(int i,int j){
	if(i!=j) printpath(i,p[i][j]);
	printf(" %d",j);
}

int main(){
	int V,E,i,k,j,u,v;
	scanf("%d %d",&V,&E);
	for(i=0;i<V;i++){
		for(j=0;j<V;j++){
			dist[i][j]=inf;
		}
	}
	for(i=0;i<E;i++){
		scanf("%d %d",&u,&v);
		dist[u][v]=dist[v][u]=1;
	}
	for(i=0;i<V;i++){
		dist[i][i]=0;
	}
	//inisialisasi parent
	for(i=0;i<V;i++){
		for(j=0;j<V;j++){
			p[i][j]=i;
		}
	}
	//floyd
	for(k=0;k<V;k++){
		for(i=0;i<V;i++){
			for(j=0;j<V;j++){
				if(dist[i][j] > dist[i][k]+dist[k][j]){
					dist[i][j]=dist[i][k]+dist[k][j];	
					p[i][j]=p[k][j];

					//printf("p[%d][%d] menjadi %d saat k = %d\n",i,j,p[k][j],k);
				}
				
				//printf("dist[%d][%d] = %d\n",i,j,dist[i][j]);
			}
		}
	}
	for(i=0;i<V-1;i++){
		for(j=i+1;j<V;j++){
			printf("path dr %d ke %d adalah:",i,j);
			printpath(i,j);
			printf("\n");
		}
	}
	printf("\n\n");
	for(i=V-1;i>=0;i--){
		for(j=i-1;j>=0;j--){
			printf("path dr %d ke %d adalah:",i,j);
			printpath(i,j);
			printf("\n");
		}
	}
	return 0;
}