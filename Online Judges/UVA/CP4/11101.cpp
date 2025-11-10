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

int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

// vector<vi> dist;

void solve(){
	int n,m;
	while(scanf("%d",&n), n) {
		int minimR = inf, maksR = -1, minimC = inf, maksC = -1;
		vii nodes;
		queue<ii> q;
		for(int i=0;i<n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			minimR = min(minimR, a);
			maksR = max(maksR, a);
			minimC = min(minimC, b);
			maksC = max(maksC, b);
			
			nodes.pb(ii(a,b));
			q.push(ii(a,b));
		}

		int m;
		scanf("%d",&m);

		vector<ii> dest;

		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			dest.pb(ii(a,b));
			minimR = min(minimR, a);
			maksR = max(maksR, a);
			minimC = min(minimC, b);
			maksC = max(maksC, b);
		}

		int dist[maksR + 1][maksC + 1];
		memset(dist, -1, sizeof dist);
		// puts("hi");
		// dist.assign(maksR + 1, vi(maksC + 1, -1));
		// puts("hi2");
		for(ii node: nodes) {
			dist[node.first][node.second] = 0;
		}

		// printf("minimR: %d maksR: %d minimC: %d maksC: %d\n", minimR, maksR, minimC, maksC);

		while(!q.empty()) {
			ii front = q.front(); q.pop();
			for(int i=0;i<4;i++){
				int nr = front.first + dr[i], nc = front.second + dc[i];
				if(nr >= minimR && nr <= maksR && nc >= minimC && nc <= maksC) {
					if(dist[nr][nc] == -1) {
						dist[nr][nc] = dist[front.first][front.second] + 1;
						q.push(ii(nr, nc));
					}	
				}
				
			}
		}	

		int minim = inf;
		for(ii d: dest) {
			// printf("dest: %d %d, dist: %d\n", d.first, d.second, dist[d.first][d.second]);
			minim = min(minim, dist[d.first][d.second]);
		}

		printf("%d\n", minim);
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