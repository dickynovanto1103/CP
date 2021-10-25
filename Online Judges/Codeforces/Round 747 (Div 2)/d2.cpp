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
int col[200010];

void addEdge(int a, int b, int w) {
	adj[a].pb(ii(b, w)); adj[b].pb(ii(a, w));
}

bool isValid;
int cnt[2];

int n;

void dfs(int node) {
	if(!isValid) return;
	cnt[col[node]] += (node <= n);

	for(ii x : adj[node]){
		int v = x.first, w = x.second;
		if(col[v] == -1) {
			col[v] = col[node] ^ w;
			dfs(v);
		}else{
			//if w == 1, expected to be different ..if w == 1 && col[node] == col[v], then false, if w == 0 && col[node] != col[v]
			if(col[node] ^ w != col[v]) {
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
		adj.assign(n + 1, vii());
		fill(col, col+n + 1, -1);

		for(i=0;i<m;i++){
			int a,b;
			char s[10];
			scanf("%d %d %s", &a,&b,s);

			if(s[0] == 'i') {
				addEdge(a, b, 1);
			}else{
				addEdge(a, b, 0);
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