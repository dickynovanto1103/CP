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
typedef pair<ii,int> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

class Solution {
public:
	int dist[101][102];
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    	// printf("src: %d dest: %d\n", src, dst);
  		vector<vii> adj(n, vii());
  		for(int i=0;i<flights.size();i++){
  			int from = flights[i][0];
  			int to = flights[i][1];
  			int w = flights[i][2];
  			adj[from].pb(ii(to, w));
  		}

  		for(int i=0;i<=n;i++){
  			for(int j=0;j<=n+1;j++){
  				dist[i][j] = inf;
  			}
  		}

  		priority_queue<iii, viii, greater<iii>> pq;
  		dist[src][0] = 0;
  		pq.push(iii(ii(0, 0), src));
  		while(!pq.empty()) {
  			iii top = pq.top(); pq.pop();
  			int curDist = top.first.first, numStep = top.first.second, node = top.second;
  			if(curDist > dist[node][numStep]) {continue;}
  			for(int i=0;i<adj[node].size();i++){
  				ii v = adj[node][i];
  				int neighbor = v.first, w = v.second;
  				if(dist[neighbor][numStep + 1] > dist[node][numStep] + w) {
  					dist[neighbor][numStep + 1] = dist[node][numStep] + w;
  					pq.push(iii(ii(dist[neighbor][numStep + 1], numStep + 1), neighbor));
  				}
  			}
  		}

  		int minim = inf;
  		for(int i=0;i<=k+1;i++){
  			minim = min(minim, dist[dst][i]);
  			// printf("dist[%d][%d]: %d\n", dst, i, dist[dst][i]);
  		}

  		if(minim == inf) {
  			return -1;
  		}

  		return minim;
    }
};

void solve(){

}

int main(){
	// int tc = 1;
	// scanf("%d",&tc);
	// while(tc--){
	// 	solve();
	// }

	int n,m, k, src, dest;
	while(scanf("%d %d %d %d %d",&n,&m, &k, &src, &dest) != EOF) {
		vector<vector<int>> edges(m, vi(3, 0));
		for(int i=0;i<m;i++){
			scanf("%d %d %d",&edges[i][0],&edges[i][1],&edges[i][2]);
		}

		Solution s;
		int ans = s.findCheapestPrice(n, edges, src, dest, k);
		printf("%d\n", ans);
	}

	return 0;
};