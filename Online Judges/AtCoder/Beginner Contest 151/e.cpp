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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;
const ll mod = 1e9 + 7;

ll fac[maxn], inv[maxn];

ll modPow(ll a, ll b){
	if(b == 0){return 1;}
	else{
		if(b % 2 == 1){return a*modPow(a,b-1)%mod;}
		else{
			ll temp = modPow(a,b/2);
			return temp*temp%mod;
		}
	}
}

ll c(int a, int b){
	ll bil = fac[a]*inv[b];
	bil %= mod;
	return bil*inv[a-b]%mod;
}

int main(){
	int i,j;
	fac[0] = inv[0] = 1;
	for(i=1;i<maxn;i++){
		fac[i] = (ll)i*fac[i-1];
		fac[i] %= mod;
		inv[i] = modPow(fac[i], mod-2);
	}
	int n,k;
	int a[maxn];
	scanf("%d %d",&n,&k);
	ll ans = 0;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	for(i=0;i<n;i++){
		int sisa = n - i - 1;
		if(sisa >= (k-1)){
			ll banyak = c(sisa, k-1);
			ll tot = a[i]*banyak;
			ans -= tot; ans %= mod;
			if(ans < 0){ans += mod;}
		}
	}
	for(i=0;i<n;i++){
		int sisa = i;
		if(sisa >= (k-1)){
			ll banyak = c(sisa, k-1);
			ll tot = a[i]*banyak;
			ans += tot; ans %= mod;
		}	
	}
	printf("%lld\n",ans);
	return 0;
};