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

void solve(){
	int n,s;
	ll length;
	while(scanf("%d %d %lld",&n,&s,&length) != EOF) {
		s--;
		ll a[n+1] = {0};
		ll pref[n+1] = {0}, suff[n+1] = {0};
		pref[0] = 0;
		for(int i=1;i<n;i++){
			scanf("%lld",&a[i]);
			pref[i] = a[i];
			pref[i] += pref[i-1];
			// printf("pref[%d]: %lld\n", i, pref[i]);
		}

		suff[n-1] = 0;
		for(int i=n-2;i>=0;i--){
			suff[i] = a[i+1];
			suff[i] += suff[i+1];
			// printf("suff[%d]: %lld\n", i, suff[i]);
		}

		int ans = 1;
		//try go left and back
		for(int i=s-1;i>=0;i--){
			ll distLeft = pref[s] - pref[i];
			// printf("distLeft: %lld\n", distLeft);
			if(distLeft <= length) {
				ans = max(ans, s - i + 1);
				// printf("i: %d, s: %d s - i: %d, ans: %d\n", i, s, s-i, ans);
			}

			if(distLeft * 2LL > length) {
				// puts("break");
				continue;
			}

			ll remainingLength = length - distLeft * 2LL;

			// find the most right that it can go...the right most with pref
			ll expectedPref = pref[s] + remainingLength;
			// printf("distLeft: %lld remainingLength: %lld, expectedPref: %lld\n", distLeft, remainingLength, expectedPref);
			int kiri = s, kanan = n-1, maxCity = -1, mid;
			while(kiri <= kanan) {
				mid = (kiri + kanan) / 2;
				if(pref[mid] <= expectedPref) {
					maxCity = mid;
					kiri = mid + 1;
				}else{
					kanan = mid-1;
				}
			}

			// printf("i: %d maxCity: %d\n", i, maxCity);

			if(maxCity > -1) {
				ans = max(ans, s - i + 1 + (maxCity - s));
				// printf("newAns: %d\n", ans);
			}
		}

		//try go right and back
		for(int i=s+1;i<n;i++){
			ll distRight = pref[i] - pref[s];
			// printf("i: %d s: %d distRight: %lld\n", i, s, distRight);
			if(distRight <= length) {
				ans = max(ans, i - s + 1);
			}

			if(distRight * 2LL > length) {
				continue;
			}

			ll remainingLength = length - distRight * 2LL;
			// find the most left that it can go...
			ll expectedSuff = suff[s] + remainingLength;
			int kiri = 0, kanan = s, maxCity = -1, mid;
			while(kiri <= kanan) {
				mid = (kiri + kanan) / 2;
				if(suff[mid] <= expectedSuff) {
					maxCity = mid;
					kanan = mid - 1;
				}else{
					kiri = mid + 1;
				}
			}

			if(maxCity > -1) {
				ans = max(ans, i - s + 1 + (s - maxCity));
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