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
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    	set<int> s;
    	int n = nums.size();
        for(int i=0;i<n;i++){
        	if(nums[i] == key) {
        		for(int j=max(0, i-k); j <= min(n-1, i+k);j++){
        			s.insert(j);
        		}
        	}
        }
        set<int>::iterator it;
        vector<int> v;
        for(it=s.begin();it!=s.end();it++){
        	v.pb(*it);
        }
        return v;
    }
};

int main(){
	Solution s;

	
	return 0;
};