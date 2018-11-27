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

int n,totalWeight;
const int maxn = 51;
int val[maxn], weight[maxn];
int dp[maxn][1001];

int solve(int idx, int sisaBerat){
	if(idx == n){
		return 0;
	}
	if(dp[idx][sisaBerat]!=-1){return dp[idx][sisaBerat];}
	if(sisaBerat < weight[idx]){return solve(idx+1, sisaBerat);}
	return dp[idx][sisaBerat] = max(solve(idx+1, sisaBerat), val[idx] + solve(idx+1, sisaBerat - weight[idx]));
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&totalWeight, &n);
		for(i=0;i<n;i++){scanf("%d %d",&weight[i], &val[i]);}
		memset(dp, -1, sizeof dp);
		int ans = solve(0, totalWeight);
		printf("Hey stupid robber, you can get %d.\n",ans);
	}
	return 0;
};