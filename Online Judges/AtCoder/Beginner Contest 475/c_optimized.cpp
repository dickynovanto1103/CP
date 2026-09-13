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

ll a[8002];
ll pref[8002];

ll cost(int left, int s, int right) {
	ll costLeft = pref[s] - pref[left];
	ll costRight = pref[right] - pref[s];

	return min(costLeft * 2LL + costRight, costLeft + 2LL * costRight);
}

void solve(){
	int n,s;
	ll length;
	while(scanf("%d %d %lld",&n,&s,&length) != EOF) {
		s--;
		pref[0] = 0;
		for(int i=1;i<n;i++){
			scanf("%lld",&a[i]);
			pref[i] = pref[i - 1] + a[i];
			// printf("pref[%d]: %lld\n", i, pref[i]);
		}

		int r = s;
		int ans = 1;
		for(int l=0;l<=s;l++) {
			while((r + 1) < n && cost(l, s, r + 1) <= length) {
				// printf("l: %d r: %d, cost: %lld\n", l, r, cost(l,s,r));
				r++;
			}
			if(cost(l, s, r) <= length) {
				ans = max(ans, r - l + 1);	
			}
			
			
		}

		printf("%d\n", ans);
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