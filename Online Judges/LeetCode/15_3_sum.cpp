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

    	set<tuple<int,int,int>> res;
    	set<tuple<int,int,int>>::iterator it;

    	for(int i=0;i<n;i++){
    		unordered_map<int,int> idxMapper;
    		for(int j=i+1;j<n;j++){
    			int sum = nums[i] + nums[j];
    			int match = -sum;
    			if(idxMapper.find(match) != idxMapper.end()) {
    				auto tup = make_tuple(nums[i], nums[j], match);
    				res.insert(tup);
    			}

    			idxMapper[nums[j]] = j;
    		}
    	}

    	vector<vi> ans;
    	for(auto [a,b,c]: res) {
    		ans.pb({a,b,c});
    	}

    	return ans;
    }
};

void solve(){
	Solution sol;
	vi input = {-1,0,1,2,-1,-4};
	vector<vi> ans = sol.threeSum(input);
	for(auto vecRes: ans) {
		printf("[");
		for(auto num: vecRes) {
			printf("%d ", num);
		}
		printf("]\n");
	}
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};