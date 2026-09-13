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
    int bitMask[201][201];
    

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int row = heights.size(), col = heights[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                bitMask[i][j] = 0;
            }
        }

        queue<ii> q;
        for(int i=0;i<row;i++){
            q.push(ii(i, 0));
            bitMask[i][0] = 1;
        }

        for(int i=0;i<col;i++){
            q.push(ii(0, i));
            bitMask[0][i] = 1;
        }



        while(!q.empty()) {
            ii front = q.front(); q.pop();
            for(int i=0;i<4;i++){
                int newR = front.first + dr[i];
                int newC = front.second + dc[i];
                if(newR >= 0 && newR < row && newC >= 0 && newC < col && heights[newR][newC] >= heights[front.first][front.second]) {
                    if((bitMask[newR][newC] & 1)) {
                        continue;
                    }

                    q.push(ii(newR, newC));
                    bitMask[newR][newC] |= 1;
                }
            }
        }

        for(int i=0;i<row;i++){
            q.push(ii(i, col-1));
            bitMask[i][col-1] |= 2;
        }

        for(int i=0;i<col;i++){
            q.push(ii(row-1, i));
            bitMask[row-1][i] |= 2;
        }

        while(!q.empty()) {
            ii front = q.front(); q.pop();
            // printf("front: %d %d\n", front.first, front.second);
            for(int i=0;i<4;i++){
                int newR = front.first + dr[i];
                int newC = front.second + dc[i];
                if(newR >= 0 && newR < row && newC >= 0 && newC < col && heights[newR][newC] >= heights[front.first][front.second]) {
                    if((bitMask[newR][newC] & 2)) {
                        continue;
                    }


                    q.push(ii(newR, newC));
                    bitMask[newR][newC] |= 2;
                    // printf("push %d %d bitMask: %d\n", newR, newC, bitMask[newR][newC]);
                }
            }
        }

        vector<vi> ans;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(bitMask[i][j] == 3) {
                    ans.pb({i,j});
                }
            }
        }

        return ans;
    }
};

void solve(){
    int n,m;
    while(scanf("%d %d",&n,&m) != EOF) {
        vector<vi> heights;
        for(int i=0;i<n;i++){
            vi row;
            for(int j=0;j<m;j++){
                int num;
                scanf("%d",&num);
                row.pb(num);
            }

            heights.pb(row);
        }

        Solution sol;
        vector<vi> ans = sol.pacificAtlantic(heights);
        for(int i=0;i<ans.size();i++){
            printf("[%d %d]\n", ans[i][0], ans[i][1]);
            
        }
    }
}

int main(){
    int tc = 1;
    // scanf("%d",&tc);
    while(tc--){
        solve();
    }

    return 0;
};