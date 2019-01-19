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

const int maxn = 1e5 + 5;

vector<vi> AdjList;

int dp[maxn];

int solve(int idx) {
	int i,j;
	if(dp[idx] != -1){return dp[idx];}
	int ans = 1;
	for(i=0;i<AdjList[idx].size();i++){
		int v = AdjList[idx][i];
		ans = max(ans, 1 + solve(v));
	}
	return dp[idx] = ans;
}

int main(){
	AdjList.assign(maxn, vi());
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	int indeg[maxn];
	memset(indeg, 0, sizeof indeg);
	for(i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		AdjList[a].pb(b);
		indeg[b]++;
	}
	int ans = 0;
	memset(dp, -1, sizeof dp);
	for(i=1;i<=n;i++){
		if(indeg[i] == 0){
			ans = max(ans, solve(i));
		}
	}

	// for(i=1;i<=n;i++){
	// 	printf("dp[%d]: %d\n",i,dp[i]);
	// }

	printf("%d\n",ans-1);
	return 0;
};