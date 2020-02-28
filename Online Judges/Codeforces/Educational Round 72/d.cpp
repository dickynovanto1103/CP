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

int col[5050];
int stat[5050];
vector<vi> adj;
map<ii, int> mapper;

void dfs(int node) {
	int i,j;
	stat[node] = 1;
	for(i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		if(stat[v] == 0){
			int idxEdge = mapper[ii(node, v)];
			col[idxEdge] = 1;
			dfs(v);
		}else if(stat[v] == 1) {//back edge
			int idxEdge = mapper[ii(node, v)];
			col[idxEdge] = 2;
		}
	}
	stat[node] = 2;
}

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	adj.assign(n+1, vi());
	memset(col, -1, sizeof col);
	memset(stat, 0, sizeof stat);
	for(i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		mapper[ii(a,b)] = i;
		
		adj[a].push_back(b);
	}

	for(i=1;i<=n;i++){
		if(stat[i] == 0){
			dfs(i);
		}
	}
	int maks = 1;
	for(i=0;i<m;i++){
		if(col[i] == -1){
			col[i] = 1;
		}
		maks = max(maks, col[i]);
	}
	printf("%d\n",maks);
	for(i=0;i<m;i++){
		if(i){
			printf(" ");
		}
		printf("%d", col[i]);
	}
	printf("\n");
	return 0;
};