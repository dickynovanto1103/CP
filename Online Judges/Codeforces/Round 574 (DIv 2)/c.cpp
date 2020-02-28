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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

ll dp[2][maxn];
ll maks[2][maxn];

int main(){
	int n,i,j;
	scanf("%d",&n);
	int h[2][maxn];
	for(i=0;i<2;i++){
		for(j=0;j<n;j++){
			scanf("%d",&h[i][j]);
		}
	}

	dp[0][0] = h[0][0];
	dp[1][0] = h[1][0];
	maks[0][0] = dp[0][0];
	maks[1][0] = dp[1][0];
	ll ans = max(dp[0][0], dp[1][0]);
	for(j=1;j<n;j++){
		for(i=0;i<2;i++){
			dp[i][j] = maks[1-i][j-1] + h[i][j];
			maks[i][j] = max(maks[i][j-1], dp[i][j]);
			ans = max(ans, dp[i][j]);
		}
	}
	printf("%lld\n",ans);

	return 0;
};