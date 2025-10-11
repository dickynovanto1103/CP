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
	int hNow, mNow, h, m;
	while(scanf("%d%d%d%d",&hNow,&mNow,&h,&m), (hNow || mNow || h || m)) {
		int minuteNow = hNow * 60 + mNow;
		int minuteLater = h * 60 + m;
		if(minuteLater < minuteNow) {
			minuteLater += 24 * 60;
		}

		printf("%d\n",minuteLater - minuteNow);
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