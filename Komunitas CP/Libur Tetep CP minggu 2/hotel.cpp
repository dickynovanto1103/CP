#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
	int n,maks,i,a[300010],j;
	ll sum = 0;
	scanf("%d %d",&n,&maks);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	//pakai 2 iterator
	i=0; j = 0; sum = a[j]; ll ans = -1;
	while(i<=n-1 && j<=n-1){
		if(sum<=maks){
			ans = max(ans,sum);
			j++;sum+=a[j];
		}
		else{sum-=a[i];i++;}
	}
	printf("%lld\n",ans);
	return 0;
}