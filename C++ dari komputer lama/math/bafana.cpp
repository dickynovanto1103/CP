#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,k,p,tc,i,j;
	scanf("%d",&tc);
	for(i=1;i<=tc;i++){
		scanf("%d %d %d",&n,&k,&p);
		for(j=1;j<=p;j++){k++;if(k>n){k=1;}}
		printf("Case %d: %d\n",i,k);
	}
	return 0;
}