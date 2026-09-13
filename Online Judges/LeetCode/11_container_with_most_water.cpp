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
    int maxArea(vector<int>& height) {
    	int left = 0, right = height.size() - 1;
    	int ans = 0;
    	while(left < right) {
    		ans = max(ans, min(height[left], height[right]) * (right - left));
    		if(height[left] <= height[right]) {
    			left++;
    		}else{
    			right--;
    		}
    	}

    	return ans;
    }
};

void solve(){
	vector<int> v = {1,8,6,2,5,4,8,3,7};
	Solution sol;
	printf("%d\n",sol.maxArea(v));
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};