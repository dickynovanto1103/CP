#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define explored 2
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> AdjList;
vi dfs_num,ans;
bool isCyclic;
void dfs(int a){
	if(isCyclic){return;}
	dfs_num[a] = explored;
	for(int i=0;i<AdjList[a].size();i++){
		int v = AdjList[a][i];
		if(dfs_num[v]==unvisited){dfs(v);}
		else if(dfs_num[v]==explored){isCyclic = true;}
	}
	ans.pb(a);
	dfs_num[a] = visited;
}

int main() {
	int n,m,i,j,a,b;
	scanf("%d %d",&n,&m);
	AdjList.assign(n+1,vi()); dfs_num.assign(n+1,unvisited);
	for(i=0;i<m;i++){scanf("%d %d",&a,&b); AdjList[a].pb(b);}
	isCyclic = false;
	for(i=1;i<=n;i++){
		if(dfs_num[i]==unvisited){
			dfs(i);
			if(isCyclic){break;}
		}
	}
	
	if(isCyclic){
		for(i=0;i<n;i++){
			if(i){printf(" ");}
			printf("-1");
		}
		printf("\n");
	}
	else{
		int ukuran = ans.size();
		for(i=ukuran-1;i>=0;i--){
			if(!i){printf("%d",ans[i]);}
			else{printf("%d ",ans[i]);}
		}
		printf("\n");
	}
	return 0;
}