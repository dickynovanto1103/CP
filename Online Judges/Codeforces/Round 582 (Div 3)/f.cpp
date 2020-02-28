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

const int maxn = 2e5 + 5;

vi dfs_num, dfs_low, s, visitedNode;
vector<vi> AdjList;
int dfsCounter, numSCC;

char ans[maxn];
int idxJenis[maxn];

vector<vi> idxList;

void tarjan(int u){
	dfs_num[u] = dfs_low[u] = dfsCounter++;
	s.push_back(u);
	visitedNode[u] = visited;
	for(int i=0;i<AdjList[u].size();i++){
		int v = AdjList[u][i];
		if(dfs_num[v]==unvisited) {
			tarjan(v);
		}
		if(visitedNode[v]==visited){
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}	
	}
	if(dfs_num[u] == dfs_low[u]) {
		int jenis = min(numSCC, 25);		

		while(1){
			int node = s.back(); s.pop_back(); visitedNode[node] = unvisited;
			idxList[jenis].pb(node);
			idxJenis[node] = jenis;
			// printf("node: %d ",node-1);
			// ans[node-1] = kar;
			// printf(" %d",node);
			if(node == u){
				break;
			}
		}
		numSCC++;
	}
	
}

int main(){
	int n,k,i,j;
	scanf("%d %d",&n,&k);
	int a[maxn];
	AdjList.assign(n+1, vi());
	dfs_num.assign(n+1,unvisited); dfs_low.assign(n+1,0); visitedNode.assign(n+1,unvisited);
	idxList.assign(26, vi());
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(i){
			AdjList[a[i-1]].pb(a[i]);
		}
	}
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(i){
			AdjList[a[i-1]].pb(a[i]);
		}
	}

	dfsCounter = numSCC = 0;

	for(i=1;i<=n;i++){
		if(dfs_num[i]==unvisited){
			tarjan(i);
		}
	}
	bool vis[maxn];
	memset(vis, false, sizeof vis);
	if(numSCC >= k){
		char kar = 'a';
		for(i=0;i<n;i++){
			if(!vis[a[i]-1]){
				vis[a[i]-1] = true;
				int idx = idxJenis[a[i]];
				for(j=0;j<idxList[idx].size();j++){
					int bil = idxList[idx][j] - 1;
					ans[bil] = kar;
					vis[bil] = true;
				}

				kar++;
				if(kar >'z'){
					kar = 'z';
				}
			}

		}
		printf("YES\n");
		printf("%s\n",ans);	
	}else{
		printf("NO\n");
	}
	

	return 0;
};