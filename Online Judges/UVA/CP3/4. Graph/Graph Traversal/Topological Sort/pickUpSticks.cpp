#include <bits/stdc++.h>

using namespace std;
#define visited 1
#define unvisited -1
#define explored 2
typedef vector<int> vi;
typedef pair<int,int> ii;
vector<vi> AdjList;
vi dfs_num, ans;
bool foundCycle;

void toposort(int u){
	int i;
	dfs_num[u] = visited;
	
	for(i=0;i<AdjList[u].size();i++){
		int v = AdjList[u][i];
	
		if(dfs_num[v]==unvisited){
			toposort(v);
		}
	}
	ans.push_back(u);
}

void graphCheck(int u){
	if(foundCycle){return;}
	dfs_num[u] = explored;
	for(int i=0;i<AdjList[u].size();i++){
		int v = AdjList[u][i];
		if(dfs_num[v] == unvisited){
			graphCheck(v);
		}
		if(dfs_num[v] == explored){
			foundCycle = true;
		}
	}
	dfs_num[u] = visited;
}



int main(){
	int n,m,i,j;
	//freopen("input.txt","r",stdin);
	while(scanf("%d %d",&n,&m),(n||m)){

		AdjList.assign(n+1,vi()); dfs_num.assign(n+1,unvisited);
		for(i=0;i<m;i++){
			int a,b;
			scanf("%d %d",&a,&b); AdjList[a].push_back(b);
		}
		//check cycles
		foundCycle = false;
		for(i=1;i<=n;i++){
			if(dfs_num[i]==unvisited){graphCheck(i);}
			if(foundCycle) break;
		}
		if(foundCycle){printf("IMPOSSIBLE\n");}
		else{
			dfs_num.assign(n+1,unvisited);
			for(i=1;i<=n;i++){
				if(dfs_num[i]==unvisited){
					toposort(i);
				}
			}
			reverse(ans.begin(),ans.end());
			int ukuran = ans.size();
			for(i=0;i<ukuran;i++){printf("%d\n",ans[i]);}
		}
		AdjList.clear(); dfs_num.clear(); ans.clear();
	}
	

	return 0;
}