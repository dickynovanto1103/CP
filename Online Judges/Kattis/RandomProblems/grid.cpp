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

const int maxn = 501;
int n,m;
bool isValid(int x, int y){
	return x>=0 && x<n && y>=0 && y<m;
}

int main(){
	int i,j;
	scanf("%d %d",&n,&m);
	int dist[maxn][maxn];
	for(i=0;i<n;i++){

		for(j=0;j<m;j++){
			dist[i][j] = inf;
		}
	}
	int a[maxn][maxn];
	string kata[maxn];
	for(i=0;i<n;i++){
		cin>>kata[i];
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			a[i][j] = kata[i][j] - '0';
		}
	}
	int dx[] = {-1,0,1,0};
	int dy[] = {0,1,0,-1};
	queue<ii> q;
	q.push(ii(0,0));
	dist[0][0] = 0;
	while(!q.empty()){
		ii front = q.front(); q.pop();
		int x = front.first, y = front.second;
		for(i=0;i<4;i++){
			int xbaru = x + a[x][y]*dx[i], ybaru = y + dy[i]*a[x][y];
			if(isValid(xbaru, ybaru)){
				if(dist[xbaru][ybaru] == inf){
					dist[xbaru][ybaru] = dist[x][y] + 1;
					q.push(ii(xbaru, ybaru));
				}
			}
		}
	}
	if(dist[n-1][m-1] == inf){printf("-1\n");}
	else{printf("%d\n",dist[n-1][m-1]);}
	return 0;
};