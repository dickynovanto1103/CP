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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 5e2 + 3;

int main(){
	ll dp[maxn][maxn];
	int i,j;
	ll cnt[maxn];
	memset(cnt, 0, sizeof cnt);
	dp[0][0] = 1;
	for(i=1;i<maxn;i++){
		for(j=0;j<=i;j++){
			if(j == 0 || j == i){
				dp[i][j] = 1;
			}else{
				dp[i][j] = dp[i-1][j-1] + dp[i-1][j] % 7LL;
			}
		}
	}
	for(i=1;i<maxn;i++){
		printf("i: %d\n",i);
		for(j=0;j<=i;j++){
			printf("%lld ",dp[i][j]);
		}
		printf("\n");
	}

	for(i=0;i<maxn;i++){
		for(j=0;j<=i;j++){
			if(dp[i][j] % 7 == 0){
				// cnt[i]++;
			}else{
				cnt[i]++;
			}
		}
		printf("cnt[%d]: %lld\n",i, cnt[i]);
	}

	for(i=1;i<maxn;i++){
		cnt[i] += cnt[i-1];
		printf("%lld, ",cnt[i]);
		// printf("ans[%d]: %lld\n",i, cnt[i]);
	}


	return 0;
};