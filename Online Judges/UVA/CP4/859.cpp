/*
15 5
1 1
1 2
1 3
1 4
1 5
2 1
2 2
2 3
2 4
2 5
14 1
14 2
14 3
14 4
14 5
15 1
15 2
15 3
15 4
15 5
1 4

PPPPP
QQQQQ
.....
.....
.....
.....
.....
.....
.....
.....
.....
.....
.....
AAAAA
BBBBB
*/

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

int dcJump[] = {-1,-1,0,1,1};
int drJump[] = {0,1,1,1,0};

int dc[] = {-1,0,1};
int dr[] = {0,1,0};

void solve(){
	int tt = 1;
	int r,c;
	while(scanf("%d%d",&r,&c) != EOF) {
		if(tt > 1) {puts("");}
		tt++;

		int dist[r + 1][c + 1];
		memset(dist, -1, sizeof dist);

		bool peta[r + 1][c + 1] = {false};
		
		for(int i=0;i<4*c;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			peta[a][b] = true;
		}

		int a,b;
		scanf("%d%d",&a,&b);
		dist[a][b] = 0;
		for(int i=0;i<3;i++){
			int newR = a + dr[i], newC = b + dc[i];
			if(newR >= 1 && newR <= r && newC >= 1 && newC <= c && !peta[newR][newC]) {
				dist[newR][newC] = 1;
			}
		}
		queue<ii> q;
		q.push(ii(a,b));

		
		while(!q.empty()){
			ii from = q.front(); q.pop();
			for(int i=0;i<5;i++){
				int newR = from.first + drJump[i], newC = from.second + dcJump[i];
				if(newR >= 1 && newR <= r && newC >= 1 && newC <= c) {
					if(peta[newR][newC]) {
						int newR2 = from.first + drJump[i]*2, newC2 = from.second + dcJump[i] * 2;
						// printf("from: %d %d, newR and newC: %d %d, jump: %d %d\n", from.first, from.second, newR, newC, newR2, newC2);
						if(newR2 >= 1 && newR2 <= r && newC2 >= 1 && newC2 <= c && !peta[newR2][newC2] && dist[newR2][newC2] == -1) {
							dist[newR2][newC2] = dist[from.first][from.second] + 1;
							q.push(ii(newR2, newC2));
							// printf("pushed: %d %d\n", newR2, newC2);
						}	
					}
				}
			}
		}

		for(int i=r;i>=1;i--){
			for(int j=1;j<=c;j++){
				if(dist[i][j] >= 1) {
					printf("%d %d %d\n", i,j,dist[i][j]);
				}
			}
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