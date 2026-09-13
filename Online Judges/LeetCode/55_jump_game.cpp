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
    bool canJump(vector<int>& nums) {
  		int maxIdx = 0;
  		for(int i=0;i<nums.size();i++){
  			if(i > maxIdx) {
  				break;
  			}

  			maxIdx = max(maxIdx, i + nums[i]);
  			// printf("i: %d maxIdx: %d\n", i, maxIdx);
  		}   

  		return maxIdx >= (int)nums.size() - 1;
    }
};

void solve(){
	Solution sol;
	vector<int> v = {2,3,1,1,4};
	printf("%d\n", sol.canJump(v));

	v = {3,2,1,0,4};
	printf("%d\n", sol.canJump(v));

	v = {0};
	printf("%d\n", sol.canJump(v));
	v = {0,1};
	printf("%d\n", sol.canJump(v));
	v = {1,0};
	printf("%d\n", sol.canJump(v));
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};