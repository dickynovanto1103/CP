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

const int maxn = 1e7 + 2;
const int mod = 1e9 + 7;
int dp[maxn][4];

int main(){
	int n,i,j;
	scanf("%d",&n);
	dp[0][3] = 1;
	for(i=1;i<=n;i++){
		for(j=0;j<4;j++){
			if(j == 0){
				dp[i][j] = (((dp[i-1][1] + dp[i-1][2])%mod) + dp[i-1][3])%mod;
			}else if(j==1){
				dp[i][j] = (((dp[i-1][0] + dp[i-1][2])%mod) + dp[i-1][3])%mod;
			}else if(j==2){
				dp[i][j] = (((dp[i-1][0] + dp[i-1][1])%mod) + dp[i-1][3])%mod;
			}else{
				dp[i][j] = (((dp[i-1][0] + dp[i-1][1])%mod) + dp[i-1][2])%mod;
			}
			
		}
	}
	printf("%d\n",dp[n][3]);
	return 0;
};