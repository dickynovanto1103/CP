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
#define debug if(true)
typedef long long ll;
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

class Solution {
public:
	int dp[13][10001];
	vector<int> coins;
    int coinChange(vector<int>& coins, int amount) {
    	this->coins = coins;
    	memset(dp, -1, sizeof dp);
    	int res = solve(0, amount);
    	if(res >= inf) {
    		return -1;
    	}

    	return res;
    }

    int solve(int idx, int remaining) {
    	// printf("idx: %d, remaining: %d\n", idx, remaining);
    	if(remaining < 0) {return inf;}
    	if(remaining == 0) {return 0;}
    	if(idx == coins.size()) {return inf;}
    	if(dp[idx][remaining] != -1) {return dp[idx][remaining];}

    	// if(remaining < coins[idx]) {
    	// 	return dp[idx][remaining] = solve(idx + 1, remaining);
    	// }

    	int ans1 = 1 + solve(idx, remaining-coins[idx]);
    	int ans2 = solve(idx + 1, remaining);
    	return dp[idx][remaining] = min(ans1, ans2);
    }
};

void solve(){
	Solution sol;
	vector<int> coins = {1,2,5};
	printf("%d\n", sol.coinChange(coins, 11));
	coins = {2};
	printf("%d\n", sol.coinChange(coins, 3));
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};