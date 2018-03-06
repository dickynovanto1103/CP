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

const int maxn = 1e5 + 1;
const ll mod = 1e9 + 7;

int main(){
	ll dp[maxn];
	dp[2] = 1;
	ll i;
	for(i=3;i<maxn;i++){
		ll pengali = (i*(i-1))/2LL; pengali%=mod;
		dp[i] = dp[i-1]*pengali;
		dp[i] %= mod;
	}
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int idx;
		scanf("%d",&idx);
		printf("%lld\n",dp[idx]);
	}
	return 0;
};