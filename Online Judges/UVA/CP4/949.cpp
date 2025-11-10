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
typedef pair<ii,ii> iiii;
typedef vector<ii> vii;

// struct pair_hash {
//     template<class T1, class T2>
//     size_t operator()(const pair<T1, T2>& p) const {
//         size_t seed = 0;
//         boost::hash_combine(seed, p.first);
//         boost::hash_combine(seed, p.second);
//         return seed;
//     }

//     size_t hash_combine(size_t seed, )
// };

int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

void solve(){
	int r,c;
	while(scanf("%d %d",&r,&c) != EOF) {
		int restriction;
		scanf("%d",&restriction);

		map<iiii, bool> isBlocked;
		for(int i=0;i<restriction;i++){
			int a,b,c,d;
			scanf("%d%d%d%d",&a,&b,&c,&d);
			isBlocked[iiii(ii(a,b),ii(c,d))] = true;
		}

		map<ii, set<int>> monitorTime;
		int numMonitor;
		scanf("%d",&numMonitor);
		int maksTime = 0;
		for(int i=0;i<numMonitor;i++){
			int time, a,b;
			scanf("%d%d%d",&time,&a,&b);
			maksTime = max(maksTime, time);
			monitorTime[ii(a, b)].insert(time);
			// printf("inserting time: %d into: %d %d\n", time, a, b);
		}

		int minimDist = inf;

		for(int time=0;time<=maksTime;time++) {
			int dist[r + 1][c + 1];
			memset(dist, -1, sizeof dist);
			dist[0][0] = time;
			queue<ii> q;
			q.push(ii(0,0));
			bool encounterMonitor = false;
			while(!q.empty()) {
				ii front = q.front(); q.pop();
				int curDist = dist[front.first][front.second];
				for(int i=0;i<4;i++){
					int nr = front.first + dr[i], nc = front.second + dc[i];
					if(nr < 0 || nr >= r || nc < 0 || nc >= c) {
						continue;
					}

					if(isBlocked[iiii(front, ii(nr, nc))]) {
						continue;
					}

					if(monitorTime[ii(nr, nc)].count(curDist + 1)) { //anggepannya ga bs didatengin
						encounterMonitor = true;
						continue;
					}

					if(dist[nr][nc] == -1) {
						dist[nr][nc] = curDist + 1;
						q.push(ii(nr, nc));
					}
				}
			}

			// printf("time: %d, dist akhir: %d\n", time, dist[r-1][c-1]);

			if(dist[r - 1][c - 1] > -1){
				minimDist = min(minimDist, dist[r-1][c-1]);
			}

			if(!encounterMonitor) {
				break;
			}
		}

		printf("%d\n", minimDist);
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