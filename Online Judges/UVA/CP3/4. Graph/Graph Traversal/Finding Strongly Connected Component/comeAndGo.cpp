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

const int maxn = 2010;

bool isVisited[maxn];
int dfs_num[maxn], dfs_low[maxn];
vi listNode;
int cnt = 0;
int counter = 0;
vector<vi> AdjList;

void dfs(int u) {
	dfs_num[u] = dfs_low[u] = counter++;
	isVisited[u] = true;
	listNode.pb(u);

	for(int i=0;i<AdjList[u].size();i++){
		int v = AdjList[u][i];
		if(dfs_num[v] == -1){
			dfs(v);
		}
		if(isVisited[v]){
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
	}

	if(dfs_low[u] == dfs_num[u]){
		while(1){
			int node = listNode.back(); listNode.pop_back();
			isVisited[node] = false;	
			if(node == u){break;}
		}
		cnt++;
	}
}

int main(){
	int n,m,i,j;
	while(scanf("%d %d",&n,&m), (n||m)) {
		counter = 0; cnt = 0;
		AdjList.assign(maxn, vi());
		memset(dfs_num, -1, sizeof dfs_num);
		memset(isVisited, false, sizeof isVisited);
		for(i=0;i<m;i++){
			int a,b,p;
			scanf("%d %d %d",&a,&b,&p);
			
			AdjList[a].pb(b);
			if(p == 2){
				AdjList[b].pb(a);
			}	
		}
		for(i=1;i<=n;i++){
			if(dfs_num[i] == -1){
				dfs(i);
			}
		}
		if(cnt == 1){printf("1\n");}
		else{printf("0\n");}

	}
	return 0;
};