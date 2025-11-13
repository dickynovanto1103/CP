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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e6 + 6;
const int mod = 998244353;

ll modPow(ll a, ll b) {
	if(b == 0) {return 1;}
	if(b % 2 == 1) {
		ll ans = a * modPow(a, b-1);
		ans %= mod;
		return ans;
	}

	ll temp = modPow(a, b/2);
	ll ans = (temp * temp) % mod;
	return ans;
}

ll fac[maxn], invFac[maxn];
void genFac(int maks) {
	fac[0] = invFac[0] = 1;
	fac[1] = invFac[1] = 1;
	for(int i=2;i<=maks;i++){
		fac[i] = (ll)i * fac[i-1];
		fac[i] %= mod;
		invFac[i] = modPow(fac[i], mod - 2);
	}
}

ll binom(int a, int b) {
	if(b == 0) {return 1;}
	return (((fac[a] * invFac[b]) % mod) * invFac[a - b]) % mod;
}

void solve(){
	int n,d;
	genFac(maxn - 1);
	while(scanf("%d%d",&n,&d) != EOF) {
		int cnt[1000001] = {};
		int maks = 0;
		for(int i=0;i<n;i++){
			int num;
			scanf("%d",&num);
			cnt[num]++;
			maks = max(maks, num);
		}

		ll ans = 1;

		int sum = 0;
		for(int i=0;i<=maks;i++){
			sum += cnt[i];

			ans *= binom(sum, cnt[i]);
			ans %= mod;
			// printf("i: %d cnt[%d]: %d, sum: %d, ans: %lld\n", i, i, cnt[i], sum, ans);

			if(i >= d) {
				sum -= cnt[i - d];
			}
		}

		printf("%lld\n", ans);
	}
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};