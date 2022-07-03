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
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
        	int mid = (l + r) / 2;
        	if(nums[mid] < target) {
        		l = mid+1;
        	}else if(nums[mid] > target) {
        		r = mid-1;
        	}else{
        		return mid;
        	}
        }
        return -1;
    }
};

int main(){
	
	
	return 0;
};