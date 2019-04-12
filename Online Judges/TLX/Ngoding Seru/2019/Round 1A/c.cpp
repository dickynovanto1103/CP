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

const ll mod = 1e9 + 7;

ll dp[1001][2001];

ll mul(ll a, ll b){
	return (ll)a*b % mod;
}

void add(ll &a, ll b){
	a += b;
	if(a >= mod){a -= mod;}
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[1011];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	dp[0][a[0]] = a[0];

	for(i=1;i<n;i++){
		int bil = a[i];
		dp[i][bil] = bil;
		for(j=0;j<=2000;j++){
			if(j == bil){continue;}
			int gcd = __gcd(bil, j);
			// dp[i][j] = dp[i][j-1];
			add(dp[i][gcd], mul(dp[i-1][j], bil));
		}
	}

	ll ans = 0;
	for(j=0;j<=2000;j++){
		add(ans, mul(dp[n-1][j],j));
	}
	int x = 1,y = 2;
	printf("dp[%d][%d]: %lld\n",x,y,dp[x][y]);

	printf("%lld\n",ans);
	return 0;
};