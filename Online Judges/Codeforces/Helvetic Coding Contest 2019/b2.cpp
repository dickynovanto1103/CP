#include <bits/stdc++.h>

using namespace std;
#define inf 2000000000
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

vector<vi> adj, AdjList;
int dist[102][102];

struct space{
	int x,a,f;
};

struct base{
	int x,d;
};

void bfs(int node) {
	int i,j;
	queue<int> q;
	dist[node][node] = 0;
	q.push(node);
	while(!q.empty()) {
		int front = q.front(); q.pop();
		for(i=0;i<adj[front].size();i++){
			int v = adj[front][i];
			if(dist[node][v] == inf){
				dist[node][v] = dist[node][front] + 1;
				q.push(v);
			}
		}
	}
}

vi match, vis;

int Aug(int node) {
	if(vis[node]){return 0;}
	vis[node] = 1;
	for(int i=0;i<AdjList[node].size();i++) {
		int v = AdjList[node][i];
		if(match[v] == -1 || Aug(match[v])) {
			match[v] = node; return 1; // found 1 matching
		}
	}
	return 0; //no matching
}

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	adj.assign(n+1, vi());
	AdjList.assign(1010, vi());
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			dist[i][j] = inf;
		}
	}
	for(i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a].pb(b); adj[b].pb(a);
	}
	for(i=1;i<=n;i++){
		bfs(i);
		// for(j=1;j<=n;j++){
		// 	printf("dist[%d][%d]: %d\n",i,j,dist[i][j]);
		// }
	}

	int s,b,k,h;
	scanf("%d %d %d %d",&s,&b,&k,&h);
	space sp[1010];
	base ba[1010];
	for(i=1;i<=s;i++){
		int x,a,f;
		scanf("%d %d %d",&sp[i].x,&sp[i].a,&sp[i].f);
	}
	for(i=1;i<=b;i++){
		int x,def;
		scanf("%d %d",&ba[i].x, &ba[i].d);
	}
	for(i=1;i<=s;i++) {
		int koorS = sp[i].x, att = sp[i].a, fuel = sp[i].f;
		for(j=1;j<=b;j++) {
			int koorB = ba[j].x, def = ba[j].d;
			if(dist[koorS][koorB] <= fuel && def <= att) {
				AdjList[i].pb(s + j);
			}
		}
	}

	int mcbm = 0;
	match.assign(s + b + 20,-1);
	for(i=1;i<=s;i++){
		vis.assign(s+2,0);
		mcbm+=Aug(i);
	}
	// printf("mcbm: %d\n",mcbm);
	ll jawab = min((ll)mcbm * (ll)k, (ll)h*(ll)s);
	printf("%lld\n",jawab);

	return 0;
};