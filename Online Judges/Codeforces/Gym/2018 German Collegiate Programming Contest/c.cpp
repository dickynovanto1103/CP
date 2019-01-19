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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vii> AdjList;

const int maxn = 1e3 + 3;

bool isVisited[maxn];

ll dp[maxn];

ll dfs(int node){
	int i;
	if(dp[node] != -1){return dp[node];}
	ll sum = 0;
	for(i=0;i<AdjList[node].size();i++){
		ii v = AdjList[node][i];
		int tetangga = v.first, berat = v.second;
		sum = max(sum, (ll)berat + dfs(tetangga));
	}
	return dp[node] = sum;
}

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	AdjList.assign(n+1, vii());
	for(i=0;i<m;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		AdjList[a].pb(ii(b,c));
	}
	memset(dp,-1, sizeof dp);
	memset(isVisited, false, sizeof isVisited);
	ll maks = 0;
	for(i=1;i<=n;i++){
		maks = max(maks, dfs(i));
	}
	printf("%lld\n",maks);
	return 0;
};