#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> AdjList;
vi ans;
bool isVisited[15];
void dfs(int node){
	isVisited[node] = true;
	ans.pb(node);
	for(int i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		if(!isVisited[v]){
			dfs(v);
		}
	}
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	AdjList.assign(n+1,vi());
	for(i=0;i<(n-1);i++){
		int a,b;
		scanf("%d %d",&a,&b);
		AdjList[a].pb(b); AdjList[b].pb(a);
	}
	memset(isVisited, false, sizeof isVisited);

	dfs(0);
	for(i=0;i<ans.size();i++){
		if(i){printf(" ");}
		printf("%d",ans[i]);
	}
	printf("\n");
	return 0;
};