#include <bits/stdc++.h>

using namespace std;
#define maxvertex 100
#define visited 1
#define unvisited -1
typedef pair<int,int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

vector <vii> AdjList;
queue <int> q;

int main(){
	int V,totalneighbor,i,j,id,weight;
	int indegree[maxvertex+1];
	vi sorted;

	memset(indegree,0,sizeof indegree);
	scanf("%d",&V);
	AdjList.assign(V,vii());
	for(i=0;i<V;i++){
		scanf("%d",&totalneighbor);
		for(j=0;j<totalneighbor;j++){
			scanf("%d %d",&id,&weight);
			indegree[id]++;
			AdjList[i].push_back(ii(id,weight));
		}
	}
	//
	for(i=0;i<V;i++){
		if(indegree[i]==0) q.push(i);
	}
	while(!q.empty()){
		int v = q.front(); q.pop();
		sorted.push_back(v);
		for(i=0;i<(int)AdjList[v].size();i++){
			ii pair=AdjList[v][i];
			indegree[pair.first]--;
			if(indegree[pair.first]==0){q.push(pair.first);}
		}
	}
	printf("toposort:");
	for(i=0;i<sorted.size();i++){
		printf(" %d",sorted[i]);
	}
	printf("\n");

	return 0;
}