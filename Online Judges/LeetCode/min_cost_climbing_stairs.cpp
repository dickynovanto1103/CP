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
    int minCostClimbingStairs(vector<int>& cost) {
    	int dp[1000];
    	int n = cost.size();
    	dp[0] = cost[0]; dp[1] = cost[1];
    	for(int i=2;i<n;i++){
    		dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
    	}

    	return min(dp[n-1], dp[n-2]);
    }
};

int main(){
	int n;
	while(scanf("%d",&n) != EOF) {
		vi v(n);
		for(int i=0;i<n;i++){
			scanf("%d",&v[i]);
		}

		Solution sol;
		cout<<sol.minCostClimbingStairs(v)<<endl;
	}

	
	return 0;
};