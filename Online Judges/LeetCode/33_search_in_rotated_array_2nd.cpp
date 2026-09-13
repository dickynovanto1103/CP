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
    int search(vector<int>& nums, int target) {
     	int low = 0, high = nums.size() - 1, mid, ans = -1;
     	while(low <= high)    {
     		mid = (low + high) / 2;
     		//left sorted
     		if(nums[mid] == target) {
     			ans = mid;
     			break;
     		}else if(nums[low] <= nums[mid]) {
     			if(nums[low] <= target && target < nums[mid]) {
     				high = mid - 1;
     			}else{
     				low = mid + 1;
     			}
     		}else{ //right sorted
     			if(nums[mid] < target && target <= nums[high]) {
     				low = mid + 1;
     			}else{
     				high = mid - 1;
     			}
     		}
     	}

     	return ans;
    }
};

void solve(){
	Solution sol;
	vi a = {4,5,6,7,0,1,2};
	printf("%d\n", sol.search(a, 0));
	printf("%d\n", sol.search(a, 3));
	a = {3, 1};
	printf("%d\n", sol.search(a, 1));
	printf("%d\n", sol.search(a, 2));
	printf("%d\n", sol.search(a, 3));

	a = {1};
	printf("%d\n", sol.search(a, 1));
	printf("%d\n", sol.search(a, 0));
	printf("%d\n", sol.search(a, 2));

	a = {1, 2, 3};
	printf("%d\n", sol.search(a, 1));
	printf("%d\n", sol.search(a, 0));
	printf("%d\n", sol.search(a, 2));
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};