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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

vector<vi> AdjList, CentroidTree, up;
bool isCentroid[maxn];
int sz[maxn];
int dist[maxn];
int parent[maxn], height[maxn];

int tin[maxn], tout[maxn], waktu, batasAtas;

void dfs(int n, int p, int dalam) {
	sz[n] = 1;
	tin[n] = waktu++;
	height[n] = dalam;
	// printf("n: %d\n",n);

	up[n][0] = p;

	for(int i=1;i<=batasAtas;i++){
		// printf("halo\n");
		up[n][i] = up[up[n][i-1]][i-1];
	}

	for(int i=0;i<AdjList[n].size();i++){
		int v = AdjList[n][i];
		// printf("v; %d\n",v);
		if(v!=p) {
			dfs(v, n, dalam+1);
			sz[n] += sz[v];
		}
	}

	tout[n] = waktu++;
}

bool isAncestor(int a, int b){
	return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca(int a, int b) {
	if(isAncestor(a,b)){return a;}
	if(isAncestor(b,a)){return b;}
	for(int i=batasAtas;i>=0;i--){
		if(!isAncestor(up[a][i], b)){
			a = up[a][i];
		}
	}
	return up[a][0];
}

int getCentroid(int n, int p) {
	int node = n;
	int maks = sz[n]/2;
	for(int i=0;i<AdjList[n].size();i++){
		int v = AdjList[n][i];
		if(v != p && sz[v] > maks && !isCentroid[v]) {
			int temp = sz[n];
			int selisih = sz[n] - sz[v];
			sz[n] = selisih;
			sz[v] = temp;
			node = getCentroid(v, n);
			break;
		}
	}

	isCentroid[node] = true;
	return node;
}

int firstRoot = -1;

void constructCentroidTree(int n) {
	int root = getCentroid(n, -1);
	if(firstRoot == -1){firstRoot = root;}
	// printf("root: %d\n",root);
	for(int i=0;i<AdjList[root].size();i++){
		int v = AdjList[root][i];
		if(!isCentroid[v]) {
			int other = getCentroid(v, root);
			CentroidTree[root].pb(other); CentroidTree[other].pb(root);
			parent[other] = root;
			constructCentroidTree(other);	
		}
		
	}
}

int hitungJarak(int a, int b) {
	int nodeLCA =lca(a,b);
	return height[a] - height[nodeLCA] + height[b] - height[nodeLCA];
}

void update(int node) {
	int jarak = 0;
	int nodeAwal = node;
	while(node != -1){
		jarak = hitungJarak(nodeAwal, node);
		dist[node] = min(dist[node], jarak);
		// printf("d[%d]: %d\n",node,dist[node]);
		node = parent[node];
	}
}

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	batasAtas = ceil(log2(n));

	AdjList.assign(maxn, vi());
	CentroidTree.assign(maxn, vi());
	up.assign(maxn, vi(batasAtas+10));
	for(i=0;i<n-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		AdjList[a].pb(b); AdjList[b].pb(a);
	}
	dfs(1,1,0);
	// for(i=1;i<=n;i++){printf("sz[%d]: %d\n",i,sz[i]);}
	memset(isCentroid, false, sizeof isCentroid);
	constructCentroidTree(1);
	// for(i=1;i<=n;i++){
	// 	printf("node %d:",i);
	// 	for(j=0;j<CentroidTree[i].size();j++){
	// 		printf(" %d",CentroidTree[i][j]);
	// 	}
	// 	printf("\n");
	// }
	parent[firstRoot] = -1;
	// printf("firstRoot ;%d\n",firstRoot);
	fill(dist, dist+maxn, inf);
	update(1);
	// for(i=1;i<=n;i++){
	// 	printf("d[%d]: %d\n",i,dist[i]);
	// }
	while(m--){
		int com, node;
		scanf("%d %d",&com,&node);
		if(com == 1){
			//change to red..the update
			update(node);
			// for(i=1;i<=n;i++){
			// 	printf("dist[%d]: %d\n",i,dist[i]);
			// }
		}else{
			//go up
			int jarak = 0;
			int ans = inf;
			int nodeAwal = node;
			while(node != -1){
				jarak = hitungJarak(nodeAwal, node);
				ans = min(ans, dist[node] + jarak);
				node = parent[node];
			}
			printf("%d\n",ans);
		}
	}
	return 0;
};