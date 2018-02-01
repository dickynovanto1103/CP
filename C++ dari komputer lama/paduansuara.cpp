#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,cntgrup,i,idx[10010];
	int a[10010];
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		printf("%d (%d)\n",a[i],i);
	}
	scanf("%d",&cntgrup);
	for(i=1;i<=cntgrup-1;i++){idx[i]=i*n/cntgrup;}
	for(i=1;i<=cntgrup-1;i++){printf("indeks ke %d adalah %d\n",i,idx[i]);}
	return 0;
}