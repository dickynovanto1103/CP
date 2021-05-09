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

struct edge {
	ll price;
	int limit;
};

typedef pair<ll,ll> ii;
typedef pair<int,edge> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

vector<viii> adj;

int main(){
	int tc,i,j,n,q;
	scanf("%d",&tc);
	int l[1010];
	ll p[1010];
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d:",tt);
		scanf("%d %d",&n,&q);
		adj.assign(n+1, viii());
		for(i=0;i<n-1;i++){
			int x,y, limit;
			ll price;
			scanf("%d %d %d %lld",&x,&y,&limit, &price);
			l[i] = limit, p[i] = price;
			edge e;
			e.price = price;
			e.limit = limit;
			adj[x].pb(iii(y, e));
			adj[y].pb(iii(x, e));
		}

		ll dist[1010];

		while(q--){
			int start, w;
			scanf("%d %d",&start,&w);
			queue<int> q;
			q.push(start);
			memset(dist, -1, sizeof dist);
			dist[start] = 0;
			while(!q.empty()){
				int node = q.front(); q.pop();
				// printf("node: %d dist: %lld\n", node, dist[node]);
				for(int i=0;i<adj[node].size();i++){
					int v = adj[node][i].first;
					// printf("v: %d curr distv: %lld\n",v, dist[v]);
					if(dist[v] == -1) {
						edge e = adj[node][i].second;
						int limit = e.limit;
						ll price = e.price;	
						if(w >= limit) {
							dist[v] = __gcd(dist[node], price);
						}else{
							dist[v] = dist[node];
						}
						q.push(v);
					}
				}
			}

			assert(dist[1] != -1);
			printf(" %lld", dist[1]);
		}
		printf("\n");
	}
	
	return 0;
};