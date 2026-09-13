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

vector<vi> adj;
int sz[200002];

int dfs(int node) {
	sz[node] = 1;
	for(int i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		if(sz[v] == 0) {
			sz[node] += dfs(v);	
		}
	}

	return sz[node];
}

int number;
ll ans;

void process(int node, int par, int k) {
	for(int i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		if(v == par) {
			continue;
		}

		//swap 
		int state = sz[v] >= k ? 1: 0;
		swap(sz[node], sz[v]);
		sz[node] = sz[v] - sz[node];
		int state2 = sz[node] >= k ? 1 : 0;
		int add = 0;
		if(state == 1 && state2 == 0) {
			number--;
			add = -1;
		}else if(state == 0 && state2 == 1) {
			number++;
			add = 1;
		}

		ans += number;
		// printf("processing node: %d, v: %d parent: %d, added by number: %d, ans now: %lld\n", node, v, par, number,ans);
		// printf("after swap sz[%d]: %d, sz[%d]: %d\n", node, sz[node], v, sz[v]);
		process(v, node, k);
		//swap again
		swap(sz[node], sz[v]);
		sz[v] = sz[node] - sz[v];
		number += -add;
	}
}

void solve(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<=n;i++){
		sz[i] = 0;
	}
	number = 0;
	ans = 0;
	adj.assign(n+1, vi());
	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].pb(b);
		adj[b].pb(a);
	}

	dfs(1);
	for(int i=1;i<=n;i++){
		if(sz[i] >= k) {
			number++;
		}
	}
	ans += number;
	// printf("number: %d\n", number);

	process(1, -1, k);
	printf("%lld\n", ans);
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};