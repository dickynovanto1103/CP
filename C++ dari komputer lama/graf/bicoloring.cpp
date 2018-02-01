#include <bits/stdc++.h>

using namespace std;
#define visited 1
#define unvisited -1
#define inf 1000000000
typedef vector <int> vi;

vector <vi> AdjList;


int main(){
	int n,e,i,j,a,b,v,vertex;
	queue <int> q;
	bool isBipartite;
	while(scanf("%d",&n),n){
		AdjList.assign(n,vi());
		vi color(n,inf);
		scanf("%d",&e);
		for(i=0;i<e;i++){
			scanf("%d %d",&a,&b);
			AdjList[a].push_back(b);
			AdjList[b].push_back(a);
		}
		q.push(0);color[0]=0;
		isBipartite=true;
		while(!q.empty() && isBipartite){
			v = q.front(); q.pop();
			for(i=0;i<(int)AdjList[v].size();i++){
				vertex=AdjList[v][i];
				if(color[vertex]==inf){
					color[vertex]=1-color[v];
					q.push(vertex);
				}else if(color[vertex]==color[v]){
					isBipartite=false;
				}
			}
		}
		if(isBipartite){printf("BICOLORABLE.\n");}
		else{printf("NOT BICOLORABLE.\n");}
	}
	return 0;
}