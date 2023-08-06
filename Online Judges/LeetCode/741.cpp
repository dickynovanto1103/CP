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

int dp[601][301][301];

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        memset(dp, -1, sizeof dp);
        
        dr1 = {0,0,1,1};
        dr2 = {0,1,0,1};
        
        this->grid = grid;

        // printGrid();
        
        return max(solve(0,0,0), 0);
    }

    void printGrid() {
    	for(int i=0;i<n;i++){
    		for(int j=0;j<n;j++){
    			printf("%d ", grid[i][j]);
    		}
    		puts("");
    	}
    }
    
    int solve(int step, int r1, int r2) {
    	// printf("step: %d r1: %d, r2: %d\n", step, r1, r2);
        if(step == (n + n - 2)) {
            return grid[n-1][n-1];
        }

        int& ans = dp[step][r1][r2];
        if(ans != -1) return ans;

        ans = -inf;

        int tambah = grid[r1][getCol(step, r1)] + grid[r2][getCol(step, r2)];
        if(r1 == r2) {
        	tambah -= grid[r1][getCol(step, r1)];
        }

        for(int i=0;i<4;i++){
            int newR1 = r1 + dr1[i];
            int newR2 = r2 + dr2[i];
            int newC1 = getCol(step+1, newR1);
            int newC2 = getCol(step+1, newR2);
            
            if(newR1 < 0 || newR1 >= n || newC1 < 0 || newC1 >= n) {continue;}
            if(newR2 < 0 || newR2 >= n || newC2 < 0 || newC2 >= n) {continue;}

            if(grid[newR1][newC1] == -1) continue;
            if(grid[newR2][newC2] == -1) continue;
            
            ans = max(ans, tambah + solve(step+1, newR1, newR2));
        }
        
        return ans;
    }
    
    int getCol(int step, int row) {
        return step - row;
    }
    
private:
    vector<vector<int>> grid;
    int n;
    
    vector<int> dr1, dr2;
};

int main(){
	int n;
	while(cin>>n){
		vector<vi> v;
		for(int i=0;i<n;i++){
			vi temp(n);
			for(int j=0;j<n;j++){
				scanf("%d",&temp[j]);
			}
			v.pb(temp);
		}

		Solution sol;
		cout<<sol.cherryPickup(v)<<endl;
	}	
	
	return 0;
};

/*
3
0 1 -1
1 0 -1
1 1 1

3
1 1 -1
1 -1 1
-1 1 1
*/