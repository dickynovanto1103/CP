#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef list<ll> vi;

ll joseph (ll n,ll k) {
    if(n==1){return 1;}
    return (joseph(n-1,k) + k-1)%n+1;
}

int main(){
	ll tc,i,n,test=1;
	ll k;
	//a.erase(a.begin()+idx);
	
	scanf("%lld",&tc);
	while(tc--){
		printf("Case %lld: ",test++);
		scanf("%lld %lld",&n,&k);
		//printf("%lld\n",joseph(n,k));
		//printf("versi iterative:\n");
		ll ans = 1;
		for(i=2;i<=n;i++){
			//printf("ans: %lld\n",ans);
			ans = (ans+k-1)%i+1;
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}