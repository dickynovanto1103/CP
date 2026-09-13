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
    vector<int> productExceptSelf(vector<int>& nums) {
    	vi ans(nums.size());

    	int curAns = 1;
    	for(int i=0;i<nums.size();i++){
    		ans[i] = curAns;
    		curAns *= nums[i];
    	}

    	curAns = 1;
    	for(int i=nums.size() - 1;i>=0;i--){
    		ans[i] *= curAns;
    		curAns *= nums[i];
    	}

    	return ans;
    }
};

void solve(){
	Solution sol;
	vi a = {1,2,3,4};
	vi ans = sol.productExceptSelf(a);
	for(int num: ans) {
		printf("%d ", num);
	}
	puts("");
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};