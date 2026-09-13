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
    int lengthOfLIS(vector<int>& nums) {
        vector<int> list;
        for(int i=0;i<nums.size();i++){
            auto it = lower_bound(list.begin(), list.end(), nums[i]);
            
            if(it == list.end()) {
                list.pb(nums[i]);
            }else{
                *it = nums[i];
            }
        }

        return list.size();
    }
};

void solve(){
    Solution sol;
    vector<int> v = {0,1,0,3,2,3};
    //0
    // 0 1
    // 0 0
    // 0 0 3
    // 0 0 2
    // 0 0 2 3

    printf("%d\n",sol.lengthOfLIS(v));
    // 0
    // 0 1 -> kalo lower bound ternyata end -> add lgsg
    // 0 1
    // 0 1 3
    // 0 1 2 
    // 0 1 2 3

    //v = {100, 101, 102, 0, 1, 500}
    // 100
    // 100 101
    // 100 101 102
    // 0 101 102
    // 0 1 102
    // 0 1 102 500


    v = {7,7,7};
    printf("%d\n",sol.lengthOfLIS(v));
}

int main(){
    int tc = 1;
    // scanf("%d",&tc);
    while(tc--){
        solve();
    }

    return 0;
};