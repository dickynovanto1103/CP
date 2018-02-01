#include <cstdio>

using namespace std;

int main(){
	int r,c,i,j,k,l,m,TC;
	int A[151][151],cnt;
	scanf("%d",&TC);
	for(m=1;m<=TC;m++){
		scanf("%d %d",&r,&c);
		for(i=1;i<=r;i++){
			for(j=1;j<=c;j++){
				scanf("%d",&A[i][j]);
			}
		}
		cnt=0;
		for(i=1;i<=r;i++){
			for(j=1;j<=c;j++){
				for(k=i+1;k<=r;k++){
					for(l=j+1;l<=c;l++){
						if((A[i][j]==A[i][l]) && (A[i][l]==A[k][j]) && (A[k][j]==A[k][l])){
							cnt++;
						}
						//printf("A[%d][%d]=%d, A[%d][%d]=%d, A[%d][%d]=%d, A[%d][%d]=%d\n",i,j,A[i][j],i,l,A[i][l],k,j,A[k][j],k,l,A[k][l]);
						//printf("cnt sekarang: %d\n",cnt);
					}
				}
			}
		}
		printf("Case #%d: %d\n",m,cnt);
	}
	return 0;
}