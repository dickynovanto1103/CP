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
int h[maxn];

void dfs(int node, int par, int height) {
	sor[node] = a[node];
	h[node] = height;
	for(int i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		if(v != par) {
			dfs(v, node, height+1);
			sor[node] ^= sor[v];
		}
	}
}

ii edgeToRemove;
int maxHeight = 0;

void search(int node, int par, int target) {
	for(int i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		if(v != par){
			if(sor[v] == target && maxHeight < h[v]) {
				edgeToRemove = ii(node, v);
				maxHeight = h[v];
			}
			search(v, node, target);
		}
	}
}

void assignNewNeighbor(int a, int b) {
	vi newNeigh;
	for(int i=0;i<adj[a].size();i++){
		int v = adj[a][i];
		if(v == b){
			continue;
		}
		newNeigh.pb(v);
	}
	assert(newNeigh.size() == adj[a].size() - 1);
	adj[a] = newNeigh;
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
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		adj.assign(n+1, vi());
		for(i=0;i<n-1;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			adj[x].pb(y); adj[y].pb(x);
		}

		dfs(1, -1, 0);

		if(sor[1] == 0){printf("YES\n"); continue;}
		if(k == 2){puts("NO"); continue;} //must at least cut 2 edges
		int target = sor[1];

		//find 
		edgeToRemove = ii(-1,-1);
		maxHeight = 0;
		search(1, -1, target);
		if(edgeToRemove == ii(-1,-1)) {puts("NO"); continue;}
		//remove the edge
		removeEdge(edgeToRemove.first, edgeToRemove.second);
		dfs(1, -1, 0);

		edgeToRemove = ii(-1, -1);
		maxHeight = 0;
		search(1, -1, target);
		if(edgeToRemove == ii(-1,-1)){puts("NO"); continue;}
		puts("YES");
	}
	
	return 0;
};