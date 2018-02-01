#include <bits/stdc++.h>

using namespace std;

int main(){
	int tc,n,i,j;
	int a[15];
	scanf("%d",&tc);
	for(i=1;i<=tc;i++){
		scanf("%d",&n);
		int med=n/2;
		//printf("median is %d",n/2);
		for(j=0;j<n;j++) scanf("%d",&a[j]);
		//for(j=0;j<n;j++) printf("%d ",a[j]);

		printf("Case %d: %d\n",i,a[med]);
	}
	return 0;
}