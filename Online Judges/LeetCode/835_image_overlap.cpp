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
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
    	vii a, b;
  		for(int i=0;i<img1.size();i++){
  			for(int j=0;j<img1[i].size();j++){
  				if(img1[i][j] == 1) {
  					a.pb({i,j});
  				} 
  			}
  		}

  		for(int i=0;i<img2.size();i++){
  			for(int j=0;j<img2[i].size();j++){
  				if(img2[i][j] == 1) {
  					b.pb({i,j});
  				} 
  			}
  		}

  		map<ii, int> mapper;
  		int ans = 0;
  		for(auto [r1, c1]: a) {
  			for(auto [r2, c2]: b) {
  				ans = max(ans, ++mapper[{r2 - r1, c2 - c1}]);
  			}
  		}

  		return ans;
    }
};

void solve(){

}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};