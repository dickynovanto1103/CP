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
	int dp[101][101];
    int minFallingPathSum(vector<vector<int>>& matrix) {
    	int row = matrix.size(), col = matrix[0].size();
        for(int j=0;j<col;j++){
        	dp[0][j] = matrix[0][j];
        }

        for(int i=1;i<row;i++){
        	for(int j=0;j<col;j++){
        		dp[i][j] = matrix[i][j] + min((j == 0 ? inf: dp[i-1][j-1]), min(dp[i-1][j], (j == (col - 1) ? inf: dp[i-1][j+1])));
        	}
        }

        int minim = inf;
        for(int j=0;j<col;j++){
        	minim = min(minim, dp[row-1][j]);
        }

        return minim;
    }
};

int main(){
	Solution s;
	vector<vector<int>> matrix;
	matrix.push_back({1, 2, 3});
	s.minFallingPathSum(matrix);
	return 0;
};