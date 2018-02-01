#include <bits/stdc++.h>

using namespace std;
#define unvisited -1
#define visited 1
typedef vector<int> vi;

vector<vi> AdjList;

int dfsNumberCounter, dfsRoot, rootChildren;
vi dfs_num, dfs_low, dfs_parent, articulation_vertex;

void articulationPointAndBridge(int u) {
	int j;
	dfs_num[u] = dfs_low[u] = dfsNumberCounter++;
	for(j=0;j<AdjList[u].size();j++) {
		int v = AdjList[u][j];
		if(dfs_num[v] == unvisited) {
			dfs_parent[v] = u;
			if(u == dfsRoot) {rootChildren++;}

			articulationPointAndBridge(v);

			if(dfs_low[v] >= dfs_num[u]) {
				articulation_vertex[u] = true;
			}
			if(dfs_low[v] > dfs_num[u]) {
				printf("Edge: %d %d\n",u,v);
			}
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}else if(v != dfs_parent[u]){
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

int main() {
	int V,E,i,a,b;
	scanf("%d %d",&V,&E);
	AdjList.assign(V,vi());
	//add adge
	for(i=0;i<E;i++){
		scanf("%d %d",&a,&b);
		AdjList[a].push_back(b); AdjList[b].push_back(a);
	}

	dfsNumberCounter = 0; dfs_num.assign(V,unvisited); dfs_low.assign(V,0);
	dfs_parent.assign(V,0); articulation_vertex.assign(V,0);
	printf("bridges:\n");
	for(i=0;i<V;i++) {
		if(dfs_num[i] == unvisited) {
			dfsRoot = i; rootChildren = 0; articulationPointAndBridge(i);
			articulation_vertex[dfsRoot] = (rootChildren > 1);
		}
	}
	printf("articulation points:");
	for(i=0;i<V;i++){
		if(articulation_vertex[i]){
			printf(" %d",i);
		}
	}
	printf("\n");

	//cek dfs low dan dfs num
	for(i=0;i<V;i++) {
		printf("dfs_num[%d] = %d\n",i,dfs_num[i]);
		printf("dfs_low[%d] = %d\n\n",i,dfs_low[i]);
	}
	return 0;
}