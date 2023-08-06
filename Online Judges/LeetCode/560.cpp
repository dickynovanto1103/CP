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
    int subarraySum(vector<int>& nums, int k) {
        int pref[20001];
        unordered_map<int, vi> adj;
        for(int i=0;i<nums.size();i++){
            pref[i] = nums[i] + (i > 0 ? pref[i-1] : 0);
            adj[pref[i]].pb(i);
        }
        
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            int tambah = (i > 0 ? pref[i-1] : 0);
            vi temp = adj[k + tambah];
            int idx = lower_bound(temp.begin(), temp.end(), i) - temp.begin();
            ans += (temp.size() - idx);
        }
        
        return ans;
    }
};

int main(){
    int n,k;
    while(cin>>n>>k){
        vi v(n);
        for(int i=0;i<n;i++){
            scanf("%d",&v[i]);
        }

        Solution sol;
        cout<<sol.subarraySum(v, k)<<endl;
    }
    
    return 0;
};