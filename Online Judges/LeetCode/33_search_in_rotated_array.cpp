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
        int minIdx = findMinIdx(nums);
        int n = nums.size();
        int kiri = 0, kanan = n-1, ans = -1, mid;
        // printf("minIdx: %d\n", minIdx);
        while(kiri <= kanan) {
        	int mid = (kiri + kanan) / 2;
        	int real = realIdx(mid, minIdx, n);
        	// printf("mid: %d, kiri = %d, kanan: %d, real: %d\n", mid, kiri, kanan, real);
        	if(nums[real] < target) {
        		// printf("nums[%d]: %d < target: %d\n", real, nums[real], target);
        		kiri = mid + 1;
        	}else if(nums[real] > target) {
        		// printf("nums[%d]: %d > target: %d\n", real, nums[real], target);
        		kanan = mid - 1;
        	}else{
        		ans = mid;
        		// printf("enter here, ans: %d\n", ans);
        		break;
        	}
        }
        if(ans == -1) {
        	return -1;
        }

        return realIdx(ans, minIdx, n);
    }

    int realIdx(int idx, int offset, int n) {
    	return (idx + offset) % n;
    }

    int findMinIdx(vector<int>& nums) {
    	int n = nums.size();
    	if(nums.size() == 1) {return 0;}
    	if(nums[0] < nums[n - 1]) {
    		return 0;
    	}

    	int kiri = 0, kanan = n-1, ans = -1, mid;
    	while(kiri <= kanan) {
    		mid = (kiri + kanan) / 2;
    		// printf("kiri: %d kanan: %d mid: %d\n", kiri, kanan, mid);
    		if(nums[mid] >= nums[0]) {
    			kiri = mid + 1;
    		}else {
    			ans = mid;
    			kanan = mid - 1;
    		}
    	}
    	// printf("ans: %d\n", ans);

    	assert(ans != -1);
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

	a = {1};
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