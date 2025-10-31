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

int dr[] = {-2,-1,1,2,2,1,-1,-2};
int dc[] = {1,2,2,1,-1,-2,-2,-1};

ii convertStrToPair(string s) {
	return {s[0] - 'a' + 1, s[1] - '0'};
}

void solve(){
	string source, dest;
	while(cin>>source>>dest) {

		queue<iii> q;
		int dist[9][9];
		memset(dist, -1, sizeof(dist));

		ii sourcePair = convertStrToPair(source);
		// printf("sourcePair: %d, %d\n", sourcePair.first, sourcePair.second);
		dist[sourcePair.first][sourcePair.second] = 0;

		q.push(iii(sourcePair, 0));
		
		while(!q.empty()) {
			iii temp = q.front(); q.pop();
			ii front = temp.first;
			int jarak = temp.second;

			for(int i=0;i<8;i++){
				int nr = front.first + dr[i];
				int nc = front.second + dc[i];

				if(nr >= 1 && nr <= 8 && nc >= 1 && nc <= 8 && dist[nr][nc] == -1) {
					dist[nr][nc] = jarak + 1;
					// printf("dist[%d][%d]: %d\n", nr,nc, jarak+1);
					q.push(iii(ii(nr, nc), dist[nr][nc]));
				}
			}
		}

		ii akhirPair = convertStrToPair(dest);
		// printf("akhirPair: %d, %d\n", akhirPair.first, akhirPair.second);
		cout<<"To get from "<< source<< " to "<< dest << " takes "<< dist[akhirPair.first][akhirPair.second] <<  " knight moves."<<endl;
	}
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};