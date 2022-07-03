/*
ID: dickyno1
LANG: C++14
TASK: ttwo
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
#define COW 0
#define FARMER 1
typedef long long ll;
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef vector<ii> vii;

string s[11];

int dist[2][11][11][4];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

ii move(ii koor, int dir) {
	return {koor.first + dy[dir], koor.second + dx[dir]};
}

bool isOutOfBound(ii koor) {
	return koor.first < 0 || koor.first >= 10 || koor.second < 0 || koor.second >= 10;
}

bool isObstacle(ii koor) {
	return s[koor.first][koor.second] == '*';
}

bool canReach(ii koor) {
	return !isOutOfBound(koor) && !isObstacle(koor);
}

void bfs(ii koor, int creature) {
	queue<iii> q;

	dist[creature][koor.first][koor.second][0] = 0;
	
	q.push(iii(koor, 0));
	while(!q.empty()) {
		iii front = q.front(); q.pop();
		koor = front.first; int dir = front.second;
		ii newKoor = move(koor, dir);
		if(canReach(newKoor)) {
			if(dist[creature][newKoor.first][newKoor.second][dir] == -1) {
				dist[creature][newKoor.first][newKoor.second][dir] = dist[creature][koor.first][koor.second][dir] + 1;
				q.push(iii(newKoor, dir));	
			}
		}else{
			int newDir = (dir + 1) % 4;
			if(dist[creature][koor.first][koor.second][newDir] == -1) {
				dist[creature][koor.first][koor.second][newDir] = dist[creature][koor.first][koor.second][dir] + 1;
				q.push(iii(koor, newDir));
			}
		}

		// for(int i=1;i<=4;i++){
		// 	int newDir = (dir + i) % 4;
		// 	if(dist[creature][koor.first][koor.second][newDir] == -1) {
		// 		dist[creature][koor.first][koor.second][newDir] = dist[creature][koor.first][koor.second][dir] + 1;
		// 		q.push(iii(koor, newDir));
		// 	}
		// }
	}
}

bool inSameKoor(ii a, ii b) {
	return a == b;
}

int simulate(ii koorCow, ii koorFarmer) {
	int dirCow = 0;
	int dirFarmer = 0;
	int ans = 0;
	while(koorCow != koorFarmer) {
		ii newKoorCow = move(koorCow, dirCow);
		if(canReach(newKoorCow)) {
			koorCow = newKoorCow;
		}else{
			dirCow++; dirCow %= 4;
		}

		ii newKoorFarmer = move(koorFarmer, dirFarmer);
		if(canReach(newKoorFarmer)) {
			koorFarmer = newKoorFarmer;
		}else{
			dirFarmer++; dirFarmer %= 4;
		}
		ans++;
		if(ans > 1000000) {
			return 0;
		}
	}

	return ans;
}

int main(){
	freopen("ttwo.in", "r", stdin);
	freopen("ttwo.out", "w", stdout);

	for(int i=0;i<10;i++){
		cin>>s[i];
	}

	ii koorCow = ii(-1,-1), koorFarmer = {-1, -1};
	int i,j,k;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			char c = s[i][j];
			if(c == 'C') {
				koorCow = ii(i,j);
			}else if(c == 'F'){
				koorFarmer = {i,j};
			}
		}
	}

	int ans = simulate(koorCow, koorFarmer);

	printf("%d\n", ans);
	
	return 0;
};