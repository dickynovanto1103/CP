#include <bits/stdc++.h>

using namespace std;
#define inf 1e18
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 402;

ll dp[maxn][maxn];

ll a[maxn];
ll pref[maxn];

ll price(int depan, int belakang) {
	if(depan > belakang){return 0;}
	return pref[belakang] - pref[depan-1];
}

ll solve(int depan, int belakang) {
	if(depan >= belakang) {
		return 0;
	}
	if(dp[depan][belakang] != -1){return dp[depan][belakang];}
	int i,j;
	ll ans = inf;
	for(i=depan;i<belakang;i++){
		ll ans2 = solve(depan, i) + solve(i+1, belakang) + price(depan, i) + price(i+1, belakang);
		ans = min(ans, ans2);
	}
	return dp[depan][belakang] = ans;
}

void min_self(ll &a, ll b){
	a = min(a,b);
}

int main(){
	int n,i,j;
	
	scanf("%d",&n);
	
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		pref[i] = a[i];
		pref[i] += pref[i-1];
	}
	memset(dp, -1, sizeof dp);
	
	printf("%lld\n",solve(1,n));

	// bottom up approach

	// for(i=1;i<=n;i++){
	// 	for(j=1;j<=n-i;j++){
	// 		int depan = j, belakang = j+i;
	// 		dp[depan][belakang] = inf;
	// 		for(int k=depan;k<belakang;k++){
	// 			min_self(dp[depan][belakang], price(depan, k) + price(k+1, belakang) + dp[depan][k] + dp[k+1][belakang]);
	// 			// printf("sekarang k: %d dp[%d][%d]: %lld, price: %lld %lld\n",k, depan, belakang, dp[depan][belakang], price(depan, k), price(k+1, belakang));	
	// 		}
	// 		// printf("dp[%d][%d]: %lld\n",depan, belakang, dp[depan][belakang]);
	// 	}
	// }
	return 0;
};