#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int A[55],memo[55][55];

int cut(int left, int right){
	int i;
	if(left+1==right){return 0;}
	else{
		if(memo[left][right]!=-1){return memo[left][right];}
		else{
			int total=2000000000;
			for(i=left+1;i<right;i++)
				total=min(total,cut(left,i)+cut(i,right)+(A[right]-A[left]));
			return(memo[left][right]=total);
		}
	}
}

int main(){
	int l,n,i,j,left,right;
	
	while(scanf("%d",&l),(l)){
		memset(memo,-1,sizeof memo);
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&A[i]);
		}
		A[0]=0;
		A[n+1]=l;
		printf("The minimum cutting is %d.\n",cut(0,n+1));
	}
	return 0;
}