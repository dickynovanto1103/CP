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

int dist[100001];

void dfs(int node, int p) {
	for(int i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		if(v != p){
			dist[v] = dist[node] + 1;
			dfs(v, node);
		}
	}
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	adj.assign(n+1, vi());
	for(i=0;i<n-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a].pb(b); adj[b].pb(a);
	}

	bool isLeaf[100001];
	memset(isLeaf, false, sizeof isLeaf);
	int cntLeaf = 0;
	int nodeLeaf = 1;
	for(i=1;i<=n;i++){
		if(adj[i].size() == 1){isLeaf[i] = true; cntLeaf++;}
	}

	int cntNonLeafNeighborLeaf = 0;
	for(i=1;i<=n;i++){
		if(isLeaf[i]){continue;}
		for(j=0;j<adj[i].size();j++){
			int v = adj[i][j];
			if(isLeaf[v]){cntNonLeafNeighborLeaf++; break;}
		}
	}

	dist[nodeLeaf] = 0;
	dfs(nodeLeaf, -1);
	bool isGanjil = false, isGenap = false;
	for(i=1;i<=n;i++){
		if(isLeaf[i]){
			if (dist[i] % 2 == 1) {
				isGanjil = true;	
			}else{
				isGenap = true;
			}
			
		}
	}

	int minimVal = (isGanjil && isGenap ? 3 : 1);

	int maksVal = n-1 - cntLeaf + cntNonLeafNeighborLeaf;
	printf("%d %d\n",minimVal, maksVal);
	
	return 0;
};