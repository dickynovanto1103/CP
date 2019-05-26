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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> AdjList;
const int maxn = 1e4 + 4;
ll cost[maxn];
ll maksCost[maxn];
ll ans = 0;
ll k;

void dfs(int node, int p) {
	int i,j;
	maksCost[node] = cost[node];

	for(i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		if(v != p) {
			dfs(v, node);
			if(maksCost[node] < (cost[node] + maksCost[v])) {
				maksCost[node] = (cost[node] + maksCost[v]);
			}
		}
	}

	if(maksCost[node] > k) {
		ans += (maksCost[node] - k)*2LL;
		maksCost[node] = k;
	}
}

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	while(tc--){
		ans = 0;
		int x;
		scanf("%d %d %lld",&n,&x,&k);
		for(i=1;i<=n;i++){
			scanf("%lld",&cost[i]);
		}
		AdjList.assign(n+1, vi());
		for(i=0;i<n-1;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			AdjList[a].pb(b); AdjList[b].pb(a);
		}

		dfs(x,-1);
		if(ans < 0){ans = 0;}
		printf("%lld\n",ans);
		AdjList.clear();
	}
	return 0;
};