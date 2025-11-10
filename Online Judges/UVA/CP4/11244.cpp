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

bool isVisited[102][102];
vector<string> v;

int dr[] = {0,-1,-1,-1,0,1,1,1};
int dc[] = {-1,-1,0,1,1,1,0,-1};

int floodFill(int curR, int curC, int r, int c) {
	int ans = 1;
	isVisited[curR][curC] = true;
	for(int i=0;i<8;i++){
		int nr = curR + dr[i], nc = curC + dc[i];
		if(nr >= 0 && nr < r && nc >= 0 && nc < c && !isVisited[nr][nc] && v[nr][nc] == '*') {
			ans += floodFill(nr, nc, r, c);
		}
	}

	return ans;
}

void solve(){
	int r,c;
	while(scanf("%d%d",&r,&c), (r || c)) {
		v.clear();
		for(int i=0;i<r;i++){
			string s;
			cin>>s;
			v.pb(s);
		}

		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				isVisited[i][j] = false;
			}
		}

		int ans = 0;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(v[i][j] == '*' && !isVisited[i][j]) {
					bool isStar = (floodFill(i,j,r,c) == 1);
					// printf("i: %d j: %d, isStar: %d\n", i,j,isStar);
					ans += (isStar ? 1 : 0);
				}
			}
		}

		printf("%d\n", ans);
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