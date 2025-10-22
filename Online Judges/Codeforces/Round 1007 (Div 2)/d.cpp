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

int a[200010];

int findAns(int n, ll idx) {
	if(idx <= n) {
		return a[idx];
	}

	int ans = 0;
	for(int i=1;i<=n;i++){
		if(a[i] == 0) {
			continue;
		}
		ll startingIdx = max(n+1, i*2);
		if(startingIdx > idx) {
			break;
		}

		ll times = idx - startingIdx + 1;
		printf("i: %d idx: %lld startingIdx %lld, times: %lld\n", i, idx, startingIdx, times);

		if(times % 2 == 1) {
			ans ^= 1;
		}
	}

	return ans;
}

void solve(){
	ll n, l, r;
	scanf("%lld %lld %lld",&n,&l,&r);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
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