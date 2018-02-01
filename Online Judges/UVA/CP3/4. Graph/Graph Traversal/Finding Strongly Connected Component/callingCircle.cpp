#include <bits/stdc++.h>

using namespace std;
#define visited 1
#define unvisited -1
typedef vector<int> vi;

vi dfs_num, dfs_low, s, visitedNode;
vector<vi> AdjList;
int dfsCounter, numSCC;
map<string,int> mapper;
map<string,int>::iterator it;
map<int,string> mapper1;
map<int,string>::iterator it1;

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
		
		int countJawab = 0;
		while(1){
			int node = s.back(); s.pop_back(); visitedNode[node] = unvisited;
			if(!countJawab){cout<<mapper1[node]; countJawab = 1;}
			else{printf(", "); cout<<mapper1[node];}
			//printf(" %d",node);
			if(node == u){printf("\n"); break;}
		}
	}
	
}

int main(){
	int i,a,b,test=1;
	int V,E,cnt;
	string kata1,kata2;
	

	while(scanf("%d %d",&V,&E),(V||E)){
		AdjList.assign(V,vi()); dfs_num.assign(V,unvisited); dfs_low.assign(V,0); visitedNode.assign(V,unvisited);
		if(test>0){printf("\n");}
		cnt = 0;
		printf("Calling circles for data set %d:\n",test++);
		for(i=0;i<E;i++){
			cin>>kata1>>kata2;
			it = mapper.find(kata1);
			if(it==mapper.end()){mapper[kata1] = cnt++;}
			it = mapper.find(kata2);
			if(it==mapper.end()){mapper[kata2] = cnt++;}
			a = mapper[kata1]; b = mapper[kata2];
			mapper1[a] = kata1; mapper1[b] = kata2;
			AdjList[a].push_back(b);
		}
		dfsCounter = 0;

		for(i=0;i<V;i++){
			if(dfs_num[i]==unvisited){
				tarjan(i);
			}
		}
		mapper.clear(); mapper1.clear(); AdjList.clear(); dfs_num.clear(); dfs_low.clear(); visitedNode.clear(); s.clear();
	}
	
	return 0;
}