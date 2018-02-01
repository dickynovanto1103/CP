#include <bits/stdc++.h>

using namespace std;
#define inf 2000000000
typedef pair <int,int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

vector <vii> AdjList;
vi dist;

int main(){
	int tc,V,E,i,j,k,u,v,w;
	bool iscycle;

	scanf("%d",&tc);
	while(tc--){
		iscycle=false;
		scanf("%d %d",&V,&E);
		AdjList.assign(V,vii());
		dist.assign(V,inf);
		for(i=0;i<E;i++){
			scanf("%d %d %d",&u,&v,&w);
			AdjList[u].push_back(ii(v,w));
		}
		//bellman ford
		dist[0]=0;
		for(i=0;i<V-1;i++){
			for(j=0;j<V;j++){
				for(k=0;k<AdjList[j].size();k++){
					ii pair = AdjList[j][k];
					dist[pair.first]=min(dist[pair.first],pair.second+dist[j]);
				}
			}
		}
		//cek cycle
		for(j=0;j<V && !iscycle;j++){
			for(k=0;k<AdjList[j].size() && !iscycle;k++){
				ii pair = AdjList[j][k];
				if(dist[pair.first] > pair.second + dist[j]){iscycle=true;}
			}
		}
		if(iscycle){printf("possible\n");}
		else{printf("not possible\n");}
		AdjList.clear(); dist.clear();
	}
	return 0;
}