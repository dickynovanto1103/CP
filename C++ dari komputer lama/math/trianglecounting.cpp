#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,i,k,j,cnt;
	while(scanf("%d",&n),(n>=3)){
		cnt=0;
		for(i=1;i<=n-2;i++){
			for(j=i+1;j<=n-1;j++){
				for(k=j+1;k<i+j && k<=n;k++){
					cnt++;
					//printf("skrg: %d i:%d j:%d k:%d\n",cnt,i,j,k);
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}