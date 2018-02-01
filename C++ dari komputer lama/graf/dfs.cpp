/*#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define visited 1
#define unvisited -1

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector<vii> AdjList;
vi dfs_num;

void dfs(int u){
	printf(" %d",u);
	dfs_num[u]=visited;
	for (int i = 0; i < (int)AdjList[u].size(); i++)
	{
		ii v=AdjList[u][i];
		if(dfs_num[v.first]==unvisited){
			dfs(v.first);
		}
	}
}

int main(){
	int totalneighbor,V,i,j,id,weight;
	//printf("masukkan jumlah V\n");
	scanf("%d",&V);
	AdjList.assign(V,vii());
	for(i=0;i<V;i++){
		//printf("untuk node %d, masukkan jumlah neighbor\n",i);
		scanf("%d",&totalneighbor);
		for(j=0;j<totalneighbor;j++){
			//printf("masukkan node tetangga dan berat edgenya\n");
			scanf("%d %d",&id,&weight);
			AdjList[i].push_back(ii(id,weight));
		}
		
	}
	int numComponent=0;
	dfs_num.assign(V,unvisited);
	for(i=0;i<V;i++){
		if(dfs_num[i]==unvisited){
			printf("Component %d:",++numComponent),dfs(i),printf("\n");
		}
	}
	printf("Ada %d Component terhubung\n",numComponent);
	return 0;
}*/

#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector <ii> vii;



int main(){

	return 0;
}