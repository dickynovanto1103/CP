#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> AdjList, AdjDirected;
vi dfs_num;
ll anak[50010];

void dfs(int u, int parent){
	dfs_num[u] = visited;
	for(int i=0;i<AdjList[u].size();i++){
		int v = AdjList[u][i];
		if(dfs_num[v]==unvisited){
			AdjDirected[u].pb(v);
			dfs(v,u);
		}
	}
}

void countAnak(int u){
	anak[u] = 1;
	for(int i=0;i<AdjDirected[u].size();i++){
		int v = AdjDirected[u][i];
		countAnak(v);
		anak[u]+=anak[v];
	}
}

ll tot;

void solve(int u){
	for(int i=0;i<AdjDirected[u].size();i++){
		int v = AdjDirected[u][i];
		tot+=((anak[0]-anak[v])*anak[v]);
		solve(v);
	}
}


int main() {
	int tc,n,i;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		AdjList.assign(n,vi()); AdjDirected.assign(n,vi());
		dfs_num.assign(n,unvisited);
		int a,b;
		for(i=0;i<n-1;i++){
			scanf("%d %d",&a,&b); a--; b--; 
			AdjList[a].pb(b); AdjList[b].pb(a);
		}
		dfs(0,-1);

		countAnak(0);
		tot = 0;
		solve(0);
		printf("%lld\n",2*tot);
		AdjDirected.clear(); AdjList.clear(); dfs_num.clear();
	}
	return 0;
}