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
typedef vector<ll> vll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<ii> vii;
typedef vector<pll> vpll;

const int maxn = 1e5 + 5;

ll val[maxn];
ll dp[maxn];
ll maxVal[maxn];
vector<vi> adj;

void solve(int node) {
	if(adj[node].size() == 0) {
		dp[node] = val[node];
		maxVal[node] = val[node];
		return;
	}

	for(int i=0;i<adj[node].size();i++) {
		int v = adj[node][i];
		solve(v);
	}

	vpll listPas;
	for(int i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		listPas.pb(ii(maxVal[v], dp[v]));
	}

	sort(listPas.begin(), listPas.end());
	ll maks = val[node];

	for(pll pas: listPas) {
		maks = max(maks, pas.first);
	}

	maxVal[node] = maks;
	if(node == 0) {//kasus khusus karena node 0 bisa didatengin beberapa kali
		for(int i=0;i<adj[node].size();i++){
			int v = adj[node][i];
			dp[node] += dp[v];
		}
		return;
	}

	assert(listPas.size() > 0);
	dp[node] = max(val[node], listPas[0].first);
	for(int i=1;i<listPas.size();i++){
		dp[node] += listPas[i].second;
	}
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ", tt);
		int n;
		scanf("%d",&n);
		adj.assign(n+2, vi());
		for(i=0;i<=n;i++){
			dp[i] = 0;
			maxVal[i] = 0;
		}

		for(i=1;i<=n;i++){
			scanf("%lld",&val[i]);
		}

		for(i=1;i<=n;i++){
			int source;
			scanf("%d",&source);
			adj[source].pb(i);
		}

		solve(0);
		// for(i=0;i<=n;i++){
		// 	printf("maxVal[%d]: %lld, dp[%d]: %lld\n", i, maxVal[i], i, dp[i]);
		// }
		printf("%lld\n", dp[0]);
	}
	
	return 0;
};