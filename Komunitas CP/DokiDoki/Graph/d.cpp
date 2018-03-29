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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int , ii> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

const int maxn = 1e3 + 4;

char kata[maxn][maxn];
int dist[maxn][maxn];

viii AdjList[maxn][maxn];

int main(){
	int tc,i,j,n,m;
	int dx[] = {-1,0,1,0};
	int dy[] = {0,1,0,-1};
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++){scanf("%s",kata[i]);}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				dist[i][j] = inf;
				for(int k=0;k<4;k++){
					int xbaru = i+dx[k], ybaru = j + dy[k];
					if(xbaru>=0 && xbaru<n && ybaru>=0 && ybaru<m) {
						if(kata[i][j] == kata[xbaru][ybaru]) {
							AdjList[i][j].pb(make_pair(0,ii(xbaru,ybaru)));
						}else{
							AdjList[i][j].pb(make_pair(1,ii(xbaru,ybaru)));
						}
					}
				}
			}
		}
		deque<ii> d;
		dist[0][0] = 0;
		d.push_back( ii(0,0));

		while(!d.empty()){
			ii front = d.front(); d.pop_front();
			int x = front.first, y = front.second;
			
			for(i=0;i<AdjList[x][y].size();i++){
				iii v = AdjList[x][y][i];
				int berat = v.first, xbaru = v.second.first, ybaru = v.second.second;
				if(dist[xbaru][ybaru] > (dist[x][y] + berat)) {
					dist[xbaru][ybaru] = dist[x][y] + berat;
					if(berat==0){
						d.push_front(ii(xbaru,ybaru));
					}else{
						d.push_back(ii(xbaru,ybaru));
					}
				}
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				AdjList[i][j].clear();	
			}
		}
		printf("%d\n",dist[n-1][m-1]);	
	}
	
	return 0;
};
