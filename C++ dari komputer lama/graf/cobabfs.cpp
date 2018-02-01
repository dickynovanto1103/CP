#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
typedef vector <int> vi;

int awal;
vector <vi> AdjList;
int p[100];

void reconstructPrint(int v){
	if(v!=awal){reconstructPrint(p[v]);}
	printf("%d ",v);
}

int main(){
	int V,E,i,v1,v2,akhir;

	queue <int> q;
	scanf("%d %d",&V,&E);
	vi dist(V,inf);
	AdjList.assign(V,vi());
	for(i=0;i<E;i++){
		scanf("%d %d",&v1,&v2);
		AdjList[v1].push_back(v2);
		AdjList[v2].push_back(v1);
	}
	scanf("%d",&awal);
	dist[awal]=0;
	q.push(awal);
	while(!q.empty()){
		int v=q.front(); q.pop();
		for(i=0;i<(int)AdjList[v].size();i++){
			int vertex=AdjList[v][i];
			if(dist[vertex]==inf){//belum dikunjungi
				dist[vertex]=dist[v]+1;
				p[vertex]=v;
				q.push(vertex);
			}
		}
	}
	scanf("%d",&akhir);
	printf("shortest path from %d to %d is %d\n",awal,akhir,dist[akhir]);
	printf("path:\n");
	reconstructPrint(akhir);
	return 0;
}