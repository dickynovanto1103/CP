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
    bool containsDuplicate(vector<int>& nums) {
  		unordered_map<int, bool> mapper;
  		for(int i=0;i<nums.size();i++){
  			if(mapper.find(nums[i]) != mapper.end()) {
  				return true;
  			}

  			mapper[nums[i]] = true;
  		}      

  		return false;
    }
};

void solve(){
	Solution sol;
	vi a = {1,2,3,1};
	int ans = sol.containsDuplicate(a);
	printf("%d\n", ans);
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};