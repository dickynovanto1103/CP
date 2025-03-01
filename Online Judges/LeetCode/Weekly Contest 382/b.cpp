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
	ll maxSqrt = ll(sqrt(inf));
    int maximumLength(vector<int>& nums) {
    	int ans = 1;
    	map<int, int> cntMap;
    	int n = nums.size();
        for(int i=0;i<n;i++) {
        	cntMap[nums[i]]++;
        }

        for(int i=0;i<n;i++){
        	ll x = nums[i];
        	int now = 1;
        	if(x == 1) {
        		int cnt = cntMap[1];
        		if(cnt % 2 == 0) {
        			cnt--;
        		}
        		ans = max(ans, cnt);
        	}
        	while(x <= maxSqrt) {
        		if(cntMap[x*x] >= 1 && cntMap[x] >= 2) {
        			x *= x;
        			now += 2;
        			ans = max(ans, now);
        		}else{
        			break;
        		}
        	}
        }

        return ans;
    }
};

// void solve(){
	
// }

int main(){
	// int tc = 1;
	// scanf("%d",&tc);
	// while(tc--){
	// 	solve();
	// }

	Solution s;
	int n;
	while(scanf("%d",&n)!=EOF) {
		vi a;
		for(int i=0;i<n;i++){
			int bil;
			scanf("%d",&bil);
			a.pb(bil);
		}

		int ans = s.maximumLength(a);
		printf("%d\n", ans);
	}

	return 0;
};