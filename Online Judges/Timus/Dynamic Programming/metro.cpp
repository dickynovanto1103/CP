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

bool isDiagonal[1010][1010];
double dp[1010][1010];
int n,m;

int main(){
	int i,j;
	scanf("%d %d",&n,&m);
	int k;
	for(i=0;i<1010;i++){
		for(j=0;j<1010;j++){
			dp[i][j] = -1;
		}
	}
	scanf("%d",&k);
	memset(isDiagonal, false, sizeof isDiagonal);
	for(i=0;i<k;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		isDiagonal[x][y] = true;
	}
	dp[0][0] = 0;
	for(i=1;i<=n;i++){
		dp[i][0] = 1 + dp[i-1][0];
		// printf("dp[%d][%d] bernilai: %lf\n",i,m,dp[i][m]);
	}
	for(i=1;i<=m;i++){
		dp[0][i] = 1 + dp[0][i-1];
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			dp[i][j] = min(1 + dp[i-1][j], 1 + dp[i][j-1]);
			if(isDiagonal[i][j]) {
				dp[i][j] = min(dp[i][j], sqrt(2) + dp[i-1][j-1]);
			}
		}
	}
	
	double ans = dp[n][m]*100.0;
	// for(i=1;i<=n;i++){
	// 	for(j=1;j<=m;j++){
	// 		printf("%lf ",dp[i][j]);
	// 	}
	// 	printf("\n");
	// }
	ll jawab = round(ans);
	printf("%lld\n",jawab);
	return 0;
};