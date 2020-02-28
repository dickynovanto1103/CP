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

const int maxn = 1e5 + 5;
const ll mod = 1e9 + 7;

ll a[maxn];

vector<vi> adj;
vector<map<ll,int>> mapper;
void dfs(int node, int p) {
	// printf("node: %d\n",node);
	map<ll,int>::iterator it;
	map<ll, int> mapBaru;
	for(it=mapper[node].begin();it!=mapper[node].end();it++){
		ll bil = it->first;
		int cnt = it->second;
		// printf("bil; %lld cnt: %d\n", bil, cnt);
		ll gcd = __gcd(bil, a[node]);
		mapBaru[gcd] += cnt;
	}
	mapper[node] = mapBaru;
	mapBaru.clear();
	mapper[node][a[node]]++;
	for(int i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		if(v!=p){
			mapper[v] = mapper[node];
			dfs(v,node);
		}
	}
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	mapper.assign(n+1, map<ll,int>());
	adj.assign(n+1, vi());
	for(i=0;i<n-1;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		adj[x].pb(y); adj[y].pb(x);
	}
	dfs(1,-1);
	ll ans = 0;
	map<ll,int>::iterator it;
	for(i=1;i<=n;i++){
		for(it=mapper[i].begin();it!=mapper[i].end();it++){
			ll bil = it->first;
			ll cnt = it->second;
			ans += (bil%mod)*cnt%mod;
			ans %= mod;
		}
	}
	printf("%lld\n",ans);
	return 0;
};