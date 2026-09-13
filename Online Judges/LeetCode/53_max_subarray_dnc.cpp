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
	vi nums;
    int maxSubArray(vector<int>& nums){
    	this->nums = nums;
    	return solve(0, nums.size() - 1);
    }

    int solve(int left, int right) {
    	if(left == right) {
    		return nums[left];
    	}

    	int mid = (left + right) / 2;
    	int ans1 = solve(left, mid);
    	int ans2 = solve(mid + 1, right);
    	
    	int maxMid = nums[mid];
    	
    	int curAns = 0;
    	int maxMidToLeft = -inf;
    	for(int i=mid-1;i>=left;i--) {
    		curAns += nums[i];
    		maxMidToLeft = max(maxMidToLeft, curAns);
    	}
    	if(maxMidToLeft < 0) {maxMidToLeft = 0;}

    	curAns = 0;
    	int maxMidToRight = -inf;
    	for(int i=mid+1;i<=right;i++){
    		curAns += nums[i];
    		maxMidToRight = max(maxMidToRight, curAns);
    	}
    	if(maxMidToRight < 0) {maxMidToRight = 0;}
    	int ans = max(ans1, max(ans2, maxMid + maxMidToLeft + maxMidToRight));
    	// printf("left: %d right: %d ans: %d, ans1: %d, ans2: %d, ans tengah: %d\n", left, right, ans, ans1, ans2, maxMid + maxMidToLeft + maxMidToRight);
    	return ans;
    }
};

void solve(){
	Solution sol;
	vi a = {-2,1,-3,4,-1,2,1,-5,4};
	int ans = sol.maxSubArray(a);
	printf("%d\n", ans);
	a = {-1,-2};
	printf("%d\n", sol.maxSubArray(a));
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};