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

int sz[200001];
const int mod = 1e9 + 7;

ll fac[200001], invFac[200001];

map<int,ll> dp[200001];
ll ans[200001];

ll solve(int node, int parent) {
	int i,j;
	if(dp[node].find(parent) != dp[node].end()) {
		return dp[node][parent];
	}

	ll jawab = fac[sz[node]-1];
	for(i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		if(v == parent){continue;}
		jawab *= invFac[sz[v]];
		jawab %= mod;
	}

	for(i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		if(v == parent){continue;}
		jawab *= solve(v, node);
		jawab %= mod;
	}

	return dp[node][parent] = jawab;
}

ll modPow(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1) {
			res *= a;
			res %= mod;
		}
		a *= a;
		a %= mod;
		b /= 2;
	}
	return res;
}

void reroot(int node, int v) {
	int ukuran = sz[node];
	int szTetangga = sz[v];
	sz[node] = sz[node] - szTetangga;
	sz[v] = ukuran;
}

void dfs(int node, int parent) {
	int i;
	// printf("node: %d parent: %d\n",node, parent);
	if(dp[node].find(-1) == dp[node].end()) {
		// printf("not found node: %d\n",node);
		ll ans = solve(node, -1);
		dp[node][-1] = ans;
	}
	for(i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		if(v == parent){continue;}
		ll ansBaru = dp[node][-1] * modPow(dp[v][node], mod-2); ansBaru %= mod;
		ansBaru *= fac[sz[node] - sz[v] - 1]; ansBaru %= mod;
		ansBaru *= invFac[sz[node] - 1]; ansBaru %= mod;
		ansBaru *= fac[sz[v]]; ansBaru %= mod;

		dp[node][v] = ansBaru; //dp node with the parent = v
		reroot(node, v);
		dfs(v, node);

		reroot(v, node);
	}
}

int subtreeSize(int node, int parent) {
	sz[node] = 1;
	for(int i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		if(v == parent){continue;}
		sz[node] += subtreeSize(v, node);
	}
	return sz[node];
}

void processFac() {
	fac[0] = invFac[0] = 1;
	for(int i=1;i<=200000;i++){
		fac[i] = (ll)i*fac[i-1];
		fac[i] %= mod;
		invFac[i] = modPow(fac[i], mod-2);
	}
}

int main(){
	int n, i,j;	

	processFac();
	scanf("%d",&n);
	adj.assign(n+1, vi());
	for(i=0;i<n-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a].pb(b); adj[b].pb(a);
	}

	subtreeSize(1, -1);
	solve(1, -1);
	dfs(1, -1);
	
	for(i=1;i<=n;i++){
		ll ans = dp[i][-1];
		printf("%lld\n",ans);
	}

	return 0;
};