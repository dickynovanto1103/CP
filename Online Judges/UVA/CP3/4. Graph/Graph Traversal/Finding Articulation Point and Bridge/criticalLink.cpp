#include <bits/stdc++.h>

using namespace std;
#define unvisited -1
#define visited 1
typedef vector<int> vi;
typedef pair<int,int> ii;
vector<vi> AdjList;

int dfsNumberCounter, dfsRoot, rootChildren;
vi dfs_num, dfs_low, dfs_parent, articulation_vertex;
vector<ii> edges;
void articulationPointAndBridge(int u) {
	int j;
	dfs_num[u] = dfs_low[u] = dfsNumberCounter++;
	for(j=0;j<AdjList[u].size();j++) {
		int v = AdjList[u][j];
		if(dfs_num[v] == unvisited) {
			dfs_parent[v] = u;
			if(u == dfsRoot) {rootChildren++;}

			articulationPointAndBridge(v);

			/*if(dfs_low[v] >= dfs_num[u]) {
				articulation_vertex[u] = true;
			}*/
			if(dfs_low[v] > dfs_num[u]) {
				//printf("Edge: %d %d\n",u,v);
				edges.push_back(ii(u,v));
			}
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}else if(v != dfs_parent[u]){
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

int main(){
	int V,num_neighbors, a,b,i,j;
	while(scanf("%d",&V)!=EOF){
		AdjList.assign(V,vi());
		for(i=0;i<V;i++){
			scanf("%d (%d) ",&a,&num_neighbors);
		
			//printf("yang dibaca: %d\n",num_neighbors);
			for(j=0;j<num_neighbors;j++){
				scanf("%d",&b);
				AdjList[a].push_back(b);
			}	
		}
		
		dfsNumberCounter = 0; dfs_num.assign(V+1,unvisited); dfs_low.assign(V+1,0);
		dfs_parent.assign(V+1,0); articulation_vertex.assign(V+1,0);
		//printf("bridges:\n");
		for(i=0;i<V;i++) {
			if(dfs_num[i] == unvisited) {
				dfsRoot = i; rootChildren = 0; articulationPointAndBridge(i);
				articulation_vertex[dfsRoot] = (rootChildren > 1);
			}
		}
		printf("%d critical links\n",edges.size());
		for(i=0;i<edges.size();i++){
			int bil1 = edges[i].first;
			int bil2 = edges[i].second;
			if(bil1 > bil2){
				int temp = bil1;
				bil1 = bil2;	
				bil2 = temp;
			}
			edges[i].first = bil1;
			edges[i].second = bil2;
		}
		sort(edges.begin(), edges.end());
		for(i=0;i<edges.size();i++){
			printf("%d - %d\n",edges[i].first,edges[i].second);
		}
		printf("\n");
		AdjList.clear(); dfs_low.clear(); dfs_num.clear(); dfs_parent.clear(); articulation_vertex.clear();
		edges.clear();
	}
	return 0;
}