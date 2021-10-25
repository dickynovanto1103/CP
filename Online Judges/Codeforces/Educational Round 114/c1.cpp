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
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,i,j;
	scanf("%d",&n);
	vi v(n);
	for(auto &x: v) {
		scanf("%lld",&x);
	}
	sort(v.begin(), v.end());
	// for(auto &x: v)
	// 	printf("x: %lld\n", x);
	ll sum = accumulate(v.begin(), v.end(), 0LL);
	
	int m;
	scanf("%d",&m);
	while(m--){
		ll def, att;
		scanf("%lld %lld",&def,&att);
		int idx = lower_bound(v.begin(), v.end(), def) - v.begin();
		// printf("idx: %d\n", idx);
		ll ans = 2e18;
		if(idx > 0) {
			ans = min(ans, (def - v[idx-1]) + max(0LL, att - sum + v[idx-1]));
			// printf("ans skrg: %lld\n", ans);
		}

		if(idx < n) {
			ans = min(ans, max(0LL, att - sum + v[idx]));
			// printf("ans skrg2: %lld\n", ans);
		}
		printf("%lld\n", ans);
	}
	
	return 0;
};