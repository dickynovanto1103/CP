#include <bits/stdc++.h>

using namespace std;
#define visited 1
#define unvisited -1
typedef vector<int> vi;

vi dfs_num, dfs_low, s, visitedNode;
vector<vi> AdjList;
int dfsCounter, numSCC;

void tarjan(int u){
	dfs_num[u] = visited;
	for(int i = 0; i < AdjList[u].size(); i++){
		int v = AdjList[u][i];
		if(dfs_num[v]==unvisited){
			tarjan(v);
		}
	}
}

int main(){
	int i,j,a,b,tc,V,E;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&V,&E);
		AdjList.assign(V,vi()); dfs_num.assign(V,unvisited); dfs_low.assign(V,0); visitedNode.assign(V,unvisited);

		for(i=0;i<E;i++){
			scanf("%d %d",&a,&b);
			a--; b--;
			AdjList[a].push_back(b); AdjList[b].push_back(a);
		}
		dfsCounter = numSCC = 0;
		int ans = 0;
		for(i=0;i<V;i++){
			if(dfs_num[i]==unvisited){
				ans++;
				tarjan(i);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}