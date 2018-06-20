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

ll dp[20][2];
int n,k;

ll solve(int idx, int isTerakhir0) {
	if(idx==(n+1)){return 1;}
	if(dp[idx][isTerakhir0] != -1){return dp[idx][isTerakhir0];}
	if(isTerakhir0){
		dp[idx][isTerakhir0] = ((ll)k-1LL)*solve(idx+1, 0);
	}else{
		dp[idx][isTerakhir0] = ((ll)k-1LL)*solve(idx+1,0) + solve(idx+1,1);
	}
	return dp[idx][isTerakhir0];
}

int main(){
	memset(dp,-1,sizeof dp);
	scanf("%d %d",&n,&k);
	dp[0][1] = 1;
	dp[0][0] = 1;
	ll ans = solve(1,1);
	printf("%lld\n",ans);
	return 0;
};