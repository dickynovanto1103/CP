#include <bits/stdc++.h>

using namespace std;
#define inf 10000000000000LL
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
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

const int maxn = 55;

vector<vii> adj;
ll dist[maxn];

void resetDist() {
	for(int i=0;i<maxn;i++){
		dist[i] = inf;
	}
}

void dijkstra(int node) {
	priority_queue<ii, vii, greater<ii> > pq;
	dist[node] = 0;
	pq.push(ii(dist[node], node));
	int i,j;
	while(!pq.empty()) {
		ii front = pq.top(); pq.pop();
		ll jarak = front.first, u = front.second;
		if(jarak > dist[u]){continue;}
		for(i=0;i<adj[u].size();i++){
			ii v = adj[u][i];
			if(dist[v.first] > (dist[u] + v.second)) {
				dist[v.first] = dist[u] + v.second;
				pq.push(ii(dist[v.first], v.first));
			}
		}
	}
}

bool isMatched(int node) {
	int i,j;
	for(i=0;i<adj[node].size();i++){
		ii v = adj[node][i];
		ll tetangga = v.first, jarak = v.second;
		if(dist[tetangga] == jarak){

		}else{
			return false;
		}
	}
	return true;
}

int main(){
	int tc;

	int n,m,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d %d",&n,&m);
		adj.assign(maxn, vii());
		int x[maxn], y[maxn], z[maxn];
		for(i=0;i<m;i++){
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			x[i] = a, y[i] = b, z[i] = c;
			adj[a].pb(ii(b,c));
			adj[b].pb(ii(a,c));
		}

		bool valid = true;

		for(i=1;i<=n;i++){
			if(adj[i].size()){
				resetDist();
				dijkstra(i);
				if(!isMatched(i)){
					valid = false;
					break;
				}
			}
		}
		if(!valid){printf("Impossible\n");}
		else{
			printf("%d\n",m);
			for(i=0;i<m;i++){
				printf("%d %d %d\n",x[i], y[i], z[i]);
			}
		}
		adj.clear();
	}
	return 0;
};