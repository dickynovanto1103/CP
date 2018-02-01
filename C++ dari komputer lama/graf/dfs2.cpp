#include <bits/stdc++.h>

using namespace std;
typedef vector <int> vi;
typedef pair <int,int> ii;
typedef vector <ii> vii;
#define visited 1
#define unvisited -1


vector <vi> AdjList;
vector <vii> Weighted;

vi dfs_num;

void dfs(int s){
	int i;
	if(dfs_num[s]==visited){return;}
	else{
		dfs_num[s]=visited;
		printf("%d ",s);
		for(i=0;i<(int)AdjList[s].size();i++){
			if(dfs_num[AdjList[s][i]]==unvisited){
				dfs(AdjList[s][i]);
			}
		}
	}
}

int main(){
	int V,E,v1,v2,i,w;
	
	scanf("%d",&V);
	AdjList.assign(V,vi());
	dfs_num.assign(V,unvisited);
	scanf("%d",&E);
	for(i=0;i<E;i++){
		scanf("%d %d",&v1,&v2);
		AdjList[v1].push_back(v2);
		AdjList[v2].push_back(v1);//undirected
	}
	printf("AdjList:\n");
	for(i=0;i<V;i++){
		printf("Node %d: ",i);
		for(int j=0;j<(int)AdjList[i].size();j++){
			printf("-> %d ",AdjList[i][j]);
		}
		printf("\n");
	}
	/*Weighted.assign(V,vii());
	for(i=0;i<E;i++){
		scanf("%d %d %d",&v1,&v2,&w);
		ii pair;
		pair=ii(v2,w);
		Weighted[v1].push_back(pair);
		pair=ii(v1,w);
		Weighted[v2].push_back(pair);
	}
	printf("Weighted:\n");
	for(i=0;i<V;i++){
		printf("Node %d: ",i);
		for(int j=0;j<(int)Weighted[i].size();j++){
			ii pair=Weighted[i][j];
			printf("-> %d(%d) ",pair.first,pair.second);
		}
		printf("\n");
	}*/
	printf("masukkan node yang mau didfs:\n");
	int s;
	scanf("%d",&s);printf("dfs from node %d: ",s);dfs(s);
	return 0;
}