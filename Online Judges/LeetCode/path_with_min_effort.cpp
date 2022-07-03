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
typedef pair<ii,int> iii;
typedef vector<ii> vii;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

class Solution {
public:
	bool can(vector<vi>& heights, int minJarak) {
		bool vis[100][100];
		memset(vis, false, sizeof vis);
		queue<iii> q;
		q.push(iii(ii(0,0), heights[0][0]));
		vis[0][0] = true;
		int n = heights.size();
		int m = heights[0].size();
		while(!q.empty()) {
			iii record = q.front(); q.pop();
			int x = record.first.first;
			int y = record.first.second;
			// printf("process: %d %d\n", x, y);
			for(int i=0;i<4;i++){
				int xbaru = x + dx[i], ybaru = y + dy[i];
				if(xbaru >= 0 && xbaru < n && ybaru >= 0 && ybaru < m && !vis[xbaru][ybaru]) {
					int selisih = abs(heights[xbaru][ybaru] - heights[x][y]);
					if(selisih <= minJarak) {
						vis[xbaru][ybaru] = true;
						q.push(iii(ii(xbaru, ybaru), heights[xbaru][ybaru]));
					}
				}
			}
		}

		// for(int i=0;i<n;i++){
		// 	for(int j=0;j<m;j++){
		// 		printf("%d ", vis[i][j]);
		// 	}
		// 	puts("");
		// }

		return vis[n-1][m-1];
	}

    int minimumEffortPath(vector<vector<int>>& heights) {
        int kiri = 0, kanan = 1000000, mid, ans;
        while(kiri <= kanan) {
        	mid = (kiri + kanan) / 2;
        	// printf("mid: %d kiri: %d kanan: %d\n", mid, kiri, kanan);
        	if(can(heights, mid)) {
        		ans = mid;
        		kanan = mid-1;
        	}else{
        		kiri = mid+1;
        	}
        }

        return ans;
    }
};

int main(){
	int n,m;
	while(cin>>n>>m) {
		vector<vi> heights;
		for(int i=0;i<n;i++){
			vi v;
			for(int j=0;j<m;j++){
				int bil;
				cin>>bil;
				v.pb(bil);
			}
			heights.pb(v);
		}

		Solution sol;
		cout<<sol.minimumEffortPath(heights)<<endl;
	}
	
	return 0;
};