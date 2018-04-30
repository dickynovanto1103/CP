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

int n,k,d;
ll dp[101][2];
const ll mod = 1e9 + 7;

ll solve(int sisa, int sudahMinD) {
	int i,j;
	if(sisa<0){return 0;}
	if(dp[sisa][sudahMinD] != -1) { return dp[sisa][sudahMinD];}
	ll ans = 0;
	for(i=1;i<=k;i++){
		if(i>=d){ans+=solve(sisa-i,1); ans%=mod;}
		else{
			ans+=solve(sisa-i,sudahMinD);
			ans%=mod;
		}
	}
	return dp[sisa][sudahMinD] = ans;
}

int main(){
	int i,j;
	scanf("%d %d %d",&n,&k,&d);
	memset(dp,-1,sizeof dp);
	dp[0][0] = 0;
	dp[0][1] = 1;
	ll ans = solve(n,0);
	printf("%lld\n",ans);
	return 0;
};