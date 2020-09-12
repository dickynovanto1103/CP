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
const int maxn = 1e5 + 5;
int sz[maxn];

void dfs(int node, int par) {
	sz[node] = 1;
	for(int i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		if(v != par) {
			dfs(v, node);
			sz[node] += sz[v];
		}
	}
}

vi centroids;
int n;
bool vis[maxn];
bool found;
bool isCentroid[maxn];

void getCentroid(int node, int p) {
	if(found){return;}
	// printf("node: %d p: %d\n",node, p);
	int maks = sz[node]/2;
	int maksValid = 0;
	bool breaked = false;
	for(int i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		if(v != p && sz[v] > maks) {
			int temp = sz[node];
			int selisih = sz[node] - sz[v];
			sz[node] = selisih;
			sz[v] = temp;
			getCentroid(v, node);
			breaked = true;
			break;
		} else if (sz[v] == maks && (sz[node] % 2 == 0)) {
			centroids.pb(node);
			centroids.pb(v);
			isCentroid[node] = true;
			isCentroid[v] = true;
			found = true;
			// printf("push %d\n",v);
			return;
		}
	}
	if(!breaked){
		centroids.pb(node);
		isCentroid[node] = true;
		found = true;
	}
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		found =false;
		adj.clear();
		adj.assign(n+1, vi());
		for(i=1;i<=n;i++){
			isCentroid[i] = false;
			vis[i] = false;
			sz[i] = 0;
		}
		centroids.clear();
		ii edge;
		for(i=0;i<n-1;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			adj[a].pb(b);
			adj[b].pb(a);
			edge = ii(a,b);
		}
		dfs(1, -1);
		// for(i=1;i<=n;i++){
		// 	printf("sz[%d]: %d\n",i, sz[i]);
		// }
		getCentroid(1, -1);
		assert(centroids.size() >= 1);
		if(centroids.size() == 1){
			printf("%d %d\n%d %d\n",edge.first, edge.second, edge.first, edge.second);
		}else{
			int node = centroids[0];
			int second = centroids[1];
			// printf("node: %d second: %d\n",node, second);
			bool breaked = false;
			for(i=0;i<adj[node].size();i++){
				int v = adj[node][i];
				if(!isCentroid[v]){
					printf("%d %d\n%d %d\n",node, v, v, second);
					breaked = true;
					break;
				}
			}
			assert(breaked == true);
		}
	}
	
	return 0;
};