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

const int mod = 1e9 + 7;
const int maxn = 1000010;
ll fac[maxn],invFac[maxn];

ll modPow(ll a, ll b){
	if(b==0){return 1;}
	else{
		if(b%2==1){
			return ((a%mod)*(modPow(a,b-1)%mod))%mod;
		}else{
			ll temp = modPow(a,b/2)%mod;
			return ((temp%mod) * (temp%mod))%mod;
		}
	}
}

ll inv(ll a){
	return modPow(a,mod-2)%mod;
}

ll c(ll n, ll k){
	return ((((fac[n]%mod)*(invFac[n-k]%mod))%mod)*(invFac[k]%mod))%mod;
}

int main() {
	ll n,a,b,d;
	fac[0] = 1;
	invFac[0] = inv(fac[0]);
	for(int i=1;i<maxn;i++){
		fac[i] = ((fac[i-1] % mod)*(i % mod))%mod;
		invFac[i] = inv(fac[i])%mod;
	}
	//printf("test\n");
	while(scanf("%lld %lld %lld %lld",&n,&a,&b,&d)!=EOF){
		ll banyakCara1Sekolah = c(b,d);
		ll banyakCaraSiswaUntukAsekolah = modPow(banyakCara1Sekolah,a);
		ll banyakCaraMilihSekolah = c(n,a);
		ll ans = ((banyakCaraSiswaUntukAsekolah%mod)*(banyakCaraMilihSekolah%mod))%mod;
		printf("%lld\n",ans);
	}
	return 0;
}