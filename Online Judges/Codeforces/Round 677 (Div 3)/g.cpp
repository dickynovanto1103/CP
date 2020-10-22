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
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vii> adj;
int dist[1001][1001];
int qa[1001], qb[1001];

void dijkstra(int node) {
	dist[node][node] = 0;
	priority_queue<ii, vii, greater<ii> > pq;
	pq.push(ii(dist[node][node], node));
	while(!pq.empty()){
		ii cur = pq.top(); pq.pop();
		int curNode = cur.second, curJarak = cur.first;
		if(dist[node][curNode] < curJarak) {continue;}
		for(int i=0;i<adj[curNode].size();i++){
			ii pas = adj[curNode][i];
			int v = pas.first, w = pas.second;
			if(dist[node][v] > dist[node][curNode] + w) {
				dist[node][v] = dist[node][curNode] + w;
				pq.push(ii(dist[node][v], v));
			}
		}
	}
}

int main(){
	int n,m,k,i,j;
	while(scanf("%d %d %d",&n,&m,&k) != EOF) {
		adj.assign(n+1, vii());
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				dist[i][j] = inf;
			}
		}
		ii edge[m + 1];
		for(i=0;i<m;i++){
			int a,b,w;
			scanf("%d %d %d",&a,&b,&w);
			adj[a].pb(ii(b, w));
			adj[b].pb(ii(a, w));
			edge[i].first = a; edge[i].second = b;
		}
		for(i=1;i<=n;i++){
			dijkstra(i);
		}
		ll tot = (ll)inf*(ll)inf;

		for(i=0;i<k;i++) {
			scanf("%d %d",&qa[i], &qb[i]);
		}

		for(j=0;j<m;j++){
			int u = edge[j].first, v = edge[j].second;
			ll totCase = 0;
			for(i=0;i<k;i++){
				int a = qa[i], b = qb[i];
				int ans = dist[a][b];
				int jarak1 = dist[a][u] + dist[v][b];
				int jarak2 = dist[b][u] + dist[v][a];
				ans = min(ans, min(jarak1, jarak2));
				totCase += ans;
			}
			tot = min(tot, totCase);
		}
		// for(i=0;i<k;i++){
		// 	int a,b;
		// 	scanf("%d %d",&a,&b);
		// 	int ans = dist[a][b];
		// 	printf("a: %d b: %d ans awal: %d\n",a, b, ans);
		// 	//try to remove each edge
		// 	for(j=0;j<m;j++){
		// 		int u = edge[j].first, v = edge[j].second;
		// 		int jarak1 = dist[a][u] + dist[v][b];
		// 		int jarak2 = dist[b][u] + dist[v][a];
		// 		ans = min(ans, min(jarak1, jarak2));
		// 	}
		// 	printf("final ans: %d\n",ans);
		// 	tot += ans;
		// }
		printf("%lld\n",tot);
	}
	
	
	return 0;
};