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
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        dp[0][0][0] = grid[0][0];

        for(int r1=0;r1<n;r1++){
        	for(int r2=0;r2<m;r2++){
        		int step = i + j;
        		if(step == 0) continue;

        		dp[step][i][j] = 
        	}
        }
    }

private:
	int dp[101][51][51];
};

int main(){
	Solution sol;
	
	return 0;
};