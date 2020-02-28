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

int dp[201][201];
int a[201];

vector<vi> adj;
int k;

int solve(int node, int jarak, int p){
	int ans = 0;
	debug printf("node: %d jarak: %d p: %d\n",node, jarak,p);
	if(dp[node][jarak]!=-1){return dp[node][jarak];}
	for(int i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		// printf("node: %d v: %d\n",node,v);
		if(jarak <= k){

		}
		if(v!=p){
			process = true;
			if(jarak > k){
				ans += max(solve(v, jarak+1, node), a[node] + solve(v, 1, node));
			}else{
				ans += solve(v, jarak+1, node);
			}
		}
	}
	if(!process){
		if(jarak > k){
			ans += a[node];
		}
	}
	debug printf("node: %d jarak: %d p: %d ans: %d\n",node, jarak,p,ans);
	return dp[node][jarak] = ans;
}

int main(){
	int n,i,j;
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	adj.assign(n+1,vi());
	for(i=0;i<n-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a].pb(b); adj[b].pb(a);
	}
	int ans = 0;
	for(i=1;i<=n;i++){
		memset(dp, -1, sizeof dp);
		int jawab = a[i] + solve(i, 0,-1);
		ans = max(jawab, ans);
	}
	printf("%d\n",ans);
	return 0;
};