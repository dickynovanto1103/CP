#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int i,j,N,TC;
	int A[2010],ans;
	scanf("%d",&TC);
	for(i=1;i<=TC;i++){
		scanf("%d",&N);
		for(j=1;j<=N;j++){
			scanf("%d",&A[j]);
		}
		ans=min(A[1],A[N]);
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}