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
const ll mod = 1e9 + 7;
ll dp[maxn], preSum[maxn];

int main(){
	int tc,k,i;
	int a,b;
	scanf("%d %d",&tc,&k);
	for(i=1;i<k;i++){dp[i] = 1;}
	for(i=1;i<k;i++){
		preSum[i] = dp[i] + preSum[i-1];
		preSum[i] %= mod;
	}
	dp[k] = 2;
	preSum[k] = dp[k] + preSum[k-1];
	preSum[k] %= mod;

	for(i=k+1;i<maxn;i++){
		dp[i] = dp[i-1] + dp[i-k];
		dp[i] %= mod;
	}
	for(i=k+1;i<maxn;i++){
		preSum[i] = preSum[i-1] + dp[i];
		preSum[i] %= mod;
	}

	while(tc--){
		scanf("%d %d",&a,&b);
		ll ans = preSum[b] - preSum[a-1];
		ans%=mod;
		if(ans<0){ans+=mod;}
		printf("%lld\n",ans);
	}

	return 0;
};