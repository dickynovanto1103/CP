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
int color[200001];
int parent[200001];
bool foundOddCycle;
vector<int> oddCycle;

void dfs(int node) {
	// printf("node: %d, color: %d\n", node, color[node]);
	if(foundOddCycle) {
		return;
	}
	for(int i=0;i<adj[node].size();i++){
		int v = adj[node][i];

		if(color[v] == -1) {
			color[v] = 1 - color[node];
			// printf("node: %d neighbor: %d has no color assigning color: %d\n", node, v, color[v]);
			parent[v] = node;
			// printf("parent[%d]: %d\n", v, parent[v]);
			dfs(v);
		}else if(color[v] == color[node]) {
			// printf("node: %d neighbor: %d has same color\n", node, v);
			if(foundOddCycle){return;}
			//not bipartite, cycle detected
			int curNode = node;
			foundOddCycle = true;
			while(curNode != v) {
				oddCycle.pb(curNode);
				// printf("v: %d curNode: %d, parent: %d\n", v, curNode, parent[curNode]);
				curNode = parent[curNode];
			}
			oddCycle.pb(v);
			
			return;
		}
	}
}

void check(int n) {
	for(int i=0;i<=n;i++){
		color[i] = -1;
		parent[i] = -1;
	}
	
	color[1] = 0;

	dfs(1);
	if(foundOddCycle){
		printf("%d\n", oddCycle.size());
		for(int node: oddCycle){
			printf("%d ", node);
		}
		puts("");
	}else{
		puts("-1");
	}
}

void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	adj.assign(n + 1, vi());

	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].pb(b);
		adj[b].pb(a);
	}

	foundOddCycle = false;
	oddCycle.clear();
	check(n);
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};