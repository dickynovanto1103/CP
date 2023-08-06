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
    long long minCost(vector<int>& nums, vector<int>& cost) {
  		return ternary(nums, cost);
    }

    long long calculateCost(vi& nums, vi& cost, int target) {
    	ll sum = 0;
    	int sz = nums.size();
		for(int i=0;i<sz;i++){
			sum += (ll)cost[i] * (abs(nums[i] - target));
		}

		return sum;
    }

    long long ternary(vi& nums, vi& cost) {
    	int sz = nums.size();
    	int minim = inf, maks = 0;
    	for(int i=0;i<sz;i++) {
    		minim = min(minim, nums[i]);
    		maks = max(maks, nums[i]);
    	}

    	int lo = -1;
    	int hi = maks;
    	while(hi - lo > 1) {
    		int mid = (hi + lo) / 2;
    		if(calculateCost(nums, cost, mid) > calculateCost(nums, cost, mid + 1)) {
    			lo = mid;
    		}else{
    			hi = mid;
    		}
    		// printf("mid: %d, lo: %d, hi: %d\n", mid, lo, hi);
    	}

    	assert(lo > -1);
    	// printf("ketemu titik minimal di titik: %d\n", lo + 1);
    	return calculateCost(nums, cost, lo + 1);
    }

    long long bf(vi& nums, vi& cost) {
    	int sz = nums.size();
    	int minim = inf, maks = 0;
    	for(int i=0;i<sz;i++) {
    		minim = min(minim, nums[i]);
    		maks = max(maks, nums[i]);
    	}

    	ll minimCost = -1;
    	ll targetPas = 0;
    	for(int target=minim;target<=maks;target++){
    		ll sum = 0;
    		for(int i=0;i<sz;i++){
    			sum += (ll)cost[i] * (abs(nums[i] - target));
    		}
    		if(minimCost == -1) minimCost = sum;
    		minimCost = min(minimCost, sum);
    		if(minimCost == sum) {
    			targetPas = target;
    		}

    		printf("untuk capai target: %d, cost: %lld\n", target, sum);
    	}
    	printf("minimCost: %lld targetPas: %d\n", minimCost, targetPas);
    	return minimCost;
    }
};

int main(){
	int n;
	int tc = 0;
	while(scanf("%d",&n) != EOF) {
		cerr<<endl<<"processing tc: "<<++tc<<endl;
		vi nums(n), cost(n);
		for(int i=0;i<n;i++){
			scanf("%d",&nums[i]);
		}	
		for(int i=0;i<n;i++){
			scanf("%d",&cost[i]);
		}	

		Solution sol;
		printf("%lld\n", sol.minCost(nums, cost));
	}
	
	
	
	
	return 0;
};