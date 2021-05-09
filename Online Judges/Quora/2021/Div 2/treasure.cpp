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
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

string a[1001];
int dist[1001][1001];
int dx[] = {1, 0};
int dy[] = {0, 1};
int ways[1001][1001];
const int mod = 1e9 + 7;

int main(){
	int n,i,j;
	while(scanf("%d",&n)!=EOF){
		memset(ways, 0, sizeof ways);
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				dist[i][j] = inf;
			}
		}
		for(i=0;i<n;i++){
			cin>>a[i];
		}	
		//find shortest path first, put it into matrix
		deque<iii> q;
		int bil = -(a[0][0] - '0');
		dist[0][0] = bil;
		q.push_front(iii(dist[0][0], ii(0, 0)));
		while(!q.empty()){
			iii front = q.front(); q.pop_front();
			int jarak = front.first, x = front.second.first, y = front.second.second;
			if(jarak > dist[x][y]){continue;}
			for(i=0;i<2;i++){
				int xbaru = x + dx[i], ybaru = y + dy[i];
				if(xbaru >= 0 && xbaru < n && ybaru >= 0 && ybaru < n){

					int bil = (a[xbaru][ybaru] - '0');
					if(dist[xbaru][ybaru] > (dist[x][y] - bil)){
						dist[xbaru][ybaru] = dist[x][y] - bil;	
						if(bil == 1){
							q.push_front(iii(dist[xbaru][ybaru], ii(xbaru, ybaru)));
						}else{
							q.push_back(iii(dist[xbaru][ybaru], ii(xbaru, ybaru)));
						}
					}
					
				}
			}
		}

		printf("%d ",-dist[n-1][n-1]);

		ways[0][0] = 1;
		for(i=0;i<n;i++){
			ways[0][i] = 1;
			ways[i][0] = 1;
		}

		for(i=1;i<n;i++){
			for(j=1;j<n;j++){
				int bil = (a[i][j] - '0');
				// printf("i: %d j: %d bil: %d\n",i,j,bil);
				if(dist[i][j] == (dist[i-1][j] - bil)) {
					ways[i][j] += ways[i-1][j];
					if(ways[i][j] >= mod){
						ways[i][j] -= mod;
					}
				}
				if(dist[i][j] == (dist[i][j-1] - bil)) {
					ways[i][j] += ways[i][j-1];
					if(ways[i][j] >= mod){
						ways[i][j] -= mod;
					}
				}
			}
		}
		printf("%d\n",ways[n-1][n-1]);
	}
	
	
	return 0;
};