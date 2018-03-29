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
typedef vector<ii> vii;

const int maxn = 1e3 +3;
char kata[maxn][maxn];
int dist[maxn][maxn];

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){scanf("%s",kata[i]);}
	ii idxExit, idxStart;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			dist[i][j] = inf;
			if(kata[i][j]=='E'){idxExit= ii(i,j);}
			else if(kata[i][j]=='S'){idxStart=ii(i,j);}
		}
	}
	queue<ii> q; q.push(idxExit);
	dist[idxExit.first][idxExit.second] = 0;
	int dx[] = {-1,0,1,0};
	int dy[] = {0,1,0,-1};
	while(!q.empty()) {
		ii front = q.front(); q.pop();
		int x = front.first, y = front.second;
		for(i=0;i<4;i++){
			int xbaru = x+dx[i], ybaru = y+dy[i];
			if(xbaru>=0 && xbaru<n && ybaru>=0 && ybaru<m) {
				if(dist[xbaru][ybaru]==inf && kata[xbaru][ybaru]!='T'){
					dist[xbaru][ybaru] = (dist[x][y] + 1);
					q.push(ii(xbaru,ybaru));
				}
			}
		}
	}
	int jarakKu = dist[idxStart.first][idxStart.second];
	int counter = 0;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(kata[i][j]>='1' && kata[i][j]<='9'){
				int jarakMusuh = dist[i][j];
				if(jarakMusuh<=jarakKu){
					counter+=(kata[i][j]-'0');
				}
			}
		}
	}
	printf("%d\n",counter);
	return 0;
};