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

const int maxn = 1e3 + 3;
const ll mod = 1e9 + 7;

string kata[4];
ll dp[4][maxn][4];
int n;

int solve(int row, int col, int sebelum){
	if(kata[row][col] == '#'){return 0;}
	if(row==2 && col == (n-1)){
		if(sebelum == 0){return 1;}
		else{return 0;}
	}
	if(row < 0){return 0;}
	if(row > 2 || col > (n-1)){return 0;}
	
	if(dp[row][col][sebelum] != -1){return dp[row][col][sebelum];}
	ll ans = 0;
	if(sebelum == 0 || sebelum == 1){
		ans += solve(row, col+1, 2);
		ans %= mod;
		ans += solve(row, col+1, 3);
		ans %= mod;
	}else if(sebelum == 2){
		ans += solve(row+1, col, 0);
		ans %= mod;
	}else if(sebelum == 3){
		ans += solve(row-1, col, 1);
		ans %= mod;
	}
	return dp[row][col][sebelum] = ans;
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d",&n);
		for(i=0;i<3;i++){cin>>kata[i];}
		memset(dp,-1,sizeof dp);
		ll ans = solve(0,0,2);
		printf("%lld\n", ans);
	}
	return 0;
};