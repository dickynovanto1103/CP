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

int a[400020];

int findAns(int n, ll idx) {
	// printf("initial idx: %lld\n", idx);
	if(idx <= (2 * n) + 1) {
		return a[idx];
	}

	if(idx % 2 == 1) {
		return findAns(n, idx - 1);
	}

	if((idx / 2) % 2 == 1) {
		//find selisih with n+1
		ll diff = idx - (2*n+2);
		int mod = diff % 4;
		int pos = 2*n + 2 + mod;
		// printf("lgsg masuk sini, idx: %lld, n+1: %d, diff: %lld, mod: %d pos: %d\n", idx, n+1, diff, mod, pos);
		return a[pos];
	}

	// printf("split, find idx-2: %lld, and idx / 2: %lld\n", idx-2, idx/2);

	return findAns(n, idx-2) ^ findAns(n, idx/2);
}

void solve(){
	ll n, l, r;
	scanf("%lld %lld %lld",&n,&l,&r);
	int prefXOR[2*n+50] = {0};
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);

		prefXOR[i] = prefXOR[i-1] ^ a[i];
		// printf("xor[%d]: %d\n",i, prefXOR[i]);
	}

	for(int i=n+1;i<=2*n+10;i++){
		a[i] = prefXOR[i/2];
		prefXOR[i] = prefXOR[i-1] ^ a[i];
		// printf("a[%d]: %d xor[%d]: %d\n",i, a[i], i, prefXOR[i]);
	}

	int ans = findAns(n, l);
	printf("%d\n", ans);

}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	while(tc--){
		// printf("tc: %d\n", tc);
		solve();
	}

	return 0;
};