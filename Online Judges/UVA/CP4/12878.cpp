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
	int n,m;
	while(scanf("%d%d",&n,&m) != EOF) {
		vector<vii> adj;
		adj.assign(n+1, vii());
		for(int i=0;i<m;i++){
			int a,b,w;
			scanf("%d%d%d\n", &a,&b,&w);
			adj[a].pb(ii(b, w));
			adj[b].pb(ii(a, w));
		}

		int dist[n+1];
		memset(dist, -1, sizeof dist);
		dist[0] = 0;
		priority_queue<ii, vii, greater<ii>> pq;
		pq.push(ii(dist[0], 0));
		while(!pq.empty()) {
			ii top = pq.top(); pq.pop();
			int curDist = top.first, node = top.second;
			if(curDist > dist[node]) {continue;}

			for(ii v: adj[node]) {
				int ne = v.first, w = v.second;
				if(dist[ne] == -1 || dist[ne] > curDist + w) {
					dist[ne] = curDist + w;
					pq.push(ii(dist[ne], ne));
				}
			}
		}

		// for(int i=0;i<n;i++){
		// 	printf("dist[%d]: %d\n", i, dist[i]);
		// }

		//backtrack
		int sumPath = 0;
		queue<int> q;
		q.push(n-1);
		bool isVisited[n+1] = {};

		while(!q.empty()) {
			int front = q.front(); q.pop();
			if(isVisited[front]) {
				continue;
			}

			isVisited[front] = true;
			for(ii v: adj[front]) {
				int ne = v.first, w = v.second;
				if(dist[ne] == (dist[front] - w)) {
					sumPath += w * 2;
					// printf("pushing neighbor: %d from front: %d\n", ne, front);
					q.push(ne);
				}
			}
		}

		printf("%d\n", sumPath);
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