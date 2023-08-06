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


const int maxn = 200001;
ll pos[maxn];
bool vis[maxn];


vector<vii> adj;

void dfs(int node) {
	for(int i=0;i<adj[node].size();i++){
		ii tetangga = adj[node][i];
		int v = tetangga.first, w = tetangga.second;
		if(!vis[v]) {
			pos[v] = pos[node] + w;
			vis[v] = true;
			dfs(v);
		}
	}
}

tuple<int, int, int> tup[maxn];


int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int n,m;
		scanf("%d %d",&n,&m);
		adj.assign(n+1, vii());
		for(int i=1;i<=n;i++){
			pos[i] = -1;
			vis[i] = false;
		}

		for(int i=0;i<m;i++){
			int a,b,d;
			scanf("%d %d %d", &a, &b, &d);
			tup[i] = make_tuple(a, b, d);
			if(d < 0) {
				adj[b].pb(ii(a, -d));
				adj[a].pb(ii(b, d));
			}else{
				adj[a].pb(ii(b, d));
				adj[b].pb(ii(a, -d));
			}
		}

		for(int i=1;i<=n;i++){
			if(!vis[i]) {
				pos[i] = 0;
				vis[i] = true;
				dfs(i);
			}
		}

		bool valid = true;

		for(int i=0;i<m;i++){
			int a = get<0>(tup[i]);
			int b = get<1>(tup[i]);
			int w = get<2>(tup[i]);

			if(pos[b] != (pos[a] + w)) {
				valid = false;
				break;
			}
		}


		if(!valid) {
			puts("NO");
		}else{
			puts("YES");
		}

	}
	
	return 0;
};