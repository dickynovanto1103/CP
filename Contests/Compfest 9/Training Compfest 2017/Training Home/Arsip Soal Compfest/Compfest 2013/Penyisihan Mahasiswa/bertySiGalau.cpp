#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ll modPow(ll a, ll b, ll mod){
	if(b==0){return 1;}
	else{
		if(b%2==1){return (a%mod*modPow(a,b-1,mod)%mod)%mod;}
		else{
			ll temp = modPow(a,b/2,mod);
			return (temp%mod*temp%mod)%mod;
		}
	}
}

const ll modulo = 1e9+7;

int main() {
	ll tc,k,n,x;
	scanf("%lld",&tc);
	while(tc--){
		scanf("%lld %lld %lld",&k,&n,&x);
		printf("%lld\n",modPow(2,k*n-k,modulo)%modulo);
	}
	return 0;
}