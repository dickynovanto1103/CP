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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

vector<vi> nodes, adj;

void dfs(int node, int p, int height) {
	// printf("node: %d parent: %d \n",node,p);
	nodes[height].pb(node);
	for(int i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		if(v != p){
			dfs(v, node, height+1);
		}
	}
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	nodes.assign(maxn, vi());
	adj.assign(maxn, vi());
	int degree[maxn];
	memset(degree, 0, sizeof degree);
	for(i=0;i<n-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a].pb(b); adj[b].pb(a);
		degree[a]++; degree[b]++;
	}
	bool node = 0;
	for(i=1;i<=n;i++){
		if(degree[i] == 1){node = i; break;}
	}
	// printf("node: %d\n",node);
	dfs(node, -1, 0);

	for(i=0;i<maxn;i++){
		int deg = -1;
		for(j=0;j<nodes[i].size();j++){
			int node = nodes[i][j];
			if(deg == -1){deg = degree[node];}
			else{
				if(deg != degree[node]){printf("-1\n");return 0;}
			}
		}
	}
	printf("%d\n",node);

	return 0;
};