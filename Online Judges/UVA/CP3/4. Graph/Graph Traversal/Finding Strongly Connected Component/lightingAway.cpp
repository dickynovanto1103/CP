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

const int maxn = 1e4 + 4;

vector<vi> AdjList;

int dfs_low[maxn], dfs_num[maxn], counter;
bool isVisited[maxn];
int cnt = 0;
int id[maxn];
vi listNode;

void dfs(int u) {
	dfs_num[u] = dfs_low[u] = counter++;
	isVisited[u] = true;
	listNode.pb(u);
	// printf("dipush: %d\n",u);
	for(int i=0;i<AdjList[u].size();i++) {
		int v = AdjList[u][i];
		if(dfs_num[v] == -1){
			dfs(v);
		}
		if(isVisited[v]) {
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
	}

	if(dfs_low[u] == dfs_num[u]) {
		// printf("SCC %d:",cnt);
		while(1){
			int node = listNode.back(); listNode.pop_back();
			isVisited[node] = false;
			id[node] = cnt;
			// printf(" %d",node);
			if(node == u){break;}
		}
		// printf("\n");
		cnt++;
	}
}

int main(){
	int tc,i,j,n,m;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		cnt = 0;
		printf("Case %d: ",tt);
		memset(dfs_num, -1, sizeof dfs_num);
		AdjList.assign(maxn, vi());
		memset(isVisited, false, sizeof isVisited);
		scanf("%d %d",&n,&m);
		int awal[100010], akhir[100010];
		for(i=0;i<m;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			awal[i] = a; akhir[i] = b;
			AdjList[a].pb(b);
		}
		for(i=1;i<=n;i++){
			if(dfs_num[i] == -1){
				dfs(i);
			}
		}
		int indegree[maxn];
		memset(indegree, 0, sizeof indegree);
		for(i=0;i<m;i++){
			if(id[awal[i]] != id[akhir[i]]){
				indegree[id[akhir[i]]]++;
			}
		}
		int ans = 0;
		for(i=0;i<cnt;i++){
			if(!indegree[i]){ans++;}
		}
		printf("%d\n",ans);
		AdjList.clear();
		listNode.clear();
	}
	return 0;
};