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
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;
int dp[101][6011],n;
ll w[maxn];

int solve(int idx, int sisa, int cnt) {
	if(idx==n){return 0;}
	if(sisa==0){return 0;}
	if(sisa < w[idx]){return solve(idx+1, sisa, cnt);}
	if(dp[idx][sisa]!=-1){return dp[idx][sisa];}
	if(cnt==0){
		return dp[idx][sisa] = max(solve(idx+1, sisa, cnt), 1 + solve(idx+1, 6*w[idx], cnt+1));	
	}else{
		return dp[idx][sisa] = max(solve(idx+1, sisa, cnt), 1 + solve(idx+1, min(6*w[idx], sisa - w[idx]), cnt+1));	
	}
	
}

int main(){
	int tc,i,j;
	
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){

		printf("Case #%d: ",tt);
		scanf("%d",&n);
		ll maks = 0;
		for(i=0;i<n;i++){scanf("%lld",&w[i]); maks = max(maks, w[i]);}
		reverse(w,w+n);
		
		memset(dp,-1,sizeof dp);
		int ans = solve(0, maks, 0);
		printf("%d\n",ans);
	}
	return 0;
};