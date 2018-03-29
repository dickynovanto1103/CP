#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000000000000
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

const int maxn = 1e5 + 1;

ll a[maxn][3], p[maxn];
ll dp[maxn][4];

int main(){
	int n,i,j;
	for(i=0;i<maxn;i++) {
		for(j=0;j<4;j++){
			dp[i][j] = inf;
		}
	}
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%lld",&a[i][0]);}
	for(i=0;i<n;i++){scanf("%lld",&a[i][1]);}
	for(i=0;i<n;i++){scanf("%lld",&a[i][2]);}
	for(i=0;i<(n-1);i++){scanf("%lld",&p[i]);}
	dp[0][0] = a[0][0];
	dp[0][1] = a[0][1];
	dp[0][2] = a[0][2];
	for(i=1;i<n;i++){
		for(j=0;j<3;j++){
			// printf("i: %d j: %d\n",i,j);
			for(int k=0;k<3;k++) {
				// printf("k: %d\n",k);
				if(k==j){
					// printf("dp[%d][%d]: %lld\n",i,j,dp[i][j]);
					// ll lama = dp[i][j];
					dp[i][k] = min(dp[i][k], dp[i-1][j] + a[i][k]);
					// if(lama==dp[i][j]){
					// 	printf("tidak berubah\n"); continue;
					// }
					// printf("dp[%d][%d] jadi: %lld dari dp[%d][%d](%lld) + a[%d][%d] (%lld)\n",i,j,dp[i][j],i-1,j,dp[i-1][j],i,k,a[i][k]);
				}else{
					// printf("dp[%d][%d]: %lld\n",i,j,dp[i][j]);
					// ll lama = dp[i][j];
					dp[i][k] = min(dp[i][k], dp[i-1][j] + a[i][k] + p[i-1]);
					// if(lama==dp[i][j]){
					// 	printf("tidak berubah\n"); continue;
					// }
					// printf("dp[%d][%d] jadi: %lld dari dp[%d][%d](%lld) + a[%d][%d] (%lld) + p[%d](%lld)\n",i,j,dp[i][j],i-1,j,dp[i-1][j],i,k,a[i][k],i-1,p[i-1]);
				}
				
			}
			
		}
	}
	// printf("tabel:\n");
	// for(i=0;i<n;i++){
	// 	for(j=0;j<3;j++){
	// 		if(j){printf(" ");}
	// 		printf("%lld",dp[i][j]);
	// 	}
	// 	printf("\n");
	// }
	ll ans = inf;
	for(i=0;i<4;i++){
		ans = min(ans, dp[n-1][i]);
	}
	printf("%lld\n",ans);
	return 0;
};