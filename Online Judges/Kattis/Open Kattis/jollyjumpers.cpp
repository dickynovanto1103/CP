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

int arr[3010];

void solve(){
	int n;
	while(scanf("%d",&n) != EOF) {

		for(int i=0;i<n;i++){
			scanf("%d",&arr[i]);
		}

		bitset<3001> vis;
		for(int i=1;i<n;i++){
			int diff = abs(arr[i] - arr[i-1]);
			if(diff >= n) {
				continue;
			}
			vis.set(diff, true);
		}

		if(vis.count() < (n-1)) {
			puts("Not jolly");
		}else {
			puts("Jolly");
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