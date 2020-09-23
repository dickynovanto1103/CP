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
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vii> adj;

const int maxn = 5e5 + 5;

int dp[maxn], shortestColor[2][maxn];
int color[maxn];

void bfs(int node) {
	queue<int> q;
	q.push(node);
	while(!q.empty()){
		node = q.front(); q.pop();
		// printf("node: %d\n",node);
		for(int i=0;i<adj[node].size();i++){
			ii v = adj[node][i];
			int tetangga = v.first, color = v.second;
			// printf("node: %d tetangga: %d color: %d shortestColor: %d dp: %d\n",node, tetangga, color, shortestColor[color][tetangga], dp[node]);
			if(shortestColor[color][tetangga] == inf){
				shortestColor[color][tetangga] = min(shortestColor[color][tetangga], dp[node] + 1);
				// printf("shortestColor[%d][%d] jadi: %d\n",color, tetangga, shortestColor[color][tetangga]);
				assert(shortestColor[color][tetangga] < inf);
				if(shortestColor[0][tetangga] != inf && shortestColor[1][tetangga] != inf){
					dp[tetangga] = max(shortestColor[0][tetangga], shortestColor[1][tetangga]);
					q.push(tetangga);
				}
			}
		}
	}
}

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++){
		dp[i] = shortestColor[0][i] = shortestColor[1][i] = inf;
	}
	adj.assign(n+1, vii());
	for(i=0;i<m;i++){
		int a,b,t;
		scanf("%d %d %d",&a,&b,&t);
		adj[b].pb(ii(a,t));
	}
	dp[n] = shortestColor[0][n] = shortestColor[1][n] = 0;
	bfs(n);
	for(i=1;i<=n;i++){
		// printf("dp[%d]: %d shortestColor[0][%d]: %d shortestColor[1][%d]: %d\n",i, dp[i], i, shortestColor[0][i], i, shortestColor[1][i]);
		if(shortestColor[0][i] > shortestColor[1][i]) {
			color[i] = 0;
		}else{
			color[i] = 1;
		}
	}
	if(dp[1] >= inf){
		printf("-1\n");
	}else{
		printf("%d\n",dp[1]);
	}
	for(i=1;i<=n;i++){
		printf("%d",color[i]);
	}
	printf("\n");
	
	return 0;
};