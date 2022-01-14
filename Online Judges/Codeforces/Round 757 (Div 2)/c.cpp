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

vector<vii> adj;
ll fac[200010];
const ll mod = 1e9 + 7;

ll modPow(ll a, ll b) {
	if(b == 0){return 1;}
	if(b % 2 == 1){
		return a * modPow(a, b-1) % mod;
	}else{
		ll temp = modPow(a, b/2);
		return temp*temp % mod;
	}
}

void buildFac() {
	fac[0] = 1;
	for(int i=1;i<=200001;i++){
		fac[i] = i * fac[i-1];
		fac[i] %= mod;
	}
}

int main(){
	buildFac();

	int tc,i,j,n,m;
	scanf("%d",&tc);
	vi a(200010);
	while(tc--){
		scanf("%d %d",&n,&m);
		fill(a.begin(), a.end(), -1);
		adj.assign(32, vii());
		for(i=0;i<m;i++){
			int l, r, x;
			scanf("%d %d %d",&l,&r,&x);
			l--; r--;
			for(j=0;j<=30;j++){
				if(!((1<<j) & x)) {
					adj[j].pb(ii(l,r));
				}
			}
		}

		for(i=0;i<=30;i++){
			sort(adj[i].begin(), adj[i].end());
			int maks = 0;
			for(ii pas: adj[i]) {
				int l = pas.first, r = pas.second;
				int bil = ~(1<<i);
				for(j=r; j>= max(maks, l);j--){
					a[j] &= bil;
				}
				maks = max(maks, r);
			}
		}

		// for(i=0;i<n;i++){
		// 	printf("%d ", a[i]);
		// }
		// puts("");
		ll ans = 0;

		for(j=0;j<=30;j++){
			int cnt1 = 0, cnt0 = 0;
			for(i=0;i<n;i++){
				if((1<<j) & a[i]) {
					cnt1++;
				}else{
					cnt0++;
				}
			}

			// printf("j: %d cnt1: %d cnt0: %d\n", j, cnt1, cnt0);

			ll basis = 1<<j;
			if(cnt1 == 0) {
				continue;
			}
			ll banyakKali = modPow(2, cnt1-1) * modPow(2, cnt0) % mod;
			ans += basis * banyakKali;
			ans %= mod;
		}
		
		printf("%lld\n", ans);
	}
	
	return 0;
};