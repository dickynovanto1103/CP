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
    int maxProfit(vector<int>& prices) {
        int minSoFar = prices[0];
        int ans = 0;
        for(int i=1;i<prices.size();i++){
        	ans = max(ans, prices[i] - minSoFar);
        	minSoFar = min(minSoFar, prices[i]);
        }

        return ans;
    }
};

void solve(){
	Solution sol;
	vi a = {7,1,5,3,6,4};
	int ans = sol.maxProfit(a);
	printf("%d\n", ans);
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};