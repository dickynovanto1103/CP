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
    	vi ans(n+1);
    	ans[0] = 0;
    	for(int i=1;i<=n;i++){
    		ans[i] = (ans[i>>1] + (i&1));
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