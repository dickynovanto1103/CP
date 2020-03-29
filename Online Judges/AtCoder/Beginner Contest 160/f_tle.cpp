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

map<int, int> sz[200001];
const int mod = 1e9 + 7;

ll fac[200001], invFac[200001];

map<int,ll> dp[200001];

ll solve(int node, int parent) {
	int i,j;
	if(dp[node].find(parent) != dp[node].end()){
		return dp[node][parent];
	}
	int ukuran = sz[node][parent];
	ll jawab = fac[ukuran-1];
	// printf("jawab: node %d parent: %d, %lld\n", node, parent, jawab);
	for(i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		if(v == parent){continue;}
		jawab *= invFac[sz[v][node]];	
		// printf("node: %d parent: %d jawab: %lld\n",node, parent, jawab);
		jawab %= mod;
		
	}
	for(i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		if(v == parent){continue;}
		jawab *= solve(v, node);
		jawab %= mod;
		// printf("rekursif node: %d parent: %d jawab: %lld\n",node, parent, jawab);
	}

	// for(i=0;i<adj[node].size();i++){
	// 	int v = adj[node][i];
	// 	dp[v][-1] = solve(v, -1);
	// }
	// printf("dp[%d, %d]: %lld\n",node, parent, jawab);
	return dp[node][parent] = jawab;
}

int subtreeSize(int node, int parent) {
	if(sz[node].find(parent) != sz[node].end()){
		return sz[node][parent];
	}
	sz[node][parent] = 1;
	int ans = 0;
	for(int i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		if(v == parent){continue;}
		ans += subtreeSize(v, node);
	}
	sz[node][parent] += ans;
	// printf("sz[%d, %d]: %d\n",node, parent, sz[ii(node, parent)]);
	return sz[node][parent];
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

	for(i=1;i<=n;i++){
		subtreeSize(i, -1);	
	}

	for(i=1;i<=n;i++){
		solve(i, -1);
	}

	for(i=1;i<=n;i++){
		ll ans = dp[i][-1];

		printf("%lld\n",ans);
	}

	return 0;
};