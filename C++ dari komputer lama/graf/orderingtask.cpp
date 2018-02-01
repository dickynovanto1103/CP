#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;
#define visited 1
#define unvisited -1
typedef vector <int> vi;
vector <vi> AdjList;
vi dfs_num, topo; 
void toposort(int a){
	int i;
	dfs_num[a]=visited;
	for(i=0;i<AdjList[a].size();i++){
		int node = AdjList[a][i];
		if(dfs_num[node]==unvisited){toposort(node);}
	}
	topo.push_back(a);
}

int main(){
	int n,m,i,a,b;
	while(scanf("%d %d",&n,&m),(n||m)){
		AdjList.assign(n+1,vi()); dfs_num.assign(n+1,unvisited);
		for(i=0;i<m;i++){scanf("%d %d",&a,&b); AdjList[a].push_back(b);}
		for(i=1;i<=n;i++){
			if(dfs_num[i]==unvisited){toposort(i);}
		}
		reverse(topo.begin(), topo.end());
		for(i=0;i<n;i++){
			if(i==0){printf("%d",topo[i]);}
			else{printf(" %d",topo[i]);}
		}
		printf("\n");
		AdjList.clear(); dfs_num.clear(); topo.clear();
	}
	return 0;
}