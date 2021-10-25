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

const int maxn = 1e5 + 5;

int a[maxn];
vector<vi> adj;
int sor[maxn];
int parent[maxn];

int dfs(int node, int goal, int par = -1) {
	sor[node] = a[node];
	parent[node] = par;
	for(int i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		if(v != par) {
			int ans = dfs(v, goal, node);
			if(ans != -1) {return ans;}
			sor[node] ^= sor[v];
		}
	}

	return sor[node] == goal ? node: -1;
}

void assignNewNeighbor(int a, int b) {
	vi tmp;
	for(auto it: adj[a]) if(it != b) tmp.pb(it);
	adj[a] = tmp;
}

void removeEdge(int a, int b) {
	assignNewNeighbor(a, b);
	assignNewNeighbor(b, a);
}

int main(){
	int tc,i,j,n, k;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&k);
		int goal = 0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			goal ^= a[i];
		}
		adj.assign(n+1, vi());
		for(i=0;i<n-1;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			adj[x].pb(y); adj[y].pb(x);
		}
		
		if(goal == 0){puts("YES"); continue;}
		if(k == 2){puts("NO"); continue;} //must at least cut 2 edges

		int sub = dfs(1, goal);

		if(sub <= 1){
			puts("NO"); continue; //if subtree not found (-1) or the subtree is at root (node 1)
		}
		//remove the edge
		assert(parent[sub] != -1);
		removeEdge(sub, parent[sub]);
		sub = dfs(1, goal);
		
		if(sub <= 1){puts("NO"); continue;}
		puts("YES");
	}
	
	return 0;
};