#include <cstdio>
#include <iostream>
using namespace std;

int A[110][110];

int main(){
	int n,s,r1,c1,r2,c2,i,j,k,l,ans,subrect,TC;
	scanf("%d",&TC);
	while(TC--){
		scanf("%d",&s);
		for(i=1;i<=s;i++){
			for(j=1;j<=s;j++){
				A[i][j]=1;
			}
		}
		scanf("%d",&n);//number of blocks
		while(n--){
			scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
			for(i=r1;i<=r2;i++){
				for(j=c1;j<=c2;j++){
					A[i][j]=-100000;
				}
			}
		}
		for(i=1;i<=s;i++){
			for(j=1;j<=s;j++){
				if(i>1) A[i][j]+=A[i-1][j];
				if(j>1) A[i][j]+=A[i][j-1];
				if(i>1 && j>1) A[i][j]-=A[i-1][j-1];		
			}
		}
		
		ans=-2000000;
		for(i=1;i<=s;i++){
			for(j=1;j<=s;j++){
				for(k=i;k<=s;k++){
					for(l=j;l<=s;l++){
						subrect=A[k][l];
						if(i>1) subrect-=A[i-1][l];
						if(j>1) subrect-=A[k][j-1];
						if(i>1 && j>1) subrect+=A[i-1][j-1];
						ans=max(ans,subrect);
					}
				}
			}
		}
		if(ans>0){
			printf("%d\n",ans);	
		}else{
			printf("0\n");
		}
		
	}
	return 0;
}