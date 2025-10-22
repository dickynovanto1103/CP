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

int getDiff(int a, int b) {
	return min(24 - abs(a - b), abs(a - b));
}

void solve(){
	int n;
	while(scanf("%d",&n) == 1){
		int gmts[n+1];
		for(int i=0;i<n;i++){
			scanf("%d",&gmts[i]);
		}

		sort(gmts, gmts + n);
		int sum = 0;
		for(int i=0;i<n-1;i+=2){
			sum += getDiff(gmts[i], gmts[i+1]);
		}

		int sum2 = 0;
		for(int i=1;i<n;i+=2) {
			int nextIdx = i + 1;
			if(nextIdx == n) {
				nextIdx = 0;
			}
			sum2 += getDiff(gmts[i], gmts[nextIdx]);
		}

		printf("%d\n", min(sum, sum2));
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