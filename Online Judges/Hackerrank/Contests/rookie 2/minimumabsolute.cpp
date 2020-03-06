#include <bits/stdc++.h>

using namespace std;
#define inf 2000000001
int a[100010];
int main(){
	int n,i,ans;
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	sort(a,a+n);
	ans = inf;
	for(i=1;i<n;i++){
		int temp = abs(a[i]-a[i-1]);
		if(temp<ans){ans = temp;}
	}
	printf("%d\n",ans);
	return 0;
}