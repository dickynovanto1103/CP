#include <bits/stdc++.h>

using namespace std;
#define visited 1
#define unvisited -1
typedef vector<int> vi;

vi dfs_num, dfs_low, s, visitedNode;
vector<vi> AdjList;
int dfsCounter, numSCC;

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
		printf("SCC %d:",++numSCC);
		while(1){
			int node = s.back(); s.pop_back(); visitedNode[node] = unvisited;
			printf(" %d",node);
			if(node == u){printf("\n"); break;}
		}
	}
	
}

int main(){
	int i,a,b;
	int V,E;
	scanf("%d %d",&V,&E);
	AdjList.assign(V,vi()); dfs_num.assign(V,unvisited); dfs_low.assign(V,0); visitedNode.assign(V,unvisited);

	for(i=0;i<E;i++){
		scanf("%d %d",&a,&b);
		AdjList[a].push_back(b);
	}
	dfsCounter = numSCC = 0;

	for(i=0;i<V;i++){
		if(dfs_num[i]==unvisited){
			tarjan(i);
		}
	}
	return 0;
}