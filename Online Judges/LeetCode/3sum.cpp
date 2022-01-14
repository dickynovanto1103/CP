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

        vi next(nums.size() + 1);

        sort(nums.begin(), nums.end());
        int len = nums.size();
        if(len > 0) {
            next[len-1] = len;
            for(int i=len-2;i>=0;i--){
                next[i] = (nums[i] == nums[i+1] ? next[i+1]: i+1);
            }    
        }
        
        vector<vi> v;

        for(int i=0;i<len;i = next[i]){
            for(int j=i+1;j<len;j = next[j]){
                
                int sum = nums[i] + nums[j];
                if(binary_search(nums.begin() + j+1, nums.end(), -sum)) {
                    vi a = {nums[i], nums[j], -sum};
                    v.pb(a);
                }
            }
        }

        return v;
    }
};

int main(){
    Solution s;
    vi a = {-1,0,1,2,-1,-4};
    vector<vi> ansList = s.threeSum(a);
    for(vi ans: ansList) {
        for(int a: ans) {
            printf("%d ", a);
        }
        puts("");
    }
    
    return 0;
};