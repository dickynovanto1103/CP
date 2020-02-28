#include <bits/stdc++.h>

using namespace std;
#define inf 100000000000000000LL
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		int n;
		scanf("%d",&n);
		vi a(n), b(n);
		ll dp[n+1][4];
		
		for(i=0;i<n;i++){
			for(j=0;j<4;j++){
				dp[i][j] = inf;
			}
		}
		for(i=0;i<n;i++){
			scanf("%d %d",&a[i],&b[i]);
		}
		for(i=0;i<4;i++){
			dp[0][i] = (ll)b[0]*i;
		}
		// printf("dp[0]\n");
		for(i=1;i<n;i++){
			for(j=0;j<4;j++){
				int sebelum = a[i-1] + j;
				for(int k=0;k<4;k++){
					//tambah k..compare dengan j yg sebelum
					int sekarang = a[i] + k;
					if(sekarang == sebelum){continue;}
					dp[i][k] = min(dp[i][k], dp[i-1][j] + (ll)k*b[i]);
					// printf("j: %d dp[%d][%d]: %lld\n",j,i,k,dp[i][k]);
				}
			}
		}
		ll ans = inf;
		for(i=0;i<4;i++){
			ans = min(ans, dp[n-1][i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
};