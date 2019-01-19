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

int tin[maxn], tout[maxn], waktu, batasAtas, height[maxn];

vector<vi> up, AdjList;

bool isAncestor(int u, int v) {
	return tin[u] <= tin[v] && tout[v] <= tout[u];
}

void dfs(int u, int p, int dalam){
	int i;

	height[u] = dalam;
	tin[u] = waktu++;
	
	up[u][0] = p;
	for(i=1;i<=batasAtas;i++){
		up[u][i] = up[up[u][i-1]][i-1];
	}

	for(i=0;i<AdjList[u].size();i++){
		int v = AdjList[u][i];
		if(v!=p){
			dfs(v, u, dalam+1);
		}
	}

	tout[u] = waktu++;
}

int lca(int a, int b){
	if(isAncestor(a,b)){return a;}
	if(isAncestor(b,a)){return b;}
	for(int i=batasAtas;i>=0;i--){
		if(!isAncestor(up[a][i], b)) {
			a = up[a][i];
		}
	}
	return up[a][0];
}

int sz[maxn];

int dfs1(int node, int p){
	sz[node] = 1;
	for(int i=0;i<AdjList[node].size();i++) {
		int v = AdjList[node][i];
		if(v!=p)
			sz[node] += dfs1(v, node);
	}
	return sz[node];
}

void preprocess() {
	waktu = 1;
	batasAtas = ceil(log2(maxn));
	up.assign(maxn, vi(batasAtas+1));
	dfs(1,1,0);
	dfs1(1,1);
}



int hitungJarak(int a, int b, int c) {
	return height[a] - height[b] + height[c] - height[b];
}

int getParentNode(int keatas, int nodeAwal) {
	int node = nodeAwal;
	for(int i=30;i>=0;i--){
		if(1<<i & keatas) {
			node = up[node][i];
		}
	}
	return node;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	AdjList.assign(maxn, vi());
	for(i=0;i<n-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		AdjList[a].pb(b);
		AdjList[b].pb(a);
	}

	preprocess();


	int q;
	scanf("%d",&q);
	while(q--){
		int a,b;
		scanf("%d %d",&a,&b);
		if(a == b){printf("%d\n",n); continue;}
		int nodeLCA = lca(a,b);
		int jarak = hitungJarak(a, nodeLCA, b);
		if(jarak % 2 == 1){printf("0\n");}
		else{
			if(height[a] == height[b]){
				int tot = 0;
				int keatas = jarak/2;

				int node1 = getParentNode(keatas-1, a);
				int node2 = getParentNode(keatas-1, b);
				printf("%d\n",n-sz[node1]-sz[node2]);
			
			}else{
				int keatas = jarak/2;
				int node;

				if(height[a] > height[b]) {
					node = a;
				}else {
					node = b;
				}
				int node1 = getParentNode(keatas, node);
				int node2 = getParentNode(keatas-1, node);

				int ans = sz[node1] - sz[node2];
				printf("%d\n",ans);

			}
		}

	}
	return 0;
};