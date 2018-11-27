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

const ll mod = 1e9 + 7;
const int maxn = 100;
int dp[maxn][maxn];

int main(){
	int n,i,j;
	int a[maxn];
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int idx = 0;
	dp[0][0] = 1;
	for(i=0;i<=n;i++){
		dp[i][0] = 1;
	}
	// dp[1][0] = 1;
	for(i=1;i<=n;i++){
		//copy semua nilai dp awal
		for(j=1;j<=n;j++){
			if(a[i]%j == 0){
				dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
			}else{
				dp[i][j] = dp[i-1][j];
			}
			printf("%d ",dp[i][j]);
		}
		printf("\n");
		
	}
	idx = 1-idx;
	int ans = 0;
	for(i=1;i<maxn;i++){
		ans += dp[n][i];
		printf("dp[%d][%d]: %d\n",n,i,dp[n][i]);
		ans %= mod;
	}
	printf("%d\n",ans);
	return 0;
};