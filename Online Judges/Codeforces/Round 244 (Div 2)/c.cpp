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

const int maxn = 1e5 + 5;
const ll mod = 1e9 + 7;
vi dfs_num, dfs_low, s, visitedNode;
vector<vi> AdjList;
int dfsCounter, numSCC;
int a[maxn];

ll numWay = 1;
ll minimCost = 0;

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
		int cntSama = 0;
		int minim = inf;
		while(1){
			int node = s.back(); s.pop_back(); visitedNode[node] = unvisited;
			if(minim > a[node]){
				minim = a[node];
				cntSama = 1;
			}else if(minim == a[node]){
				cntSama++;
			}
			// printf(" %d",node);
			if(node == u){break;}
		}
		minimCost += minim;
		numWay *= cntSama;
		numWay %= mod;
	}
	
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	AdjList.assign(n+1,vi()); dfs_num.assign(n+1,unvisited); dfs_low.assign(n+1,0); visitedNode.assign(n+1,unvisited);
	
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int m;
	scanf("%d",&m);
	for(i=0;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		AdjList[x].pb(y);
	}

	dfsCounter = numSCC = 0;

	for(i=1;i<=n;i++){
		if(dfs_num[i]==unvisited){
			tarjan(i);
		}
	}
	printf("%lld %lld\n",minimCost, numWay);

	return 0;
};