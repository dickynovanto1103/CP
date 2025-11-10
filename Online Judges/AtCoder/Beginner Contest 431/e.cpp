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

int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

const int UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3;

int getNewDirection(int curDir, char tipe) {
	if(tipe == 'A') {
		return curDir;
	} else if(tipe == 'B') {
		if(curDir == UP) {
			return LEFT;
		}else if(curDir == RIGHT) {
			return DOWN;
		}else if(curDir == DOWN) {
			return RIGHT;
		}else {
			return UP;
		}
	}else {
		if(curDir == UP) {
			return RIGHT;
		}else if(curDir == DOWN) {
			return LEFT;
		}else if(curDir == RIGHT) {
			return UP;
		}else{
			return DOWN;
		}
	}

	return -1;
}

void solve(){
	int h,w;
	scanf("%d%d",&h,&w);
	vector<string> v;
	for(int i=0;i<h;i++){
		string s;
		cin>>s;
		v.pb(s);
	}

	int dist[h + 2][w + 2][5];
	memset(dist, -1, sizeof dist);
	dist[0][0][0] = 0;
	deque<iii> q;
	q.pb(iii(ii(0,0), RIGHT));
	while(!q.empty()) {
		iii front = q.front(); q.pop_front();
		ii coordinate = front.first;
		int curR = coordinate.first, curC = coordinate.second;
		int dir = front.second;

		int newDir = getNewDirection(dir, v[curR][curC]);
		// printf("dir: %d, curR: %d curC: %d tipe: %c, newDir: %d\n", dir, curR, curC, v[curR][curC], newDir);
		int nr = curR + dr[newDir], nc = curC + dc[newDir];
		// if(curR == h-1 && curC == w-1) {
		// 	if(nr == h-1 && nc == w) {
		// 		if(dist[nr][nc][newDir] == -1 || dist[nr][nc][newDir] > dist[curR][curC][dir]) {
		// 			dist[nr][nc][newDir] = dist[curR][curC][dir];
		// 			q.push_front(iii(ii(nr, nc), newDir));
		// 		}
		// 	}

		// 	for(char i='A';i<='C';i++){
		// 		if(v[curR][curC] == i) {
		// 			continue;
		// 		}

		// 		int dirBaru = getNewDirection(dir, i);
		// 		int newR = curR + dr[dirBaru], newC = curC + dc[dirBaru];
		// 		if(newR >= 0 && newR < h && newC >= 0 && newC <= w) {
		// 			if(dist[newR][newC][dirBaru] == -1 || dist[newR][newC][dirBaru] > dist[curR][curC][dir] + 1) {
		// 				dist[newR][newC][dirBaru] = dist[curR][curC][dir] + 1;
		// 				q.push_back(iii(ii(newR, newC), dirBaru));
		// 			}
		// 		}
		// 	}
		// 	continue;
		// }

		if(nr >= 0 && nr < h && nc >= 0 && nc < w) {
			if(dist[nr][nc][newDir] == -1 || dist[nr][nc][newDir] > dist[curR][curC][dir]) {
				dist[nr][nc][newDir] = dist[curR][curC][dir];
				q.push_front(iii(ii(nr, nc), newDir));
			}
		}

		for(char i='A';i<='C';i++){
			if(v[curR][curC] == i) {
				continue;
			}

			int dirBaru = getNewDirection(dir, i);
			int newR = curR + dr[dirBaru], newC = curC + dc[dirBaru];
			if(newR >= 0 && newR < h && newC >= 0 && newC < w) {
				if(dist[newR][newC][dirBaru] == -1 || dist[newR][newC][dirBaru] > dist[curR][curC][dir] + 1) {
					dist[newR][newC][dirBaru] = dist[curR][curC][dir] + 1;
					q.push_back(iii(ii(newR, newC), dirBaru));
				}
			}
		}

		
	}

	// for(int i=0;i<h;i++){
	// 	for(int j=0;j<w;j++){
	// 		printf("for i,j: %d %d\n", i,j);
	// 		for(int k=0;k<4;k++) {
	// 			printf("\t%d ", dist[i][j][k]);	
	// 		}
	// 		puts("");
	// 	}
	// 	puts("");
	// }

	int ans = inf;
	for(int i=0;i<4;i++){
		//i represents the direction...and we need to know the new direction after 
		int newDir = getNewDirection(i, v[h-1][w-1]);
		if(dist[h-1][w-1][i] == -1) {
			continue;
		}
		if(newDir == i) {
			ans = min(ans, dist[h-1][w-1][i]);
		}else{
			ans = min(ans, dist[h-1][w-1][i] + 1);
		}
		
	}
	printf("%d\n", ans);
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};