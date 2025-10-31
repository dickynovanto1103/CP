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
	int r,c;
	while(scanf("%d %d",&r,&c) == 2)  {
		int pts[r+1] = {0};
		for(int j=0;j<c;j++){
			for(int i=1;i<=r;i++){
				int point;
				scanf("%d",&point);
				pts[i] += point;
			}
		}
		

		int winner = 1;
		int maks = -inf;
		for(int i=1;i<=r;i++){
			if(pts[i] >= maks) {
				maks = pts[i];
				winner = i;
			}
		}

		printf("%d\n", winner);
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