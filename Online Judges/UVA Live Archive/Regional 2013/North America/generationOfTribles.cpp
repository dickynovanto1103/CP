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
	scanf("%d",&tc);
	ll dp[70];
	dp[0] = 1; dp[1] = 1; dp[2] = 2; dp[3] = 4;
	for(i=4;i<=67;i++){
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4];
	}
	while(tc--){
		int idx;
		scanf("%d",&idx);
		printf("%lld\n",dp[idx]);
	}
	return 0;
};