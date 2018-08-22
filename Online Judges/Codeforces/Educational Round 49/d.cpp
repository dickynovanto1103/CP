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

typedef vector<int> vi;

const int maxn = 2e5 + 5;

vi dfs_num, dfs_low, s, visitedNode;
vector<vi> AdjList;
int dfsCounter, numSCC;

ll ans = 0;
int cost[maxn];

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
		// printf("SCC %d:",++numSCC);
		vi listScc;
		while(1){
			int node = s.back(); s.pop_back(); visitedNode[node] = unvisited;
			listScc.pb(node);
			// printf(" %d",node);
			if(node == u){break;}
		}
		int ukuran = listScc.size();
		if(ukuran == 1){
			int node = listScc[0];
			if(AdjList[node].size() == 0){
				ans += (ll)cost[node];
			}
		}else{
			ll minim = inf;
			for(int i=0;i<ukuran;i++){
				int node = listScc[i];
				minim = min(minim, (ll)cost[node]);
			}
			ans += minim;
		}
		
	}
	
}



int main(){
	int i,a,b;
	int n;
	scanf("%d",&n);
	AdjList.assign(n,vi()); dfs_num.assign(n,unvisited); dfs_low.assign(n,0); visitedNode.assign(n,unvisited);
	
	for(i=0;i<n;i++){
		scanf("%d",&cost[i]);
	}

	for(i=0;i<n;i++){
		int tujuan;
		scanf("%d",&tujuan);
		tujuan--;
		if(tujuan == i){continue;}
		AdjList[i].pb(tujuan);
	}

	dfsCounter = numSCC = 0;

	for(i=0;i<n;i++){
		if(dfs_num[i]==unvisited){
			tarjan(i);
		}
	}
	printf("%lld\n",ans);
	return 0;
}