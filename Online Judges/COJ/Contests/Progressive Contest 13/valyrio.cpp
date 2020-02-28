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

const ll mod = 1e9 + 7;

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		int c,v,l,k;
		ll dp[510][2];
		bool valid = false;
		scanf("%d %d %d %d",&c,&v,&l,&k);
		memset(dp, 0, sizeof dp);
		dp[1][0] = c; dp[1][1] = v;
		for(i=2;i<=l;i++){
			dp[i][0] = (dp[i-1][1])*(c);

			if(dp[i][0] >= k){valid = true;}
			dp[i][0] %= mod;
			dp[i][1] = (dp[i-1][0] + dp[i-1][1])*v;
			if(dp[i][1] >= k){valid = true;}
			dp[i][1] %= mod;
		}
		ll ans = dp[l][1];
		ans %= mod;
		printf("%lld %s\n",ans,(valid? "Accepted": "Rejected") );
	}
	return 0;
};