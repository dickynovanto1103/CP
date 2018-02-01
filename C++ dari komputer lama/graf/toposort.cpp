#include <bits/stdc++.h>

using namespace std;
#define visited 1
#define unvisited -1
typedef pair<int,int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

vector <vii> AdjList;
vi dfs_num,toposort;
void dfs2(int u){
	int i;
	//printf("yang dikunjungi adalah %d\n",u);
	dfs_num[u]=visited;
	
	for(i=0;i<(int)AdjList[u].size();i++){
		ii pair;
		pair=AdjList[u][i];
		if(dfs_num[pair.first]==unvisited){
			dfs2(pair.first);
		}
	}
	printf("yang dipush: %d\n",u);
	toposort.push_back(u);
}

int main(){
	int i,V,totalneighbor,j,id,weight;
	ii pair;
	scanf("%d",&V);
	toposort.clear();
	dfs_num.assign(V,unvisited);
	AdjList.assign(V,vii());
	for(i=0;i<V;i++){
		scanf("%d",&totalneighbor);
		for(j=0;j<totalneighbor;j++){
			scanf("%d %d",&id,&weight);
			pair = ii(id,weight);
			AdjList[i].push_back(pair);
		}
	}
	for(i=0;i<V;i++){
		if(dfs_num[i]==unvisited){dfs2(i);}
	}
	printf("toposort:\n");
	reverse(toposort.begin(),toposort.end());
	for(i=0;i<toposort.size();i++){
		printf("%d ",toposort[i]);
	}
	printf("\n");
	return 0;
}