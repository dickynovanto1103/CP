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

vector<vi> adj;

int dist[2001][2001];

void bfs(int node) {
	queue<int> q;
	q.push(node);
	dist[node][node] = 0;
	int i,j;
	while(!q.empty()){
		int bil = q.front(); q.pop();
		for(i=0;i<adj[bil].size();i++){
			int v = adj[bil][i];
			if(dist[node][v] == inf) {
				dist[node][v] = dist[node][bil] + 1;
				q.push(v);
			}
		}
	}
}

int main(){
	int n,x,y,i,j;
	scanf("%d %d %d",&n,&x,&y);
	adj.assign(n+1, vi());
	for(i=1;i<n;i++){
		adj[i].pb(i+1);
		adj[i+1].pb(i);
	}
	adj[x].pb(y);
	adj[y].pb(x);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			dist[i][j] = inf;
		}
	}
	for(i=1;i<=n;i++){
		bfs(i);
	}
	int cnt[200001];
	memset(cnt, 0, sizeof cnt);
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			// printf("dist[%d][%d]: %d\n",i,j,dist[i][j]);
			cnt[dist[i][j]]++;
		}
	}
	for(i=1;i<n;i++){
		printf("%d\n",cnt[i]);
	}

	return 0;
};