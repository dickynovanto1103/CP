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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e6 + 6;
ll x[maxn], y[maxn], a[maxn];
const ll mod = 1e9 + 7;

ll modPow(ll a, ll b){
	if(b == 0){return 1;}
	else{
		if(b % 2 == 1){
			return a*modPow(a,b-1)%mod;
		}else{
			ll temp = modPow(a,b/2);
			return temp*temp % mod;
		}
	}
}

ll inverse(ll a){
	return modPow(a, mod-2);
}

int main(){
	int tc,i,j,n,k,c,d,e1,e2,f;
	
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d %d %lld %lld %d %d %d %d %d",&n,&k,&x[0],&y[0],&c,&d,&e1,&e2,&f);
		ll pref[maxn];
		pref[1] = k;
		for(i=2;i<=n;i++){
			pref[i] = pref[i-1];
			ll bil2 = modPow(i, k) - 1;
			if(bil2 < 0){bil2 += mod;}
			ll bil3 = inverse(i-1);
			ll ans = (ll)i*bil2; ans %= mod; ans *= bil3; ans %= mod;

			pref[i] += (ans);
			pref[i] %= mod;
		}
		a[0] = (x[0] + y[0]) % f;
		for(i=1;i<n;i++){
			x[i] = (ll)c*x[i-1] + (ll)d*y[i-1] + (ll)e1;
			x[i] %= f;

			y[i] = (ll)d*x[i-1] + (ll)c*y[i-1] + (ll)e2;
			y[i] %= f;


			a[i] = (x[i] + y[i]) % f;
		}
		ll ans = 0;
		for(i=0;i<n;i++){
			ll jawab = a[i]*(n-i);
			jawab %= mod;
			jawab *= pref[i+1];
			jawab %= mod;
			ans += jawab;
			ans %= mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
};