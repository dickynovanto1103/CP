#include <bits/stdc++.h>

using namespace std;

int main(){
	int cnt,i,n,tc,j;
	int a[110];
	scanf("%d",&tc);
	for(i=1;i<=tc;i++){
		cnt=0;
		scanf("%d",&n);
		for(j=1;j<=n;j++){scanf("%d",&a[j]);if(a[j]<60){cnt++;}}
		printf("Case #%d: %d\n",i,cnt);
	}
	return 0;
}