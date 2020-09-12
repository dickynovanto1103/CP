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
typedef vector<ii> vii;

int findRook(int r1, int c1, int r2, int c2) {
	if(r1 == r2 || c1 == c2) {return 1;}
	return 2;
}

int findBishop(int r1, int c1, int r2, int c2) {
	if((r1 + c1) % 2 != (r2 + c2) % 2) {return 0;}
	//sama..tentuin cuman butuh 1 atau 2
	for(int i=-8;i<=8;i++){
		int xbaru = r1 + i, ybaru = c1 + i;
		if(xbaru == r2 && ybaru == c2){return 1;}
		xbaru = r1 - i, ybaru = c1 + i;
		if(xbaru == r2 && ybaru == c2){return 1;}
		xbaru = r1 + i, ybaru = c1 - i;
		if(xbaru == r2 && ybaru == c2){return 1;}
		xbaru = r1 - i, ybaru = c1 - i;
		if(xbaru == r2 && ybaru == c2){return 1;}
	}
	return 2;
}

int findKing(int r1, int c1, int r2, int c2) {
	//bfs
	int dist[9][9];
	memset(dist, -1, sizeof dist);
	queue<ii> q;
	q.push(ii(r1, c1));
	dist[r1][c1] = 0;
	int dx[] = {0,1,1,1,0,-1,-1,-1};
	int dy[] = {1,1,0,-1,-1,-1,0,1};
	while(!q.empty()) {
		ii front = q.front(); q.pop();
		int x = front.first, y = front.second;
		for(int i=0;i<8;i++){
			int xbaru = x + dx[i], ybaru = y + dy[i];
			if(xbaru >= 1 && xbaru <= 8 && ybaru >= 1 && ybaru <= 8) {
				if(dist[xbaru][ybaru] == -1) {
					dist[xbaru][ybaru] = dist[x][y] + 1;
					q.push(ii(xbaru, ybaru));
				}
			}
		}
	}
	return dist[r2][c2];
}

int main(){
	int r1, c1, r2, c2;
	scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
	int a = findRook(r1, c1, r2, c2);
	int b = findBishop(r1, c1, r2, c2);
	int c = findKing(r1, c1, r2, c2);
	printf("%d %d %d\n",a, b, c);
	return 0;
};