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
    vector<int> countBits(int n) {
    	if(n == 0) {
    		return {0};
    	}

    	vi ans = {0,1};
    	int pastPower2Num = 1;
    	for(int i=2;i<=n;i++){
    		if(i - pastPower2Num == pastPower2Num) {
    			ans.pb(1);
    			pastPower2Num = i;
    			continue;
    		}
    		ans.pb(1 + ans[i-pastPower2Num]);
    	}

    	return ans;
    }
};

void printVector(vi v) {
	for(int num: v) {
		printf("%d ", num);
	}
	puts("");
}

void solve(){
	Solution sol;
	vi ans = sol.countBits(50);
	printVector(ans);
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};