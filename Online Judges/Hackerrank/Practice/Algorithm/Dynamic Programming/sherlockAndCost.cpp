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

const int maxn = 1e5 + 5;
ll dp[maxn][2];

int main(){
	int tc,i,j,k;
	int n,b[maxn];
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){scanf("%d",&b[i]);}
		//reset dp
		for(i=1;i<=n;i++){
			for(j=0;j<=1;j++){
				dp[i][j] = 0;
			}
		}
		for(i=1;i<n;i++){
			for(j=0;j<2;j++){
				if(j==0){
					dp[i+1][0] = max(dp[i+1][0], dp[i][j]);
					dp[i+1][1] = max(dp[i+1][1], dp[i][j] + abs(1-b[i+1]));
				}else{
					dp[i+1][0] = max(dp[i+1][0], dp[i][j] + abs(1-b[i]));
					dp[i+1][1] = max(dp[i+1][1], dp[i][j] + abs(b[i+1]-b[i]));
				}		
			}
		}
		ll ans = 0;
		for(j=0;j<2;j++){
			ans = max(ans,dp[n][j]);
		}
		printf("%lld\n",ans);
	}
	return 0;
};