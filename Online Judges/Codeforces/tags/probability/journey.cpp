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

const int maxn = 1e5 + 5;

double prob[maxn];
int jarak[maxn];
vi leafNodes;

void dfs(int node, int par) {
	if(adj[node].size() == 1) leafNodes.pb(node);

	int cntV = 0;
	for(int i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		if(v == par) continue;

		cntV++;
	}

	for(int i=0;i<adj[node].size();i++) {
		int v = adj[node][i];
		if(v == par) continue;

		prob[v] = prob[node] * (1.0/cntV);
		jarak[v] = jarak[node] + 1;
		dfs(v, node);	
	}
}

int main(){
	int n;
	while(scanf("%d",&n) != EOF) {
		leafNodes.clear();
		adj.assign(n+1, vi());
		for(int i=0;i<n-1;i++){
			int a, b;
			scanf("%d %d",&a,&b);
			adj[a].pb(b); adj[b].pb(a);
		}

		prob[1] = 1;
		jarak[1] = 0;
		dfs(1, -1);

		double ans = 0;
		for(int leaf: leafNodes) {
			ans += prob[leaf] * jarak[leaf];
		}

		printf("%.9lf\n", ans);
	}
	
	return 0;
};