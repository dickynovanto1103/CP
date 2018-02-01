#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
typedef long long ll;


int main(){
	int a[25],i,j,n,d,k,tc,cnt;
	ll ans;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		for(i=0;i<=n;i++){
			scanf("%d",&a[i]);
		}
		scanf("%d %d",&d,&k);
		cnt=0;
		for(i=1;i<=inf;i++){
			ans=0;
			for(j=0;j<=n;j++){
				ans+=a[j]*pow(i,j);
			}
			cnt+=i*d;
			if(cnt>=k){break;}
		}
		printf("%lld\n",ans);
	}
	return 0;
}