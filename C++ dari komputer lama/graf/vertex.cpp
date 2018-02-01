#include <bits/stdc++.h>

using namespace std;
#define unvisited -1
#define visited 1
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vi> AdjList;
vi dfs_num;
void dfs(int a){
	int i;
	for(i=0;i<AdjList[a].size();i++){
		int v = AdjList[a][i];
		if(dfs_num[v]==unvisited){ dfs_num[v] = visited; dfs(v); }
	}
}

int main(){
	int V,i,j,start,adj,n,a,cnt,list[110];
	while(scanf("%d",&V),V){
		AdjList.assign(V+1,vi());
	
		scanf("%d",&start);

		while(start!=0){
			//printf("start: %d\n",start);	
			scanf("%d",&adj);
			while(adj!=0){
				//printf("start: %d adj: %d\n",start,adj);
				AdjList[start].push_back(adj); scanf("%d",&adj);
			}
			//baca start lagi
			scanf("%d",&start);
		}
		/*for(i=1;i<=V;i++){
			//printf("node %d:",i);
			for(j=0;j<AdjList[i].size();j++){printf(" %d",AdjList[i][j]);}
			printf("\n");
		}*/
		scanf("%d",&n);
		for(i=0;i<n;i++){
			dfs_num.assign(V+1,unvisited);
			scanf("%d",&a);
			dfs(a);
			cnt=0;
			for(j=1;j<=V;j++){
				if(dfs_num[j]==unvisited) {list[cnt]=j; cnt++;}
			}

			printf("%d",cnt);
			for(j=0;j<cnt;j++){printf(" %d",list[j]);}
			printf("\n");
		}
	}
	

	return 0;
}