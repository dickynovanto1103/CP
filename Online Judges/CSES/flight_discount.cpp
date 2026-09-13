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
typedef pair<ll,ii> lii;
typedef vector<ii> vii;

void solve(){
	int n,m;
	while(scanf("%d%d",&n,&m) != EOF) {
		vector<vii> adj;
		adj.assign(n+1, vii());
		for(int i=0;i<m;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			adj[a].pb(ii(b, c));
			// adj[b].pb(ii(a, c));
		}

		ll dist[n+1][2];
		for(int i=1;i<=n;i++){
			dist[i][0] = (ll)inf*inf;
			dist[i][1] = (ll)inf*inf;
		}

		priority_queue<lii, vector<lii>, greater<lii>> pq;
		pq.push({0, {1, 0}});
		dist[1][0] = 0;
		while(!pq.empty()) {
			lii top = pq.top(); pq.pop();
			ll curJarak = top.first;

			int node = top.second.first;
			int useCoupon = top.second.second;
			if(curJarak > dist[node][useCoupon]) {continue;}
			// printf("node: %d, useCoupon: %d\n", node, useCoupon);

			for(int i=0;i<adj[node].size();i++){
				ii v = adj[node][i];
				int nei = v.first;
				ll w = v.second;
				// printf("node: %d nei: %d w: %d pq size: %d\n", node, nei, w, pq.size());
				if(dist[nei][useCoupon] > w + dist[node][useCoupon]) {
					dist[nei][useCoupon] = w + dist[node][useCoupon];
					// printf("NO COUPON, dist[%d][%d]: %lld\n", nei, useCoupon, dist[nei][useCoupon]);
					pq.push({dist[nei][useCoupon], {nei, useCoupon}});
				}

				if(!useCoupon) {
					if(dist[nei][1] > w / 2LL + dist[node][0]) {
						dist[nei][1] = w / 2LL + dist[node][0];
						// printf("COUPON, dist[%d][%d]: %lld\n", nei, 1, dist[nei][1]);
						pq.push({dist[nei][1], {nei, 1}});
					}
				}
			}
		}

		printf("%lld\n", (dist[n][1] < (ll)inf*inf ? dist[n][1] : -1));
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