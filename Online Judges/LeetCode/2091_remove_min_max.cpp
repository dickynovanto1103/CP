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
    int minimumDeletions(vector<int>& nums) {
    	int minIdx, maxIdx;
    	int minim = inf, maks = -inf;
    	int n = nums.size();
  		for(int i=0;i<n;i++){
  			if(minim > nums[i]) {
  				minim = nums[i];
  				minIdx = i;
  			}

  			if(maks < nums[i]) {
  				maks = nums[i];
  				maxIdx = i;
  			}
  		}

  		//delete from front:
  		int ans1 = max(minIdx, maxIdx) + 1;
  		// delete from back;
  		int ans2 = max(n - minIdx, n - maxIdx);
  		//delete from front and back;
  		int ans3 = min(minIdx, maxIdx) + 1 + min(n - minIdx, n - maxIdx);
  		return min(ans1, min(ans2, ans3));
    }
};

void solve(){
	Solution sol;
	vector<int> nums = {2,10,7,5,4,1,8,6};
	printf("%d\n", sol.minimumDeletions(nums));
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};