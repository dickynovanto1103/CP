#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> AdjList;
vi dfs_num;
vi node;

void dfs(int awal){
	dfs_num[awal] = visited;
	for(int i=0;i<AdjList[awal].size();i++){
		int v = AdjList[awal][i];
		if(dfs_num[v]==unvisited){
			dfs(v);
		}
	}
	node.pb(awal);
}

int main() {
	int tc,m,i,j;
	ll n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%lld %d",&n,&m);
		AdjList.assign(n+1,vi());
		dfs_num.assign(n+1,unvisited);
		int a,b;
		for(i=0;i<m;i++){
			scanf("%d %d",&a,&b); AdjList[a].pb(b); AdjList[b].pb(a);
		}
		ll total = ((n)*(n-1))/2;
		for(i=1;i<=n;i++){
			if(dfs_num[i]==unvisited){
				node.clear();
				dfs(i);
				ll ukuran = (ll)node.size();
				total-=((ukuran)*(ukuran-1)/2);
			}
		}
		printf("%lld\n",total);

		AdjList.clear();
	}
	return 0;
}