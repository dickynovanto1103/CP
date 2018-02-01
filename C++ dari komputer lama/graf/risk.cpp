#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

int main(){
	int n,i,a,kota,b,tc=1,j,k;
	int mat[23][23];
	while(scanf("%d",&n)!=EOF){

		printf("Test Set #%d\n",tc++);
		//inisialisasi mat
		for(i=1;i<=20;i++){
			for(j=1;j<=20;j++){
				mat[i][j] = 1000000000;
			}
		}
		kota=1;
		//printf("kota: %d\n",kota);
		for(i=0;i<n;i++){scanf("%d",&a); mat[kota][a]=1; mat[a][kota]=1;}
		while(kota<19){
			
			kota++;
			//printf("kota: %d\n",kota);
			scanf("%d",&n);
			for(i=0;i<n;i++){scanf("%d",&a); mat[kota][a]=1; mat[a][kota]=1;}
		}
		//floyd warshall
		for(k=1;k<=20;k++){
			for(i=1;i<=20;i++){
				for(j=1;j<=20;j++){
					mat[i][j] = min(mat[i][j],mat[i][k] + mat[k][j]);
				}
			}
		}

		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d %d",&a,&b); 
			if(a<10){printf(" ");}
			printf("%d to ",a);
			//printf("%d to : %d\n",a,b,mat[a][b]);
			if(b<10){printf(" ");}
			printf("%d: %d\n",b,mat[a][b]);
		}
		printf("\n");
	}
	return 0;
}