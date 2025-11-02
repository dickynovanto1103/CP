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
	int r, c, n;
	while(scanf("%d %d %d",&r,&c,&n), (r || c || n)) {
		bool peta[r+1][c+1];
		memset(peta, false, sizeof peta);
		while(n--){
			int r1,c1,r2,c2;
			scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
			if(r1 > r2) {
				swap(r1, r2);
			}
			if(c1 > c2) {
				swap(c1, c2);
			}
			for(int i=r1;i<=r2;i++){
				for(int j=c1;j<=c2;j++){
					peta[i][j] = true;
				}
			}
		}

		int remaining = 0;
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				if(!peta[i][j]) remaining++;
			}
		}

		if(remaining == 0) {
			puts("There is no empty spots.");
		}else if(remaining == 1) {
			puts("There is one empty spot.");
		}else{
			printf("There are %d empty spots.\n", remaining);
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