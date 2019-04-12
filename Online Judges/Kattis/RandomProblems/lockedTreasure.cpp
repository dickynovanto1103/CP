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

int main(){
	int tc,i,j;
	int a,b;
	scanf("%d",&tc);

	ll dp[35][35];
	dp[0][0] = 1;
	dp[1][0] = 1; dp[1][1] = 1;
	for(i=2;i<=30;i++){
		dp[i][0] = dp[i][i] = 1;
		for(j=1;j<i;j++){
			dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
			// printf("dp[%d][%d]: %lld\n",i,j,dp[i][j]);
		}
	}

	while(tc--){
		scanf("%d %d",&a,&b);
		b--;
		printf("%lld\n",dp[a][b]);
	}
	return 0;
};