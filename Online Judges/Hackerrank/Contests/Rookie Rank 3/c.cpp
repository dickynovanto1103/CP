#include <bits/stdc++.h>

using namespace std;
#define unvisited -1
#define visited 1
typedef vector<int> vi;
vector<vi> AdjList;
vi dfs_num;
int cnt;
void dfs(int u){
	dfs_num[u] = visited;
	cnt++;

	for(int i=0;i<AdjList[u].size();i++){
		int v = AdjList[u][i];
		if(dfs_num[v]==unvisited){
			dfs(v);
		}
	}
}
int main(){
	int V,E,i,j,a,b,ans;
	scanf("%d %d",&V,&E);
	AdjList.assign(V,vi()); dfs_num.assign(V,unvisited);
	for(i=0;i<E;i++){
		scanf("%d %d",&a,&b); a--; b--;
		AdjList[a].push_back(b); AdjList[b].push_back(a);
	}
	ans = -1;
	for(i=0;i<V;i++){
		if(dfs_num[i]==unvisited){
			cnt = 0;
			dfs(i);
			//printf("cnt: %d\n",cnt);
			ans = max(ans, cnt);
		}
	}
	printf("%d\n",ans);
	return 0;
}