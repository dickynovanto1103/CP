#include <bits/stdc++.h>

using namespace std;
#define inf 10000000000000LL
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

const int maxn = 2e4 + 2;
ll dp[maxn][51];
ll mod,n;
ll a[maxn];

ll solve(int idx, int sisa, int idxSebelum) {
	if(idx==(n+1)){
		if(sisa==1){
			printf("idxSebelum: %d masuk sini\n",idxSebelum);
			return 0;
		}
		else{return -inf;}
	}

	if(sisa==1){return dp[idx][sisa] = max(dp[idx][sisa], dp[idxSebelum][sisa] + (a[idx] + solve(idx+1,sisa, idxSebelum)%mod));}

	if(dp[idx][sisa]!=-1){return dp[idx][sisa];}

	
	ll ans1 = dp[idx][sisa-1] = dp[idxSebelum][sisa] + (a[idx] + solve(idx+1, sisa-1, idx))%mod; //bikin partisi baru
	ll ans2 = dp[idxSebelum][sisa] + (a[idx] + solve(idx+1, sisa, idxSebelum))%mod; // ga bikin partisi baru
	if(ans1 >= ans2 && ans1 >= dp[idx][sisa]){
		dp[idx][sisa-1] = ans1;
	}
	return dp[idx][sisa] = max(dp[idx][sisa], max(ans1,ans2));

}

int main(){
	memset(dp,-1,sizeof dp);
	int k,p;
	int i,j;
	
	scanf("%lld %d %d",&n,&k,&p);
	mod = (ll)p;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}

	for(i=0;i<=k;i++){
		dp[0][i] = 0;
	}
	
	solve(1, k, 0);
	printf("%lld\n",dp[1][k]);
	return 0;
};