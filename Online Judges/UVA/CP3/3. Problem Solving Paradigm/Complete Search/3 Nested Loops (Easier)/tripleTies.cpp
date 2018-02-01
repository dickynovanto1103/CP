#include <bits/stdc++.h>

using namespace std;

bool isDraw(int listorg[], int a[101][101]){
	int i = listorg[0], j = listorg[1], k = listorg[2];
	return(a[i][j]==0 && a[i][k]==0 && a[j][i]==0 && a[j][k]==0 && a[k][i]==0 && a[k][j]==0);
}

bool isPotential(int listorg[], int a[101][101]){
	int i = listorg[0], j = listorg[1], k = listorg[2];
	int cnt = 0;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(j!=i){
				for(k=0;k<3;k++){
					if(k!=j && k!=i){
						printf("%d %d %d\n",i,j,k);
					}
				}	
			}
			
		}
	}
}

int main(){
	int n,a[101][101],i,j,k;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d",&a[i][j]);
			}
		}
		int listorg[3];
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				for(k=j+1;k<n;k++){
					listorg[0] = i; listorg[1] = j; listorg[2] = k;
					do{

					}while(next_permutation(listorg,listorg+3))
				}
			}
		}
	}
	return 0;
}