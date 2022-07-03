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
	int solve(int idx, int aRem, int bRem) {
		if(idx == sz){
			if(aRem == 0 && bRem == 0){
				return 0;
			}
			assert(false);
			return inf;
		}

		int &ans = dp[idx][aRem][bRem];
		if(ans != -1){
			return ans;
		}

		int ans1 = inf;
		if(aRem > 0) {
			ans1 = costs[idx][0] + solve(idx+1, aRem-1, bRem);
		}

		int ans2 = inf;
		if(bRem > 0) {
			ans2 = costs[idx][1] + solve(idx+1, aRem, bRem - 1);
		}

		return ans = min(ans1, ans2);
	}

	void printCosts() {
		printf("test printing vector\n");
    	for(int i=0;i<this->costs.size();i++){
    		for(int j=0;j<this->costs[i].size();j++){
    			printf("%d ", this->costs[i][j]);
    		}
    		puts("");
    	}
	}

    int twoCitySchedCost(vector<vector<int>>& costs) {
    	memset(dp, -1, sizeof dp);
    	for(vi cost: costs) {
    		this->costs.pb(cost);
    	}
    	
    	int sz = costs.size();
    	this->sz = sz;
    	
    	return solve(0, sz/2, sz/2);
    }

private:
	int dp[201][101][101];
	vector<vi> costs;
	int sz;
};

int main(){
	int n;
	while(scanf("%d",&n) != EOF){
		vector<vi> costs;
		for(int i=0;i<2*n;i++){
			vi a(2);
			for(int j=0;j<2;j++){
				scanf("%d",&a[j]);
			}
			costs.pb(a);
		}

		Solution sol;
		cout<<sol.twoCitySchedCost(costs)<<endl;
	}
		
	return 0;
};