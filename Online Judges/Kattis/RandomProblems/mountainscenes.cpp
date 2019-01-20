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

const ll mod = 1e9 + 7;

ll dp[101][10001];
int n,w,h;

ll solve(int idx, int sisa) {
	if(idx == w) {
		if(sisa >= 0){return 1;}
		else{return 0;}
	}
	if(dp[idx][sisa] != -1) {
		return dp[idx][sisa];
	}
	ll ans = 0;
	for(int i=0;i<=min(sisa, h);i++) {
		ans += solve(idx+1, sisa - i);
		ans %= mod;
	}
	return dp[idx][sisa] = ans;
}

int main(){
	
	scanf("%d %d %d",&n,&w,&h);
	ll minus = 0;
	memset(dp, -1, sizeof dp);
	for(int i=0;i<=h;i++){
		if(w*i <= n){minus++;}
	}
	ll ans = solve(0, n);
	// printf("minus: %d\n",minus);
	ans -= minus;
	if(ans < 0){ans += mod;}
	printf("%lld\n",ans);
	return 0;
};