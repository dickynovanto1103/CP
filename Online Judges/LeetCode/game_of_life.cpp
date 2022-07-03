#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define DEAD 0
#define ALIVE 1
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

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

class Solution {
public:
	int numNeighbor(vector<vi>& board, int y, int x, int state) {
		int m = board[0].size(), n = board.size();
		int cnt = 0;
		for(int i=0;i<8;i++){
			int xbaru = x + dx[i];
			int ybaru = y + dy[i];
			if(xbaru >= 0 && xbaru < m && ybaru >= 0 && ybaru < n) {
				if(board[ybaru][xbaru] == state) {
					cnt++;
				}
			}
		}

		return cnt;
	}

    void gameOfLife(vector<vector<int>>& board) {
    	int n = board.size(), m = board[0].size();
    	vector<vi> ans(n, vi(m));
        for(int i=0;i<n;i++){
        	for(int j=0;j<m;j++){
        		ans[i][j] = board[i][j];
        		int numTetangga = numNeighbor(board, i, j, ALIVE);
        		if(board[i][j] == ALIVE) {
        			if(numTetangga < 2 || numTetangga > 3) {
        				ans[i][j] = DEAD;
        			}
        		}else{
        			if(numTetangga == 3) {
        				ans[i][j] = ALIVE;
        			}
        		}
        	}
        }

        board = ans;
    }
};

int main(){
	int n,m;
	while(scanf("%d %d",&n,&m) != EOF) {
		vector<vi> a(n, vi(m));
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++){
				scanf("%d",&a[i][j]);
			}
		}

		Solution sol;
		sol.gameOfLife(a);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				printf("%d ", a[i][j]);
			}
			puts("");
		}
	}
	
	return 0;
};