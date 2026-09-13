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
    int searchInsert(vector<int>& nums, int target) {
    	int left = 0, right = nums.size();
    	while(left < right) {
    		int mid = (left + right) / 2;
    		if(nums[mid] < target) {
    			left = mid + 1;
    		}else{
    			right = mid;
    		}
    	}

    	return left;
    }
};

void solve(){
	
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};