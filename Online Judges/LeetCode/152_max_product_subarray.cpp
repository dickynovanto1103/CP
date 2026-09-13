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
    int maxProduct(vector<int>& nums) {
  		int ans = nums[0];
  		int minim = ans, maximum = ans;
  		for(int i=1;i<nums.size();i++) {
  			int curMinim = min(nums[i] * minim, min(nums[i] * maximum, nums[i]));
  			int curMax = max(nums[i] * maximum, max(nums[i] * minim, nums[i]));
  			// printf("i: %d minim: %d maximum: %d\n", i, minim, maximum);
  			ans = max(ans, curMax);
  			minim = curMinim;
  			maximum = curMax;
  		}

  		return ans;
    }
};

void solve(){
	Solution sol;
	vi a = {2,3,-2,4};
	printf("%d\n", sol.maxProduct(a));
	a = {2,3,-2,-4};
	printf("%d\n", sol.maxProduct(a));
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};