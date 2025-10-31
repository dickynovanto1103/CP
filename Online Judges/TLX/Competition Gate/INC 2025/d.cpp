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
typedef pair<ll, ll> pll;
typedef pair<pll,int> pli;
typedef vector<pli> vpli;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vector<ii>> adj;

pll dist[4][100010];

void dijkstra(int from) {
	priority_queue<pli, vpli, greater<pli>> pq;
	dist[from][from] = pll(0, 0);
	pq.push(pli(dist[from][from], from));
	while(!pq.empty()) {
		pli temp = pq.top(); pq.pop();

		pll curDist = temp.first;
		int node = temp.second;
		// printf("curDist: %lld %lld, node: %d\n", curDist.first, curDist.second, node);

		if(curDist > dist[from][node]) {
			// printf("continue");
			continue;
		}

		for(int i=0;i<adj[node].size();i++){
			ii t = adj[node][i];
			int v = t.first, w = t.second;
			// printf("node: %d v: %d w: %d\n", node, v, w);
			pll newJarak = pll(curDist.first + w, curDist.second + (w + 1) / 2);
			if(dist[from][v] > newJarak) {
				dist[from][v] = newJarak;
				pq.push(pli(dist[from][v], v));
			}
		}
	}
}

void solve(){
	int n,m;
	while(scanf("%d %d",&n,&m) == 2) {
		adj.assign(n+1, vii());
		for(int i=1;i<=n;i++){
			dist[1][i] = pll((ll)inf*inf,(ll)inf*inf);
			dist[2][i] = pll((ll)inf*inf, (ll)inf*inf);
			dist[3][i] = pll((ll)inf*inf, (ll)inf*inf);
		}
		for(int i=0;i<m;i++){
			int a, b, w;
			scanf("%d %d %d",&a,&b,&w);
			adj[a].pb(ii(b, w));
			adj[b].pb(ii(a, w));
		}

		dijkstra(1);
		// for(int i=1;i<=n;i++){
		// 	printf("dist[1][%d]: ii(%lld,%lld)\n", i, dist[1][i].first, dist[1][i].second);
		// }
		dijkstra(2);
		dijkstra(3);

		ll minim = (ll)inf*inf;
		for(int i=1;i<=n;i++){
			ll jarak1 = dist[1][i].first;
			ll jarak2 = dist[2][i].first + dist[2][i].second;
			ll jarak3 = dist[3][i].first;
			if(minim > jarak1 + jarak2 + jarak3) {
				minim = jarak1 + jarak2 + jarak3;
			}
		}

		printf("%lld\n", minim);
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