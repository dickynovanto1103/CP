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
#define debug if(false)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

int ans = inf;

int wa[maxn];
vector<vi> adj, graf;
vii edgeList;
vi listNode;
int dist[maxn];

int bfs(int node, int idx) {
	queue<int> q;
	
	dist[node] = 1;
	debug printf("node: %d\n",node);
	q.push(node);

	while(!q.empty()){
		int node = q.front(); q.pop();

		listNode.pb(node);
		for(int i=0;i<graf[node].size();i++){
			int v = graf[node][i];
			// printf("v: %d\n",v);
			if(ii(node,v) == edgeList[idx] || ii(v,node) == edgeList[idx]){
				// printf("sini node: %d v: %d\n",node, v);
				continue;
			}
			if(dist[v] == inf){
				dist[v] = dist[node] + 1;
				debug printf("dist[%d] jd: %d\n",v, dist[v]);
				q.push(v);
			}
		}
	}

	return dist[edgeList[idx].second];
}

void reset(){
	for(int i=0;i<listNode.size();i++){
		int node = listNode[i];
		dist[node] = inf;
	}
	listNode.clear();
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	ll a[maxn];
	
	adj.assign(65,vi());
	graf.assign(maxn, vi());
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
		for(j=0;j<64;j++){
			if((1LL<<j) & a[i]){
				adj[j].pb(i);
			}
		}
	}
	
	for(i=0;i<64;i++){
		if(adj[i].size() >= 3) {
			printf("3\n");
			return 0;
		}else if(adj[i].size() == 2) {
			int satu = adj[i][0], dua = adj[i][1];
			graf[satu].pb(dua); graf[dua].pb(satu);
			edgeList.pb(ii(satu, dua));
			// printf("connect %d dan %d\n",satu, dua);
		}
	}
	for(i=0;i<n;i++){
		dist[i] = inf;
	}
	for(i=0;i<edgeList.size();i++){
		ii pas = edgeList[i];
		int x = pas.first, y = pas.second;
		reset();
		ans = min(ans, bfs(x,i));
	}
	if(ans == inf){
		printf("-1\n");
	}else{
		printf("%d\n",ans);
	}
	return 0;
};