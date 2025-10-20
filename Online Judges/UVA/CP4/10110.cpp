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

// ll findFloorSqrt(ll n) {
// 	ll kiri = 1, kanan = n;
// 	int ans;
// 	while(kiri <= kanan) {
// 		ll mid = (kiri + kanan) / 2;
// 		if(mid * mid == n) {
// 			return mid;
// 		}

// 		if(mid * mid < n) {
// 			ans = mid;
// 			kiri = mid + 1;
			
// 		}else{
// 			kanan = mid - 1;
// 		}
// 	}

// 	return ans;
// }

void solve(){
	ll n;
	while(scanf("%lld",&n), n) {
		int numFactor = 0;

		ll sq = sqrt(n);
		if(sq * sq == n) {
			puts("yes");
		}else{
			puts("no");
		}

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