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

bool grid[1001][1001];

class Solution {
public:
	bool isArtifactFound(int r1, int c1, int r2, int c2) {
		for(int i=r1;i<=r2;i++){
			for(int j=c1;j<=c2;j++){
				if(!grid[i][j]) {return false;}
			}
		}
		return true;
	}

    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
    	for(int i=0;i<n;i++){
    		for(int j=0;j<n;j++){
    			grid[i][j] = false;
    		}
    	}
    	
        int ans = 0;
        int nDig = dig.size();
        for(int i=0;i<nDig;i++){
        	vi koor = dig[i];
        	int r = koor[0], c = koor[1];
        	grid[r][c] = true;
        }

        for(int i=0;i<artifacts.size();i++){
        	vi art = artifacts[i];
        	if(isArtifactFound(art[0], art[1], art[2], art[3])) {
        		ans++;
        	}
        }

        return ans;
    }
};

int main(){
	Solution s;
	vector<vi> artifacts = 
	printf("%d\n", s.digArtifacts(6, vector<>));
	
	return 0;
};