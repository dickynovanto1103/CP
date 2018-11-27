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

const int mod = 1988;
const int maxn = 5001;
int dp[maxn][maxn];
int n,k;

int solve(int idx, int sisa, int banyak){	
	if(idx == k){
		if(sisa == 0){return 1;}
		else{return 0;}
	}
	if(banyak > sisa){return 0;}

	if(dp[idx][banyak] != -1){return dp[idx][banyak];}

	int ans = 0;
	ans += solve(idx+1, sisa - banyak, banyak); //banyak computer tetap
	ans %= mod;
	ans += solve(idx+1, sisa - banyak, banyak + 1); //banyak computer naik satu
	ans %= mod;
	ans += solve(idx, sisa, banyak+1); //naikin banyaknya tapi ga dikurangi
	ans %= mod;

	return dp[idx][banyak] = ans;
}

int main(){
	
	while(scanf("%d %d",&n,&k), (n||k)){
		memset(dp,-1,sizeof dp);
		int ans = solve(0, n, 1);
		printf("%d\n",ans);
	}
	return 0;
};