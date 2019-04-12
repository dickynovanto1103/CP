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

int dp[100001][11];

const ll mod = 1e9 + 7;

void add(ll &a, ll b){
	a += b;
	if(a >= mod) {a-=mod;}
}

ll mul(ll a, ll b){
	return a*b %mod;
}

int n,k;

ll solve(int tinggi, int banyak) {
	if(tinggi == n){
		return banyak == 1;
	}
	if(dp[tinggi][banyak] != -1){return dp[tinggi][banyak];}
	ll ans = mul(solve(tinggi + 1, banyak), 2);
	if(banyak == 0){
		add(ans, 1);
	}
	for(int i=0;i<=banyak;i++){
		add(ans, mul(solve(tinggi+1, i), solve(tinggi + 1, banyak - i)));
	}
	return dp[tinggi][banyak] = ans;
}

int main(){
	int i,j;
	scanf("%d %d",&n,&k);
	memset(dp, -1, sizeof dp);
	printf("%lld\n",solve(1, k));
	return 0;
};