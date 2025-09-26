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
	int r, c;
	while(scanf("%d",&r) && r > 0) {
		scanf("%d",&c);
		int depth[c+1];
		for(int i=0;i<c;i++){
			scanf("%d",&depth[i]);
			depth[i] = r - depth[i];
		}

		int res = depth[0];
		for(int i=1;i<c;i++){
			if(depth[i] > depth[i-1]) {
				int selisih = depth[i] - depth[i-1];
				res += selisih;
			}
		}

		printf("%d\n", res);
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