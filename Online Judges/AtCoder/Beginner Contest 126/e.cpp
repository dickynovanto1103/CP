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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> AdjList;
const int maxn = 1e5 + 5;
bool vis[maxn];

void dfs(int node) {
	int i,j;
	vis[node] = true;
	for(i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		if(!vis[v]){
			dfs(v);
		}
	}
}

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	AdjList.assign(n+1, vi());
	for(i=0;i<m;i++){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		AdjList[x].pb(y); AdjList[y].pb(x);
	}
	memset(vis, false, sizeof vis);
	int cnt = 0;
	for(i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i);
			cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
};