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

vector<vi> adj;
map<ii, int> mapEdge;
int u[101], v[101], a[101], b[101],c[51], d[51];

ll dp[51][3001];
void solve(int node, int coin) {
	queue<ii> q;
	q.push(ii(node, coin));
	dp[node][coin] = 0;
	while(!q.empty()){
		ii front = q.front(); q.pop();
		node = front.first, coin = front.second;
		// printf("node: %d coin: %d\n",node, coin);
		ll waktu = (ll)inf*(ll)inf;
		for(int i=0;i<adj[node].size();i++){
			int v = adj[node][i];
			int idxEdge = mapEdge[ii(node, v)];
			if(coin >= a[idxEdge]){
				int sisa = coin - a[idxEdge];
				if(dp[v][sisa] > dp[node][coin] + b[idxEdge]) {
					// printf("push v: %d sisaCoin: %d\n",v, coin - a[idxEdge]);
					q.push(ii(v, sisa));
					dp[v][sisa] = dp[node][coin] + b[idxEdge];
					
				}
			}

			ll totCoin = min((ll)coin + c[node], (ll)3000);
			if(dp[node][totCoin] > dp[node][coin] + d[node]) {
				// printf("dorong node: %d totCoin: %lld\n",node, totCoin);
				q.push(ii(node, totCoin));
				dp[node][totCoin] = dp[node][coin] + d[node];		
			}
		}
	}
}

int main(){
	int n,m,s,i,j;
	
	scanf("%d %d %d",&n,&m,&s);
	adj.assign(n+1, vi());
	for(i=0;i<m;i++){
		scanf("%d %d %d %d",&u[i],&v[i],&a[i],&b[i]);
		adj[u[i]].pb(v[i]);
		adj[v[i]].pb(u[i]);
		mapEdge[ii(u[i], v[i])] = i;
		mapEdge[ii(v[i], u[i])] = i;
	}
	for(i=1;i<=n;i++){
		scanf("%d %d",&c[i],&d[i]);
	}
	int maksVal = 3000;
	s = min(s, maksVal);
	for(i=1;i<=n;i++){
		for(j=0;j<=3000;j++){
			dp[i][j] = (ll)inf*(ll)inf;
		}
	}

	dp[1][s] = 0;
	solve(1, s);
	

	for(i=2;i<=n;i++){
		ll ans = (ll)inf*(ll)inf;	
		for(j=0;j<=3000;j++){
			// if(j <= 10){printf("dp[%d][%d]: %lld\n",i,j,dp[i][j]);}
			ans = min(ans, dp[i][j]);
		}
		printf("%lld\n",ans);
	}
	
	return 0;
};