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

int n,k;
ll dp[2001][2001];
const ll mod = 1e9 + 7;
ll solve(int bil,int panjangSekarang) {
	if(panjangSekarang == k){return 1;}
	if(dp[bil][panjangSekarang] != -1){return dp[bil][panjangSekarang];}
	ll ans = 0;
	for(int i=bil;i<=n;i+=bil) {
		ans+=solve(i, panjangSekarang+1);
		ans%=mod;
	}
	return dp[bil][panjangSekarang] = ans;
}

int main(){
	int i,j;
	scanf("%d %d",&n,&k);
	memset(dp,-1,sizeof dp);
	ll ans = 0;
	for(i=1;i<=n;i++) {
		ans+=solve(i, 1);
		ans%=mod;
	}
	printf("%lld\n",ans);
	return 0;
};