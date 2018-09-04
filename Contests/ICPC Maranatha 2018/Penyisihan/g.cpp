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
int a[maxn];
int dp[maxn];

int n;

ll solve(int idx){
	// printf("n: %d\n",n);
	if(idx >= (n+1)){return 0;}
	if(dp[idx]!=-1){return dp[idx];}
	ll ans = a[idx];
	for(int i=2;i<=5;i++){
		ans = max(ans, ans + solve(idx+i));
	}
	return dp[idx] = ans;
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case %d :",tt);
		scanf("%d",&n);
		for(i=0;i<=(n+1);i++){dp[i] = 0; a[i] = 0;}
		
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		dp[1] = 0;
		
		for(i=2;i<=n+1;i++){
			dp[i] = a[i];
			// printf("i: %d\n",i);
			int ans = a[i];
			int temp = a[i];
			for(j=2;j<=4;j++){
				if(i-j <= 0){continue;}
				int jawab = temp;
				// printf("ans: %d\n",ans);

				ans = max(ans, jawab + dp[i-j]);
				// printf("ans jadi: %d\n",ans);
				// printf("i-j: %d a: %d dp[%d] jadi: %lld\n",i-j, a[i-j],i,dp[i]);
			}
			dp[i] = ans;
		}

		// for(i=1;i<=n;i++){
		// 	if(i>1){printf(" ");}
		// 	printf("%d",dp[i]);
		// }
		// printf("\n");
		int ans = 0;
		for(i=0;i<=(n+1);i++){
			ans = max(ans, dp[i]);
		}
		
		printf("%d\n",ans);
	}
	return 0;
};