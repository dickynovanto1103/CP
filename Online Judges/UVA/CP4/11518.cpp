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
#define debug if(true)
typedef long long ll;
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool isVisited[10001];
vector<vi> adj;

void dfs(int node) {
	isVisited[node] = true;
	for(int i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		if(!isVisited[v]) {
			dfs(v);
		}
	}
}

void solve(){
	int n,m,l;
	scanf("%d %d %d",&n,&m,&l);
	for(int i=0;i<=n;i++){
		isVisited[i] = false;
	}
	
	adj.assign(n+1, vi());
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a].pb(b);
	}

	for(int i=0;i<l;i++){
		int node;
		scanf("%d",&node);
		dfs(node);
	}

	int ans = 0;
	for(int i=1;i<=n;i++){
		if(isVisited[i]){
			ans++;
		}
	}

	printf("%d\n", ans);
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};