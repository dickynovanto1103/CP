#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000000000LL
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

const int maxn = 3e5 + 5;

vector<vii> adj;

bool vis[maxn];

ll dist[maxn];
ll a[maxn];

vi listNode;

void dfs(int node){
	// printf("node: %d\n",node);
	dist[node] += a[node];
	listNode.pb(node);
	vis[node] = true;
	// printf("dist[%d]: %lld\n",node,dist[node]);
	for(int i=0;i<adj[node].size();i++){
		ii pas = adj[node][i];
		int v = pas.first, w = pas.second;
		if(!vis[v]){
			dist[v] = max(dist[v], dist[node] - w);
			dfs(v);
		}
	}
}

void reset() {
	for(int i=0;i<listNode.size();i++){
		int node = listNode[i];
		dist[node] = 0;
		vis[node] = false;
	}
	listNode.clear();
}

ll findDiameter(int node){
	reset();
	dfs(node);
	int i,j;
	ll maks = -inf;
	int idx;
	for(i=0;i<listNode.size();i++){
		int node = listNode[i];
		if(maks < dist[node]){
			maks = dist[node];
			idx = node;
		}
	}
	reset();

	dfs(idx);
	maks = -inf;
	for(i=0;i<listNode.size();i++){
		int node = listNode[i];
		if(maks < dist[node]){
			maks = dist[node];
			idx = node;
		}
	}
	return maks;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	adj.assign(n+1,vii());
	
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(i=0;i<n-1;i++){
		int x,y,w;
		scanf("%d %d %d",&x,&y,&w);
		adj[x].pb(ii(y,w)); adj[y].pb(ii(x,w));	
	}

	memset(dist, 0, sizeof dist);
	memset(vis, false, sizeof vis);
	ll ans = 0;
	for(i=1;i<=n;i++){
		if(!vis[i]){
			ans = max(ans, findDiameter(i));
		}
	}

	printf("%lld\n",ans);



	return 0;
};