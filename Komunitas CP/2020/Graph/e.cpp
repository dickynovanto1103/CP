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
int dist[1001][1001];

void bfs(int node) {
	queue<int> q;
	dist[node][node] = 0;
	q.push(node);
	while(!q.empty()){
		int front = q.front(); q.pop();
		for(int i=0;i<adj[front].size();i++){
			int v = adj[front][i];
			if(dist[node][v] == inf) {
				dist[node][v] = dist[node][front] + 1;
				q.push(v);
			}
		}
	}
}

int main(){
	int n,m,s,t,i,j;
	scanf("%d %d %d %d",&n,&m,&s,&t);
	adj.assign(n+1, vi());
	for(i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a].pb(b);
		adj[b].pb(a);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			dist[i][j] = inf;
		}
	}
	for(i=1;i<=n;i++){
		bfs(i);
	}

	int distAwal = dist[s][t];
	// printf("distAwal: %d\n", distAwal);
	int cnt = 0;
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			//make road between node i and j
			if(dist[i][j] == 1){continue;}
			int dist1 = dist[s][i];
			int dist2 = dist[j][t];
			// printf("i: %d j: %d dist1: %d dist2: %d\n",i,j,dist1, dist2);
			bool mungkinTambah = false;
			if(dist1 + dist2 + 1 >= distAwal) {
				mungkinTambah = true;
				// cnt++;
			}
			dist1 = dist[t][i];
			dist2 = dist[j][s];
			if((dist1 + dist2 + 1) >= distAwal && mungkinTambah) {
				cnt++;
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
};