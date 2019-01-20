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

const int maxn = 1010;

ll a[maxn];
ll dp[maxn][maxn];
int n;

bool found = false;

ll solve(int idx, int langkah) {
	// printf("idx: %d langkah: %d n: %d\n",idx, langkah,n);
	if(idx == n){return 0;}
	if(dp[idx][langkah] != -1){return dp[idx][langkah];}
	ll ans = inf;

	if(idx+langkah <= n){
		ans = min(ans, a[idx+langkah] + solve(idx+langkah, langkah+1));
	}
	if(idx-langkah +1 >= 1 && idx > 1){
		ans = min(ans, a[idx-langkah + 1] + solve(idx-langkah + 1, langkah));
	}
	return dp[idx][langkah] = ans;
}

int main(){
	int i,j;
	scanf("%d",&n);

	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	memset(dp, -1, sizeof dp);
	ll ans = solve(1, 1);
	// for(i=1;i<n;i++){
	// 	printf("i: %d %lld\n",i,dp[1][i]);
	// }
	printf("%lld\n",ans);
	return 0;
};