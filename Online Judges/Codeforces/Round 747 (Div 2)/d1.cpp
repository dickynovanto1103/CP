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
int col[700010];

void addEdge(int a, int b) {
	adj[a].pb(b); adj[b].pb(a);
}

bool isValid;
int cnt[2];

int n;

void dfs(int node) {
	if(!isValid) return;
	cnt[col[node]] += (node <= n);

	for(auto v : adj[node]){
		if(col[v] == -1) {
			col[v] = 1 - col[node];
			dfs(v);
		}else{
			if(col[node] == col[v]) {
				isValid = false;
				return;
			}
		}
	}
}

int main(){
	int tc,i,j,m;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&m);
		adj.assign(n + m + 1, vi());
		int node_ext = n + 1;
		fill(col, col+n + m+1, -1);

		for(i=0;i<m;i++){
			int a,b;
			char s[10];
			scanf("%d %d %s", &a,&b,s);

			if(s[0] == 'i') {
				addEdge(a, b);
			}else{
				addEdge(a, node_ext);
				addEdge(node_ext, b);
				node_ext++;
			}
		}

		isValid = true;
		int ans = 0;

		for(i=1;i<=n;i++){
			if(col[i] == -1) {
				col[i] = 0;
				cnt[0] = cnt[1] = 0;
				dfs(i);
				ans += max(cnt[0], cnt[1]);
				if(!isValid){break;}
			}
		}
		if(!isValid){puts("-1"); continue;}

		printf("%d\n", ans);

	}
	
	return 0;
};