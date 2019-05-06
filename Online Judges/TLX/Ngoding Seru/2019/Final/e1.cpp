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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const ll mod = 1e9 + 7;
ll dp[205][205][410];

int r,c;

void normalize(ll &a) {
	if(a < 0) {a+=mod;}
}

int main(){
	int k,i,j;
	// memset(dp, -1, sizeof dp);
	scanf("%d %d %d",&r,&c,&k);
	dp[1][1][k] = 1;
	if(k == 0){printf("1\n"); return 0;}
	for(i=1;i<=r;i++){
		for(j=1;j<=c;j++){
			if(i ==1 && j == 1){continue;}
			// dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1]) % mod;
			// dp[i][j][0] += (dp[i][j-1][0] + dp[i][j-1][1]) % mod;
			// dp[i][j][0]%=mod;
			if(i == r && j == c) {
				for(int l=0;l<=k;l++){
					dp[i][j][l] = (dp[i-1][j][l] + dp[i][j-1][l])%mod;
					dp[i][j][l] %= mod;
					dp[i][j][l] -= dp[i-1][j-1][l];
					normalize(dp[i][j][l]);
					// assert(dp[i][j][l]>=0);
					// printf("dp[%d][%d][%d]: %lld\n",i,j,l,dp[i][j][l]);
				}
			}else{
				for(int l=0;l<=k;l++){
					dp[i][j][l] = (dp[i-1][j][l] + dp[i-1][j][l+1])%mod;
					dp[i][j][l] += (dp[i][j-1][l] + dp[i][j-1][l+1])%mod;

					dp[i][j][l] %= mod;
					dp[i][j][l] -= dp[i-1][j-1][l]; normalize(dp[i][j][l]);
					dp[i][j][l] -= dp[i-1][j-1][l+1]; normalize(dp[i][j][l]);
					// assert(dp[i][j][l]>=0);
					// printf("dp[%d][%d][%d]: %lld\n",i,j,l,dp[i][j][l]);
				}
			}
			
		}
	}
	// printf("r: %d c: %d k: %d\n",r,c,k );
	printf("%lld\n",dp[r][c][0]);
	return 0;
};