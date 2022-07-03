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

int dc[] = {1, 0 , -1, 0};
int dr[] = {0, 1, 0, -1};

 
class Solution {
public:
	bool inRange(int r, int c, int n){
		return r >= 0 && r < n && c >= 0 && c < n;
	}

	ii move(ii koor, int& dir, int n, vector<vi>& ans) {
		int r = koor.first, c = koor.second;
		int newR = r + dr[dir], newC = c + dc[dir];
		if(inRange(newR, newC, n) && ans[newR][newC] == 0) {
			return ii(newR, newC);
		}

		dir++; dir %= 4;
		newR = r + dr[dir], newC = c + dc[dir];
		return ii(newR, newC);
	}

    vector<vector<int>> generateMatrix(int n) {
  		vector<vi> ans(n, vi(n));
  		int dir = 0;
  		int bil = 1;
  		ii koor = ii(0,0);
  		for(int it=0;it<n*n;it++){
  			ans[koor.first][koor.second] = bil++;
  			koor = move(koor, dir, n, ans);
  		}
  		return ans;
    }
};

int main(){
	int n;
	while(cin>>n){
		Solution sol;
		vector<vi> ans = sol.generateMatrix(n);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				printf("%d ", ans[i][j]);
			}
			puts("");
		}
		puts("");
	}
	
	return 0;
};