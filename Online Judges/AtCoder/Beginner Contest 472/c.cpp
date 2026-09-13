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
	int n,m;
	ll k;
	while(scanf("%d%d%lld",&n,&m,&k) != EOF) {
		int a[n+1];
		ll pref[n+1];
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}

		for(int i=0;i<n;i++){
			int prevIdx = max(-1, i - m);
			// printf("i: %d pref[i-1]: %d a[%d]: %d prevIdx: %d\n", i, pref[i-1], i, a[i], prevIdx);

			if((i == 0 ? 0: pref[i-1]) + (ll)a[i] - (prevIdx < 0 ? 0 : pref[prevIdx]) > k) {
				pref[i] = 0;
				puts("No");
			}else{
				pref[i] = a[i];
				puts("Yes");
			}
			if(i > 0) {pref[i] += pref[i-1];}
		}
		puts("");
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