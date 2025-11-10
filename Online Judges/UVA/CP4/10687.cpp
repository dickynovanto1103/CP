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
typedef pair<double,ii> dii;
typedef vector<ii> vii;

double getDist(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool isVisited[1010];
vector<vi> adj;

void dfs(int node) {
	isVisited[node] = true;
	for(int i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		if(!isVisited[v]) {
			dfs(v);
		}
	}
}

void solve(){
	int n;
	while(scanf("%d",&n), n) {
		vii coordinates(n);
		for(int i=0;i<n;i++){
			isVisited[i] = false;
		}
		
		adj.assign(n + 1, vi());
		for(int i=0;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			coordinates[i].first = x, coordinates[i].second = y;
		}

		for(int i=0;i<n;i++){
			int x1 = coordinates[i].first, y1 = coordinates[i].second;

			vector<tuple<double, int, int, int>> edges;
			for(int j=0;j<n;j++){
				if(i == j){continue;}
				int x2 = coordinates[j].first, y2 = coordinates[j].second;
				double dist = getDist(x1, y1, x2, y2);
				edges.emplace_back(dist, x2, y2, j);
			}

			sort(edges.begin(), edges.end());
			for(int j=0;j<min(2, (int)edges.size());j++) {
				int v = get<3>(edges[j]);
				// printf("connecting %d with %d\n", i,v);
				adj[i].pb(v);
			}
		}

		dfs(0);
		bool valid = true;
		for(int i=0;i<n;i++){
			if(!isVisited[i]) {
				valid = false;
				break;
			}
		}

		if(!valid){
			puts("There are stations that are unreachable.");
		}else{
			puts("All stations are reachable.");
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