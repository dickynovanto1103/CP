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
	ll pref[101][101];
	int n,m;
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    	n = matrix.size();
    	m = matrix[0].size();

    	calculatePrefixSum(matrix);
    	int ans = 0;
    	for(int i=0;i<n;i++){
    		for(int j=i;j<n;j++){
    			//focus row i till j, then calculate the sum
    			map<ll, int> cnt;
    			for(int col=0;col<m;col++){
    				ll totalValNow = getSum(i, j, col);
    				ans += cnt[totalValNow - target];
    				cnt[totalValNow]++;
    			}
    		}
    	}


    	return ans;
    }

    ll getSum(int row1, int row2, int col) {
    	return pref[row2][col] - (row1 > 0 ? pref[row1-1][col] : 0);
    }

    void calculatePrefixSum(vector<vector<int>>& matrix) {
    	for(int i=0;i<n;i++){
    		for(int j=0;j<m;j++){
    			pref[i][j] = matrix[i][j];
    			if(i > 0) {
    				pref[i][j] += pref[i-1][j];
    			}
    			if(j > 0) {
    				pref[i][j] += pref[i][j-1];
    			}
    			if(i > 0 && j > 0) {
    				pref[i][j] -= pref[i-1][j-1];
    			}
    		}
    	}
    }
};

int main(){
	

	return 0;
};