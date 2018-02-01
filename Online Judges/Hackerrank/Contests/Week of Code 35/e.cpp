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

const ll mod = 1e9 + 9;

ll modPow(ll a, ll b) {
	if(b==0){return 1;}
	else{
		if(b%2==1){return ((a%mod)*(modPow(a,b-1)%mod))%mod;}
		else{
			ll ans = modPow(a,b/2)%mod;
			return (ans%mod * ans%mod)%mod;
		}
	}
}

int main(){
	int tc,j;
	ll i,k;
	ll n;
	scanf("%d",&tc);
	scanf("%lld %lld",&n,&k);
	ll sum = 0;
	for(i=1LL;i<=n-2LL;i++){
		sum+=modPow(n-i,k);
		sum%=mod;
	}
	printf("%lld\n",sum);
	return 0;
};