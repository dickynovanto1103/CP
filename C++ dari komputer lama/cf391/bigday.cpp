#include <bits/stdc++.h>

using namespace std;

int cnt[100100];

int main(){
	int n,a,i,j;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a);
		cnt[a]++;
	}
	int maks=1;
	for(i=2;i<100010;i++){
		int hit=0;
		for(j=i;j<100010;j+=i){hit+=cnt[j];}
		maks=max(maks,hit);
	}
	printf("%d\n",maks);
	return 0;
}