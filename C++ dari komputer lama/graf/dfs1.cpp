#include <cstdio>
#include <vector>
using namespace std;

#define unvisited -1
#define visited 1

typedef vector <int> vi;
typedef pair <int,int> ii;
typedef vector <ii> vii;

vector <vii> AdjList;
vi dfs_num;

void dfs(int u){
	int j;
	printf(" %d",u);
	dfs_num[u]=visited;
	for(j=0;j<AdjList[u].size();j++){
		ii v=AdjList[u][j];
		if(dfs_num[v.first]==unvisited){
			dfs(v.first);
		}
	}
}
int main(){
	int total_neighbor,V,i,j,id,weight,numCC;

	//printf("masukkan jumlah V\n");
	scanf("%d",&V);
	AdjList.assign(V,vii());
	for(i=0;i<V;i++){
		//printf("untuk node %d masukkan jumlah neighbor\n",i);
		scanf("%d",&total_neighbor);
		//printf("masukkan node tetangganya beserta berat edgenya\n");
		for(j=0;j<total_neighbor;j++){
			scanf("%d %d",&id,&weight);
			AdjList[i].push_back(ii(id,weight));
		}
	}
	for(i=0;i<V;i++){
		printf("node %d: ",i);
		for(vii::iterator it=AdjList[i].begin();it!=AdjList[i].end();++it){
			printf("-> %d(%d)",(*it).first,(*it).second);
		}
		printf("\n");
	}

	printf("DFS\n");
	numCC=0;
	dfs_num.assign(V,unvisited);
	for(i=0;i<V;i++){
			
				if(dfs_num[i]==unvisited){
					printf("component %d:",++numCC),dfs(i),printf("\n");
				}
			
		}
	return 0;
}