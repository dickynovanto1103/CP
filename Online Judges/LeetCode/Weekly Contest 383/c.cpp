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

int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

class Solution {
public:
	

    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
    	vector<vector<vector<int>>> temp(image.size(), vector<vector<int>>(image[0].size(), vector<int>()));

    	int n = image.size();
    	int m = image[0].size();
        for(int i=0;i<=n-3;i++){
        	for(int j=0;j<=m-3;j++){
        		if(isRegionValid(image, i, j, threshold)) {
        			int avgVal = getAvgValue(image, i, j);
        			// printf("region valid, i: %d j: %d avgVal: %d\n", i, j, avgVal);
        			fillAvgInResult(temp, avgVal, i, j);
        		}
        	}
        }

        vector<vector<int>> res(n, vector<int>(m, -1));


        return combineAllResultsInTempToRes(image, temp, res);
    }

    vector<vector<int>> combineAllResultsInTempToRes(vector<vector<int>>& image, vector<vector<vector<int>>>& temp, vector<vector<int>>& res) {
    	int n = image.size();
    	int m = image[0].size();
    	for(int i=0;i<n;i++){
    		for(int j=0;j<m;j++){
    			if(temp[i][j].size() == 0) {
    				res[i][j] = image[i][j];
    				continue;
    			}

    			int sumOfTemp = 0;
    			for(int num: temp[i][j]) {
    				sumOfTemp += num;
    			}
    			res[i][j] = sumOfTemp / temp[i][j].size();
    		}
    	}

    	return res;
    }

    void fillAvgInResult(vector<vector<vector<int>>>& res, int avg, int startRow, int startCol) {
    	int endRow = startRow + 2;
    	int endCol = startCol + 2;

    	int sum = 0;
    	for(int i=startRow;i<=endRow;i++) {
    		for(int j=startCol;j<=endCol;j++){
    			res[i][j].pb(avg);
    		}
    	}
    }

    int getAvgValue(vector<vector<int>>& image, int startRow, int startCol) {
    	int endRow = startRow + 2;
    	int endCol = startCol + 2;

    	int sum = 0;
    	for(int i=startRow;i<=endRow;i++) {
    		for(int j=startCol;j<=endCol;j++){
    			sum += image[i][j];
    		}
    	}

    	return sum / 9;
    }

    bool isRegionValid(vector<vector<int>>& image, int startRow, int startCol, int threshold) {
    	int endRow = startRow + 2;
    	int endCol = startCol + 2;

    	for(int i=startRow;i<=endRow;i++) {
    		for(int j=startCol;j<=endCol;j++){
    			for(int k=0;k<4;k++){
    				int newRow = i + dr[k], newCol = j + dc[k];
    				if(newRow >= startRow && newRow <= endRow && newCol >= startCol && newCol <= endCol) {
    					if(abs(image[i][j] - image[newRow][newCol]) > threshold) {
    						return false;
    					}
    				}
    			}
    		}
    	}

    	return true;
    }



};

void solve(){

}

void printRes(vector<vector<int>> res) {
	for(int i=0;i<res.size();i++){
		for(int j=0;j<res[0].size();j++){
			printf("%d ", res[i][j]);
		}
		puts("");
	}
	puts("");
}

int main(){
	// int tc = 1;
	// scanf("%d",&tc);
	// while(tc--){
	// 	solve();
	// }

	int n,m,threshold;

	while(scanf("%d %d %d",&n,&m,&threshold) != EOF) {
		vector<vector<int>> image(n, vector<int>(m, 0));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d",&image[i][j]);
			}
		}

		Solution s;
		vector<vector<int>> res = s.resultGrid(image, threshold);
		printRes(res);
	}

	return 0;
};