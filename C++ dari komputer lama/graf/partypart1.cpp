#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
typedef vector <int> vi;

vector <vi> AdjList;
vi dist;
int main(){
	int tc,i,j,V,E,a,b;
	queue <int> q;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&V,&E);
		AdjList.assign(V,vi());
		dist.assign(V,inf);
		for(i=0;i<E;i++){scanf("%d %d",&a,&b); AdjList[a].push_back(b); AdjList[b].push_back(a);}
		dist[0] = 0; q.push(0);
		while(!q.empty()){
			int front = q.front(); q.pop();
			for(i=0;i<AdjList[front].size();i++){
				int v = AdjList[front][i];
				if(dist[v]==inf){
					q.push(v); dist[v]=dist[front] + 1;
				}
			}
		}
		for(i=1;i<V;i++){printf("%d\n",dist[i]);}
		if(tc){printf("\n");}
		AdjList.clear(); dist.clear();
	}
	return 0;
}