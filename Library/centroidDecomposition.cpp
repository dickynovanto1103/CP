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

vector<vi> AdjList, centrodTree;
const int maxn = 1e5 + 5;
int sz[maxn];

void dfs(int node, int p) {
	sz[node] = 1;
	for(int i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		if(v!=p){
			dfs(v, node);
			sz[node] += sz[v];
		}
	}
}

bool isVisited[maxn];

int getCentroid(int n, int p) {

	int maks = sz[n]/2;
	// printf("n: %d p: %d maks: %d\n",n,p,maks);
	int node = n;
	for(int i=0;i<AdjList[n].size();i++){
		int v = AdjList[n][i];
		if(!isVisited[v] && v!=p) {
			// printf("sz[%d]: %d\n",v,sz[v]);
			if(sz[v] > maks){
				int selisih = sz[n] - sz[v];
				int tmp = sz[n];
				sz[n] = selisih;
				sz[v] = tmp;
				// printf("sz[%d] jadi: %d sz[%d] jadi: %d\n",n,sz[n], v,sz[v]);
				node = getCentroid(v, n);
				break;
			}
		}
	}
	isVisited[node] = true;

	return node;
}

void constructCentroidTree(int dasar) {
	int root = getCentroid(dasar, -1);
	// printf("root: %d\n",root);
	for(int i=0;i<AdjList[root].size();i++){
		int v = AdjList[root][i];
		if(!isVisited[v]){
			int centroidLain = getCentroid(v, root);
			centrodTree[root].pb(centroidLain); centrodTree[centroidLain].pb(root);
			// printf("dipush %d %d\n",root, centroidLain);
			constructCentroidTree(centroidLain);	
		}
		
	}
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	AdjList.assign(maxn, vi());
	centrodTree.assign(maxn, vi());
	for(i=0;i<n-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		AdjList[a].pb(b); AdjList[b].pb(a);
	}

	dfs(1,-1);

	memset(isVisited, false, sizeof isVisited);
	constructCentroidTree(1);
	for(i=1;i<=n;i++){
		for(j=0;j<centrodTree[i].size();j++){
			printf(" %d",centrodTree[i][j]);
		}
		printf("\n");
	}
	return 0;
};