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

int tt = 1;

void solve(){
	int n,m,c;
	while(scanf("%d %d %d",&n,&m,&c) && (n | m | c)) {
		// printf("n: %d, m: %d, c: %d\n", n,m,c);
		// if(tt == 3) {
		// 	break;
		// }
		printf("Sequence %d\n", tt++);
		int consumption[n+1];
		bool on[n+1] = {false};
		for(int i=1;i<=n;i++){
			scanf("%d",&consumption[i]);
		}
		int tot = 0;
		int maks = 0;
		bool success = true;
		for(int i=0;i<m;i++){
			int device;
			scanf("%d",&device);
			if(on[device]) {
				tot -= consumption[device];
			}else{
				tot += consumption[device];
				if(tot > c) {
					success = false;
				}else{
					maks = max(maks, tot);
				}
			}
			on[device] = !on[device];
		}
		if(success) {
			puts("Fuse was not blown.");
			printf("Maximal power consumption was %d amperes.\n", maks);
		}else{
			puts("Fuse was blown.");
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