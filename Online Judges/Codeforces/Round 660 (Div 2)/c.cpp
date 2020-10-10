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

int p[100010], h[100010];
ll dp[100010];
ll good[100010], bad[100010];

vector<vi> adj;
void findSubsize(int node, int par) {
	dp[node] = p[node];
	for(int i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		if(v != par){
			findSubsize(v, node);
			dp[node] += dp[v];
		}
	}
}

bool dfs(int node, int par) {
	bool valid = true;
	for(int i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		if(v != par) {
			// x + y = dp[v]
			// x - y = h[v]
			ll tambah = dp[v] + h[v];
			if(tambah % 2 == 1){
				valid = false;
				break;
			}
			ll x = tambah / 2LL;
			ll y = dp[v] - x;
			// printf("node: %d v: %d x: %lld y: %lld\n",node, v, x, y);
			if(x < 0 || y < 0){
				valid = false;
				break;
			}
			if(x <= good[node]){
				good[v] = x, bad[v] = y;
				// printf("good[%d]: %lld bad[%d]: %lld\n", v, good[v], v, bad[v]);
				valid = valid && dfs(v, node);
			}else{
				valid = false;
				break;
			}
		}
	}
	return valid;
}

bool validate(int node, int par) {
	bool valid = true;
	ll sumGood = 0, sumBad = 0;;
	for(int i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		if(v != par) {
			sumGood += good[v];
			sumBad += bad[v];
		}
	}
	if(sumGood > good[node] || (sumGood + sumBad + p[node]) != (good[node] + bad[node])) {
		valid = false;
		return valid;
	}else{
		for(int i=0;i<adj[node].size();i++){
			int v = adj[node][i];
			if(v != par) {
				valid = valid && validate(v, node);
			}
		}
	}
	return valid;
}

int main(){
	int tc,i,j,n,m;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&m);
		adj.assign(n+2,vi());
		for(i=1;i<=n;i++){
			scanf("%d",&p[i]);
			dp[i] = 0;
			good[i] = 0; bad[i] = 0;
		}
		for(i=1;i<=n;i++){
			scanf("%d",&h[i]);
		}
		for(i=0;i<n-1;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			adj[a].pb(b);
			adj[b].pb(a);
		}
		findSubsize(1, -1);
		// x + y = dp[v]
		// x - y = h[v]
		bool valid = true;
		ll tambah = dp[1] + h[1];
		// printf("tambah: %lld\n", tambah);
		ll hasilMod = tambah % 2;
		if(hasilMod < 0){hasilMod += 2;}
		if(hasilMod == 1){
			valid = false;
			printf("NO\n");
			continue;
		}
		ll x = tambah / 2LL;
		ll y = dp[1] - x;
		// printf("x: %lld y: %lld\n", x,y);
		if(x < 0 || y < 0){
			valid = false;
			printf("NO\n");
			continue;
		}
		good[1] = x, bad[1] = y;
		// printf("good: %d bad: %d\n",good[1], bad[1]);
		valid = valid && dfs(1, -1);
		valid = valid && validate(1, -1);
		printf("%s\n",valid ? "YES": "NO");
	}
	
	return 0;
};