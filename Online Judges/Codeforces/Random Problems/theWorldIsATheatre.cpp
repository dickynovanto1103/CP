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
	int i,j;
	int64_t dp[35][35];
	dp[1][0] = 1; dp[1][1] = 1;
	for(i=2;i<=30;i++){
		for(j=0;j<=i;j++){
			if(j==0 || j==i){
				dp[i][j] = 1;
			}else{
				dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
			}
		}
	}
	int n,m,t;
	scanf("%d %d %d",&n,&m,&t);
	int64_t ans = 0;
	for(i=4;i<=n;i++){
		int a = i, b = t-i;
		if(b>m){
			// printf("masuk sini\n");
			continue;
		}
		if(b<=0){break;}
		// printf("n: %d m: %d a: %d b: %d\n",n,m,a,b);
		ans+=(dp[n][a]*dp[m][b]);
	}
	//printf("halo\n");
	printf("%lld\n",ans);
	return 0;
};