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
	int n;
	while(scanf("%d",&n) != EOF) {
		int a[n+1];
		int pref[n+1];
		int suff[n+1];
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			pref[i] = a[i];
			if(i > 0) {
				pref[i] += pref[i-1];
			}
		}

		for(int i=n-1;i>=0;i--){
			suff[i] = a[i];
			if(i < n-1){
				suff[i] += suff[i+1];
			}
		}

		int minDiff = inf;
		for(int i=0;i<n-1;i++){
			minDiff = min(minDiff, abs(pref[i] - suff[i+1]));
		}

		printf("%d\n", minDiff);
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