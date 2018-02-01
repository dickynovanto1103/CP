#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vi dfs_num, dfs_low, s, visitedNode;
vector<vi> AdjList;
int dfsCounter, numSCC;
const int maxn = 100010;
vector<vi> ans;

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
		//printf("SCC %d:",++numSCC);
		++numSCC;
		while(1){
			int node = s.back(); s.pop_back(); visitedNode[node] = unvisited;
			ans[numSCC].pb(node);
			//printf(" %d",node);
			if(node == u){break;}
		}

	}
	
}


int main() {
	int n,i,j;
	int a[maxn], temp[maxn];
	map<int,int> mapper1,mapper2;
	scanf("%d",&n);
	AdjList.assign(n+1,vi());
	for(i=0;i<n;i++){scanf("%d",&a[i]); temp[i] = a[i]; mapper1[a[i]] = i+1;}
	sort(temp,temp+n);
	for(i=0;i<n;i++){mapper2[temp[i]] = i+1;}
	//construct graph
	for(i=0;i<n;i++){
		int node1 = mapper1[a[i]], node2 = mapper2[a[i]];
		AdjList[node1].pb(node2);
	}
	dfs_num.assign(n+1,unvisited); dfs_low.assign(n+1,0); visitedNode.assign(n+1,unvisited); ans.assign(n+1,vi());
	dfsCounter = numSCC = 0;

	for(i=1;i<=n;i++){
		if(dfs_num[i]==unvisited){
			tarjan(i);
		}
	}
	printf("%d\n",numSCC);
	for(i=1;i<=numSCC;i++){
		printf("%d",ans[i].size());
		for(j=0;j<ans[i].size();j++){printf(" %d",ans[i][j]);}
		printf("\n");
	}
	
	return 0;
}