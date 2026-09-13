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
	int n,l;
	while(scanf("%d%d",&n,&l) != EOF) {
		int pos[n];
		for(int i=0;i<n;i++){
			scanf("%d",&pos[i]);
		}

		sort(pos, pos + n);
		double kiri = max((double)pos[0], (double)l - (double)pos[n-1]), kanan = 1e9, mid = kanan, ans = kanan;
		while(kanan - kiri > eps) {
			mid = (kiri + kanan) / 2;
			if(mid < pos[0] || mid < (l - pos[n-1])) {
				kiri = mid;
				// printf("mid: %d, invalid\n", mid);
				continue;
			}

			bool valid = true;
			double prevRightCover = 0;
			for(int i=0;i<n;i++){
				double leftCover = pos[i] - mid, rightCover = pos[i] + mid;
				if(leftCover > prevRightCover) {
					valid = false;
					// printf("invalid here, pos[%d]: %d, mid: %lf, leftCover: %lf, prevRightCover: %lf\n", i, pos[i], mid, leftCover, prevRightCover);
					break;
				}
				prevRightCover = rightCover;
			}

			if(valid){
				// puts("valid");
				ans = mid;
				kanan = mid;
			}else{
				kiri = mid;
			}
		}

		printf("%.13lf\n", ans);
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