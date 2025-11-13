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

int dr[] = {1,1,0,-1,-1,-1,0,1};
int dc[] = {0,1,1,1,0,-1,-1,-1};

void solve(){
	int r1,c1,r2,c2,r3,c3;
	int tt = 1;
	while(scanf("%d%d%d%d%d%d",&r1,&c1,&r2,&c2,&r3,&c3) != EOF) {
		printf("Case %d: ", tt++);
		queue<ii> q;
		int dist[9][9];
		memset(dist, -1, sizeof dist);
		dist[r1][c1] = 0;
		q.push(ii(r1,c1));
		bool found = false;
		while(!q.empty()) {
			ii front = q.front(); q.pop();
			for(int i=0;i<8;i++){
				int nr = front.first + dr[i], nc = front.second + dc[i];
				if(nr >= 1 && nr <= 8 && nc >= 1 && nc <= 8) {
					if(nr == r3 && nc == c3) {
						continue;
					}

					if(dist[nr][nc] == -1) {
						dist[nr][nc] = dist[front.first][front.second] + 1;

						if(nr == r2 && nc == c2) {
							found = true;
							printf("%d\n", dist[nr][nc]);
							break;
						} 
						q.push(ii(nr, nc));
					}
				}
			}

			if(found) {
				break;
			}
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