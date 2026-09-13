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
	int dp[101];
    int rob(vector<int>& nums) {
  		memset(dp, 0, sizeof dp);
  		
  		dp[0] = nums[0];
  		//assume from starting from first house
  		for(int i=0;i<nums.size() - 1;i++){
  			dp[i] = nums[i];
  			for(int j=0;j<=i-2;j++){
  				dp[i] = max(dp[i], nums[i] + dp[j]);
  			}
  		}

  		int ans = 0;
  		for(int i=0;i<nums.size();i++){
  			ans = max(ans, dp[i]);
  		}

		memset(dp, 0, sizeof dp);
		for(int i=1;i<nums.size();i++){
			dp[i] = nums[i];
			for(int j=0;j<=i-2;j++){
				dp[i] = max(dp[i], nums[i] + dp[j]);
			}
		} 

		for(int i=0;i<nums.size();i++){
  			ans = max(ans, dp[i]);
  		}

  		return ans;
    }
};

void solve(){
	Solution sol;
	vi v = {2,3,2};
	printf("%d\n", sol.rob(v));
	v = {1,2,3,1};
	printf("%d\n", sol.rob(v));
	v = {1,2,3};
	printf("%d\n", sol.rob(v));
	v = {3};
	printf("%d\n", sol.rob(v));
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};