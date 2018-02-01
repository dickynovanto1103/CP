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
			/*if(dfs_low[v] > dfs_num[u]) {
				printf("Edge: %d %d\n",u,v);
			}*/
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}else if(v != dfs_parent[u]){
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

int main(){
	int V,i,j;
	string kata;
	while(scanf("%d",&V),V) {
		AdjList.assign(V+1, vi());
		getline(cin>>ws, kata);
		while(kata[0]!='0') {
			int bil = 0;
			int cnt = 0;
			int root;
			for(i=0;i<kata.length();i++) {
				if(kata[i]==' '){
					if(cnt==0) {root = bil; bil = 0; cnt++;}
					else {AdjList[root].push_back(bil); AdjList[bil].push_back(root); bil = 0;}
				}else {
					bil*=10; bil = bil+kata[i]-'0';
				}
			}
			AdjList[root].push_back(bil); AdjList[bil].push_back(root); bil = 0;
			getline(cin,kata);
		}
		/*for(i=1;i<=V;i++) {
			printf("node %d:",i);
			for(j=0;j<AdjList[i].size();j++){
				printf(" %d",AdjList[i][j]);
			}
			printf("\n");
		}*/
		dfsNumberCounter = 0; dfs_num.assign(V+1,unvisited); dfs_low.assign(V+1,0);
		dfs_parent.assign(V+1,0); articulation_vertex.assign(V+1,0);
		//printf("bridges:\n");
		for(i=1;i<=V;i++) {
			if(dfs_num[i] == unvisited) {
				dfsRoot = i; rootChildren = 0; articulationPointAndBridge(i);
				articulation_vertex[dfsRoot] = (rootChildren > 1);
			}
		}
		//printf("articulation points:");
		int ans = 0;
		for(i=1;i<=V;i++){
			if(articulation_vertex[i]){
				//printf(" %d",i);
				ans++;
			}
		}
		//printf("\n");

		printf("%d\n",ans);
		AdjList.clear(); dfs_low.clear(); dfs_num.clear(); dfs_parent.clear(); articulation_vertex.clear();
	}
	return 0;
}