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
map<ii, int> mapper;
map<ii, int>::iterator it;

void dfs(int node, int p, int langkah, int awal) {
	// printf("node: %d\n",node);
	if(langkah == 2){
		mapper[ii(awal, node)]++;
		return;
	}
	for(int i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		if(v != p){
			dfs(v, node, langkah+1, awal);
		}
	}
}

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	adj.assign(n+1,vi());
	for(i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a].pb(b);
	}
	for(i=1;i<=n;i++){
		dfs(i,-1,0,i);
	}
	ll ans = 0;
	for(it=mapper.begin();it!=mapper.end();it++){
		ii pas = it->first;

		int bil = it->second;
		// printf("%d %d %d\n",pas.first, pas.second,bil);
		ans += (bil)*(bil-1)/2LL;
	}
	printf("%lld\n",ans);
	return 0;
};