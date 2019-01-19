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

const int maxn = 1e3 + 3;

int dfs_num[maxn], dfs_low[maxn];
int cnt, counter;
bool isVisited[maxn];
vector<vi> AdjList;
vi listNode;

void dfs(int u) {
	dfs_low[u] = dfs_num[u] = counter++;
	isVisited[u] = true;
	listNode.pb(u);
	// printf("u: %d\n",u);
	for(int i=0;i<AdjList[u].size();i++){
		int v = AdjList[u][i];
		if(dfs_num[v] == -1){
			dfs(v);
		}
		if(isVisited[v]){
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}

	}
	if(dfs_low[u] == dfs_num[u]) {
		while(1) {
			int node = listNode.back(); listNode.pop_back();
			isVisited[node] = false;
			if(node == u){break;}
		}
		cnt++;
	}
}

int main(){
	int n,m,i,j;
	while(scanf("%d %d",&n,&m), (n||m)){
		counter = 0, cnt = 0;
		map<string,int> mapper;
		AdjList.assign(maxn, vi());
		for(i=0;i<n;i++) {
			string a,b;
			cin>>a>>b;
			a += b;
			mapper[a] = i;
			// printf("a: "); cout<<a<<endl;
		}
		for(i=0;i<m;i++){
			string a,b,c,d;
			cin>>a>>b>>c>>d;
			a += b;
			c += d;
			int id1 = mapper[a], id2 = mapper[c];
			AdjList[id1].pb(id2);
		}
		memset(dfs_num, -1, sizeof dfs_low);
		memset(isVisited, false, sizeof isVisited);
		for(i=0;i<n;i++){
			if(dfs_num[i] == -1){
				dfs(i);
			}
		}
		printf("%d\n",cnt);
	}
	
	return 0;
};