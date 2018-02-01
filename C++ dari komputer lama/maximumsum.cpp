#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int n,i,j,k,l;
	int A[101][101];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&A[i][j]);
			if(i>0) A[i][j]+=A[i-1][j];
			if(j>0) A[i][j]+=A[i][j-1];
			if(i>0 && j>0) A[i][j]-= A[i-1][j-1];//inclusion-exclusion principle
		}
	}
	int subRect,maxsubRect;
	subRect=0;
	maxsubRect=-127*10000;//lowest possible value
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			for(k=i;k<n;k++){
				for(l=j;l<n;l++){
					subRect=A[k][l];
					if(i>0) subRect-=A[i-1][l];
					if(j>0) subRect-=A[k][j-1];
					if(i>0 && j>0) subRect+=A[i-1][j-1];
					maxsubRect=max(maxsubRect,subRect);
					//printf("i: %d j: %d k: %d l: %d\n",i,j,k,l);
					//printf("subrect: %d maxsubRect: %d\n",subRect, maxsubRect);
				}
			}
		}
	}
	printf("%d\n",maxsubRect);
	return 0;
}