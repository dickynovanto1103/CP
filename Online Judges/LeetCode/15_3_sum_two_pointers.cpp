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
    vector<vector<int>> threeSum(vector<int>& nums) {
    	int n = nums.size();
    	sort(nums.begin(), nums.end());

    	vector<vi> res;

    	for(int i=0;i<n;i++){
    		if(i > 0 && nums[i] == nums[i-1]) {
    			continue;
    		}

    		int num = nums[i];
    		int expected = -num;
    		//two pointer 2 sum
    		int left = i+1, right = n-1;
    		while(left < right) {

    			int sum = nums[left] + nums[right];
    			// printf("i: %d, left: %d right: %d, sum = %d, expected: %d\n", i, left, right);
    			if(sum == expected) {
    				if(!res.empty() && res.back() == vector<int>{num, nums[left], nums[right]}) {
    					left++;
    					right--;
    					continue;
    				}

    				res.pb({num, nums[left], nums[right]});
    				left++;
    				right--;
    			}else if(sum < expected) {
    				left++;
    			}else{
    				right--;
    			}
    		}
    	}

    	return res;
    }
};

void printRes(vector<vi> ans) {
	for(auto vecRes: ans) {
		printf("[");
		for(auto num: vecRes) {
			printf("%d ", num);
		}
		printf("]\n");
	}
}

void solve(){
	Solution sol;
	vi input = {-1,0,1,2,-1,-4};
	vector<vi> ans = sol.threeSum(input);
	printRes(ans);
	input = {1,2,0,1,0,0,0,0};
	ans = sol.threeSum(input);
	printRes(ans);


}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};