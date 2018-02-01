#include <cstdio>

using namespace std;

int a[110][110];
int main(){
	int n,k,i,j;
	scanf("%d %d",&n,&k);
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(k>0){
				if(a[i][j]==0){
					if(i==j){a[i][j]=1; k--;}
					else if(k>=2){a[i][j] = a[j][i] = 1; k-=2;}
				}
			}
		}
	}
	if(k>0){printf("-1\n"); return 0;}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(j){printf(" ");}
			printf("%d",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}