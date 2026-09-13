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
    	vi ans;
    	for(int i=0;i<=n;i++){
    		int cnt = 0;
    		for(int j=0;j<32;j++) {
    			if((1<<j) <= i && ((1<<j) & i)) {
    				cnt++;
    			}
    		}

    		ans.pb(cnt);
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
	vi ans = sol.countBits(5);
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