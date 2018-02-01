#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int N,i,j,ans;
	int A[110][110];
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++){
			scanf("%d",&A[i][j]);
			if(i>1) A[i][j]+=A[i-1][j];
			if(j>1) A[i][j]+=A[i][j-1];
			if(i>1 && j>1) A[i][j]-=A[i-1][j-1];
		}
	}
	ans=-127*100*100;//minimum possible answer
	int subrect,k,l;
	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++){
			for(k=i;k<=N;k++){
				for(l=j;l<=N;l++){
					subrect=A[k][l];
					if(i>1) subrect-=A[i-1][l];
					if(j>1) subrect-=A[k][j-1];
					if(i>1 && j>1) subrect+=A[i-1][j-1];
					ans=max(ans,subrect);
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}