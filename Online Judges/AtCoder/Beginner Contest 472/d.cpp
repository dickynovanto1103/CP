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
	int n,m,k;
	while(scanf("%d%d%d",&n,&m,&k) != EOF) {
		vector<string> v(n);
		for(int i=0;i<n;i++){
			cin>>v[i];
		}

		vector<int> rows, cols;
		for(int i=0;i<n;i++){
			bool hasBomb = false;
			for(int j=0;j<m;j++){
				if(v[i][j] == '#'){
					hasBomb = true;
					break;
				}
			}

			if(!hasBomb){
				rows.pb(i);
			}
		}

		for(int j=0;j<m;j++){
			bool hasBomb = false;
			for(int i=0;i<n;i++){
				if(v[i][j] == '#') {
					hasBomb = true;
					break;
				}
			}

			if(!hasBomb) {
				cols.pb(j);
			}
		}

		queue<ii> q;
		int dist[n + 1][m + 1];
		memset(dist, -1, sizeof dist);
		for(int row: rows) {
			for(int col: cols){
				q.push(ii(row, col));
				dist[row][col] = 0;
			}
		}

		int dr[] = {-1,0,1,0};
		int dc[] = {0,1,0,-1};

		int ans = q.size();

		while(!q.empty()) {
			ii pos = q.front(); q.pop();
			for(int i=0;i<4;i++){
				int nextR = pos.first + dr[i];
				int nextC = pos.second + dc[i];
				if(nextR >= 0 && nextR < n && nextC >= 0 && nextC < m && v[nextR][nextC] == '.' && dist[nextR][nextC] == -1) {
					dist[nextR][nextC] = dist[pos.first][pos.second] + 1;
					if(dist[nextR][nextC] <= k) {
						q.push(ii(nextR, nextC));
						ans++;
					}
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