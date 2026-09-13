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
    int longestConsecutive(vector<int>& nums) {
    	unordered_set<int> s(nums.begin(), nums.end());
    	int ans = 0;
    	for(int num: s) {
    		if(!s.count(num - 1)) {
    			//this is the starting
    			int length = 1;
    			int cur = num;
    			while(s.count(cur + 1)) {
    				length++;
    				cur++;
    			}

    			ans = max(ans, length);
    		}
    	}
    	


  		return ans;
    }
};

void solve(){
	int n;
	while(scanf("%d",&n) != EOF) {
		vi v;
		for(int i=0;i<n;i++){
			int num;
			scanf("%d",&num);
			v.pb(num);
		}

		Solution sol;
		printf("%d\n", sol.longestConsecutive(v));
	}
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};