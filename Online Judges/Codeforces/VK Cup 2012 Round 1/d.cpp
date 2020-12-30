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

int dp[50010][510];
vector<vi> adj;

void solve(int node, int p) {
	dp[node][0] = 1;
	for(int i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		if(v != p){
			solve(v, node);
			for(int j=1;j<=500;j++){
				dp[node][j] += dp[v][j-1];
			}
		}
	}
}

int main(){
	int n,k,i,j;
	while(scanf("%d %d",&n,&k) != EOF){
		printf("\n\n\n");
		memset(dp, 0, sizeof dp);
		adj.assign(n+1, vi());
		for(i=0;i<n-1;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			adj[a].pb(b); adj[b].pb(a);
		}
		solve(1, -1);
		// for(i=1;i<=n;i++){
		// 	for(j=0;j<=4;j++){
		// 		printf("dp[%d][%d]: %d\n",i, j, dp[i][j]);
		// 	}
		// }
		ll ans = 0;
		for(i=1;i<=n;i++){
			ll tot = 0;
			for(j=0;j<=k;j++){
				for(int k=0;k<adj[i].size();i++){
					int v = adj[i][k];
					// ll jawab = dp[v][j]
				}
			}
			tot /= 2;
			ans += tot;
		}
	}
	
	

	
	return 0;
};