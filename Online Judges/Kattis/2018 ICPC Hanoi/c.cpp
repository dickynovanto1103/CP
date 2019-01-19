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
typedef pair<ii,int> iii;
typedef vector<ii> vii;

const int maxn = 1e2 + 2;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int r,c;
bool isValid(int x, int y){
	return x>=0 && x < r && y >= 0 && y < c;
}

int main(){
	int n,i,j;
	scanf("%d %d %d",&r,&c,&n);
	queue<iii> q;
	int dist[maxn][maxn];
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			dist[i][j] = inf;
		}
	}
	for(i=0;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		x--; y--;
		dist[x][y] = 0;
		q.push(make_pair(ii(x,y),1));
	}
	int ans = 1;
	while(!q.empty()){
		iii front = q.front(); q.pop();
		int x = front.first.first, y = front.first.second, d = front.second;
		for(i=0;i<4;i++){
			int xbaru = x + dx[i], ybaru = y + dy[i];
			if(isValid(xbaru,ybaru)){
				if(dist[xbaru][ybaru] == inf){
					dist[xbaru][ybaru] = dist[x][y] + 1;
					q.push(make_pair(ii(xbaru, ybaru), d+1));
					ans = max(ans, d+1);
				}
			}
		}
	}
	printf("%d\n",ans);

	return 0;
};