#include <cstdio>
#include <iostream>
using namespace std;

int A[110][110];

int main(){
	int R,C,i,j,k,l,ans,subrect;
	while(scanf("%d %d",&R,&C), (R||C)){
		for(i=1;i<=R;i++){
			for(j=1;j<=C;j++){
				scanf("%d",&A[i][j]);
				if(A[i][j]==0){A[i][j]=1;}
				else{A[i][j]=-100000;}//make it negative if it is a tree

				if(i>1) A[i][j]+=A[i-1][j];
				if(j>1) A[i][j]+=A[i][j-1];
				if(i>1 && j>1) A[i][j]-=A[i-1][j-1];
			}
		}
		ans=-2000000;
		for(i=1;i<=R;i++){
			for(j=1;j<=C;j++){
				for(k=i;k<=R;k++){
					for(l=j;l<=C;l++){
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