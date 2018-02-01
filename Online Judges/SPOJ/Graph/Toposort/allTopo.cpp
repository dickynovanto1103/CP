#include <bits/stdc++.h>

using namespace std;
#define visited 1
#define unvisited -1
typedef vector<int> vi;

void allTopo(vector<vi> AdjList, int indegree[], int V, vi ans, vi dfs_num){
	int i;
	if(ans.size()==V){
		for(i=0;i<ans.size();i++){
			if(i>0) printf(" ");
			printf("%d",ans[i]);
		}
		printf("\n");
	}else{
		//cek semua node
		for(i=0;i<V;i++){
			if(indegree[i]==0 && dfs_num[i]==unvisited){
				ans.push_back(i);
				dfs_num[i] = visited;
				for(int j=0;j<AdjList[i].size();j++){
					int v = AdjList[i][j];
					indegree[v]--;
				}
				allTopo(AdjList,indegree,V,ans,dfs_num);
				ans.pop_back();
				dfs_num[i] = unvisited;
				for(int j=0;j<AdjList[i].size();j++){
					int v = AdjList[i][j];
					indegree[v]++;
				}
			}

		}
	}
}
int main(){
	int V,E,i,j;	
	vector<vi> AdjList;
	vi dfs_num;
	scanf("%d %d",&V,&E);
	int indegree[V];
	dfs_num.assign(V,unvisited);
	memset(indegree,0,sizeof indegree);
	AdjList.assign(V,vi());
	for(i=0;i<E;i++){
		int a,b;
		scanf("%d %d",&a,&b); AdjList[a].push_back(b);
		indegree[b]++;
	}
	vi ans;

	allTopo(AdjList,indegree,V,ans,dfs_num);

	return 0;
}