#include <bits/stdc++.h>

using namespace std;
#define unvisited -1
#define visited 1
typedef vector<int> vi;
typedef pair<int,int> ii;
vector<vi> AdjList;
vector<ii> nodes;

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

bool acompare(ii a, ii b) {return a.second > b.second;}
bool bcompare(ii a, ii b) {return a.first < b.first;}

int main(){
	int V,m,a,b,i,j;
	bool visited_vertex[10010];
	while(scanf("%d %d",&V,&m),(V || m)) {
		AdjList.assign(V,vi());
		while(scanf("%d %d",&a,&b), (a!=-1 && b!=-1)) {
			AdjList[a].push_back(b); AdjList[b].push_back(a);
		}
		//bikin list node yang terurut berdasarkan pigeon number
		for(i=0;i<V;i++){
			nodes.push_back(ii(i,AdjList[i].size()));
			visited_vertex[i] = false;
		}

		sort(nodes.begin(), nodes.end(), acompare);

		int current = nodes[0].second;
		int curidx = 0;
		for(i=1;i<V;i++){
			if(nodes[i].second < current) {sort(nodes.begin()+ curidx, nodes.begin()+i, bcompare); curidx = i; current = nodes[i].second;}
		}
		sort(nodes.begin()+curidx, nodes.begin()+V, bcompare);
		
		printf("terurut:\n");
		for(i=0;i<V;i++){
			printf("%d %d\n",nodes[i].first, nodes[i].second);
		}
		printf("\n");

		//articulation point
		dfsNumberCounter = 0; dfs_num.assign(V,unvisited); dfs_low.assign(V,0);
		dfs_parent.assign(V,0); articulation_vertex.assign(V,0);
		
		for(i=0;i<V;i++) {
			if(dfs_num[i] == unvisited) {
				dfsRoot = i; rootChildren = 0; articulationPointAndBridge(i);
				articulation_vertex[dfsRoot] = (rootChildren > 1);
			}
		}
		//printf("articulation points:");
		int ans = 0;
		vi ans_vertex;
		for(i=0;i<V;i++){

			if(articulation_vertex[nodes[i].first]){
				//printf(" %d",i);
				printf("yang dipush: %d\n",nodes[i].first);
				ans_vertex.push_back(nodes[i].first);
				ans++;
			}
		}
		for(i=0;i<m;i++){
			int v = ans_vertex[i];
			visited_vertex[v] = true;
			printf("%d %d\n",v, nodes[v].second);
		}
		int sisa = ans - m;
		printf("batas\n");
		for(i=0;i<V && sisa > 0;i++) {//tinjau nodes
			if(!visited_vertex[i]) {
				printf("%d %d\n",nodes[i].first, nodes[i].second);
				sisa--;
			}
		}
		
		ans_vertex.clear();
		AdjList.clear(); dfs_low.clear(); dfs_num.clear(); dfs_parent.clear(); articulation_vertex.clear(); nodes.clear();
	}
	return 0;
}