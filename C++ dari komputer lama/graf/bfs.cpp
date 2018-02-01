#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
#define INF 2000000000


typedef pair <int,int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

vector<vii> AdjList;
vi parent;
int s;

void PrintPath(int u){
	if(u==s){printf("%d ",u);return;}//jika node=start node, langsung diprint dan keluar dr void
	else{
		PrintPath(parent[u]);//print parentnya dulu habis itu baru node u nya
		printf("%d ",u);
	}
}

int main(){
	int V,E,i,v1,v2,a,layer;
	queue <int> q;

	scanf("%d %d",&V,&E);
	AdjList.assign(V,vii());
	for(i=0;i<E;i++){
		scanf("%d %d",&v1,&v2);
		AdjList[v1].push_back(ii(v2,0));
		AdjList[v2].push_back(ii(v1,0));
	}
	vi dist(V,INF);

	s=5;dist[s]=0;//starting node
	q.push(s);
	parent.assign(V,-1);
	layer=-1;
	while(!q.empty()){
		a=q.front();q.pop();
		if(layer!=dist[a]){printf("\nLayer %d: ",dist[a]);}
		layer=dist[a];
		printf("visit: %d ",a);
		for(i=0;i<(int)AdjList[a].size();i++){
			ii v=AdjList[a][i];
			if(dist[v.first]==INF){
				dist[v.first]=dist[a]+1;
				parent[v.first]=a;
				q.push(v.first);
			}
		}
	}
	printf("shortest path: ");
	PrintPath(9);
	printf("jaraknya: %d\n",dist[9]);

	return 0;
}