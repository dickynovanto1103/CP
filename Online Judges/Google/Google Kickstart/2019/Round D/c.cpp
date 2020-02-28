#include <bits/stdc++.h>

using namespace std;
#define inf 1e15
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

const int maxn = 1e5 + 5;

int c[maxn], x[maxn];

ll dp[101][101];

int n,k;

ll solve(int idx, int sisaK, int forbidden) {
	if(sisaK == 0){return 0;}
	if(idx >= n){
		return inf;
	}
	if(dp[idx][sisaK] != -1){return dp[idx][sisaK];}
	if(idx == forbidden){return solve(idx+1, sisaK, forbidden);}
	return dp[idx][sisaK] = min(solve(idx+1, sisaK, forbidden), c[idx] + abs(x[idx] - x[forbidden]) + solve(idx+1, sisaK-1, forbidden));
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d %d",&k,&n);
		for(i=0;i<n;i++){
			scanf("%d",&x[i]);
		}
		for(i=0;i<n;i++){
			scanf("%d",&c[i]);
		}
		ll minimCost = inf;
		for(i=0;i<n;i++){
			ll ans = c[i];
			memset(dp, -1, sizeof dp);
			ll jawab = solve(0, k, i);
			minimCost = min(minimCost, ans + jawab);
		}
		printf("%lld\n",minimCost);
	}
	return 0;
};