#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const ll mod = 1e9 + 7;

ll modPow(ll a, ll b){
	if(b==0){return 1;}
	else{
		if(b%2==1){
			return ((a%mod)*(modPow(a,b-1)%mod))%mod;
		}else{
			ll temp = modPow(a,b/2);
			return ((temp%mod)*(temp%mod))%mod;
		}
	}
}

int main(){
	int tc,i,j;
	ll n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%lld",&n);
		ll a = 1;
		ll un = 2LL*n - 1LL;
		ll ans = ((n%mod*(a+un%mod))%mod*modPow(2LL,mod-2))%mod;
		printf("%lld\n",ans);
	}
	return 0;
};