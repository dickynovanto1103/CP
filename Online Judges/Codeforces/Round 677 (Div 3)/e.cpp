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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ll fac[22];

int main(){
	ll dp[21][21];
	dp[1][1] = 1; dp[1][0] = 1;
	for(int i=2;i<=20;i++){
		for(int j=0;j<=i;j++){
			if(j == 0 || j == i){
				dp[i][j] = 1;
				// printf("%lld ",1);
			}else{
				dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
				// printf("%lld ",dp[i][j]);
			}
		}
		// printf("\n");
	}
	fac[0] = fac[1] = 1;
	for(int i=1;i<=20;i++){
		fac[i] = i * fac[i-1];
	}
	int n;
	while(scanf("%d",&n) != EOF){
		ll banyak = dp[n][n/2];
		// printf("n: %d now1: %lld\n",n, banyak);
		banyak *= fac[n/2];
		// printf("n: %d now2: %lld\n",n, banyak);
		banyak /= n;
		// printf("n: %d now2: %lld\n",n, banyak);
		banyak *= fac[n/2-1];
		// printf("n: %d now3: %lld\n",n, banyak);
		printf("%lld\n",banyak);	
	}
	

	
	return 0;
};