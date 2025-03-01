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

//copied and modified from geeks for geeks
long long findLargestArea(int x1, int y1, int x2, int y2,
                int x3, int y3, int x4, int y4)
{
    int x5 = max(x1, x3);
    int y5 = max(y1, y3);
 
    int x6 = min(x2, x4);
    int y6 = min(y2, y4);

    if (x5 > x6 || y5 > y6) {
        return 0;
    }

    int x7 = x5;
    int y7 = y6;

    int x8 = x6;
    int y8 = y5;

    int selisihX = abs(x8 - x7);
    int selisihY = abs(y8 - y7);
    int minim = min(selisihX, selisihY);

    // printf("top left point: (%d, %d)\n", x7, y7);
    // printf("bottom right point: (%d, %d)\n", x8, y8);

    return (ll)minim * minim;
}

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
    	int n = bottomLeft.size();
    	ll maks = 0;
  		for(int i=0;i<n;i++){
  			for(int j=i+1;j<n;j++){
  				long long ans = findLargestArea(bottomLeft[i][0], bottomLeft[i][1], topRight[i][0], topRight[i][1], 
  					bottomLeft[j][0], bottomLeft[j][1], topRight[j][0], topRight[j][1]);
  				maks = max(maks, ans);
  			}
  		} 

  		return maks;
    }
};

void solve(){

}

int main(){
	// int tc = 1;
	// scanf("%d",&tc);
	// while(tc--){
	// 	solve();
	// }

	int n;
	while(scanf("%d",&n) != EOF) {
		vector<vector<int>> bottomLeft(n, vi(2, 0)), topRight(n, vi(2, 0));
		for(int i=0;i<n;i++){
			scanf("%d %d",&bottomLeft[i][0], &bottomLeft[i][1]);
		}

		for(int i=0;i<n;i++){
			scanf("%d %d",&topRight[i][0], &topRight[i][1]);
		}

		Solution s;
		s.largestSquareArea(bottomLeft, topRight)
	}

	return 0;
};