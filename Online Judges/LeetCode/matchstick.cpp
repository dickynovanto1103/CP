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
    bool makesquare(vector<int>& matchsticks) {
    	v = matchsticks;
    	sz = v.size();

    	int sum = 0;
    	for(int val: v) sum += val;

    	if(sum % 4 != 0) return false;
    	sidesLen = sum / 4;

    	dp.clear();

    	return solve(0, 0);
    }

    bool solve(int sidesFormed, int mask) {
    	if(sidesFormed == 3) return true;

    	if(dp.find(ii(sidesFormed, mask)) != dp.end()) return dp[ii(sidesFormed, mask)];

    	int tot = 0;
    	for(int i=0;i<sz;i++){
    		if((1<<i) & mask) tot += v[i];
    	}

    	if(tot > 0 && tot % sidesLen == 0) {
    		int nowSides = tot / sidesLen;
    		if(nowSides == (sidesFormed + 1)) {
    			return solve(sidesFormed + 1, mask);
    		}
    	}

    	int maksStickLen = sidesLen - (tot % sidesLen);
    	bool ans = false;
    	for(int i=0;i<sz;i++){
    		if(!((1<<i) & mask) && v[i] <= maksStickLen) {
    			if(solve(sidesFormed, mask | (1<<i))) {
    				ans = true;
    				break;
    			}
    		}
    	}

    	return dp[ii(sidesFormed, mask)] = ans;
    }

private:
	vector<int> v;
	int sz;
	int sidesLen;
	map<ii, bool> dp;
};

int main(){
	Solution sol;
	int n;
	while(cin>>n){
		vi v(n);
		for(int i=0;i<n;i++){
			scanf("%d",&v[i]);
		}

		cout<<sol.makesquare(v)<<endl;
	}
	
	return 0;
};

/*
5
1 1 2 2 2

5
3 3 3 3 4

8
2 2 2 3 3 4 8 8

4
5 5 7 3

9
1 1 1 2 1 3 3 3 5

15
100 100 100 100 100 100 100 100 4 100 2 2 100 100 100
*/