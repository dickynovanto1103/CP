#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int dx[] = {-1,0,1,0,-1,1,1,-1};
int dy[] = {0,1,0,-1,1,1,-1,-1};

int dist[1010][1010];

int main() {
	int n,m,i,j;
	string kata[1010];
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){cin>>kata[i];}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			dist[i][j] = inf;
		}
	}
	queue<ii> q; q.push(ii(0,0));
	dist[0][0] = 0;
	while(!q.empty()){
		ii front = q.front(); q.pop();
		int x = front.first, y = front.second;
		for(i=0;i<4;i++){
			int xbaru = x+dx[i], ybaru = y+dy[i];
			if(dist[xbaru][ybaru]==inf){
				if(kata[xbaru][ybaru]=='.'){
					dist[xbaru][ybaru] = dist[x][y] + 1;
					q.push(ii(xbaru,ybaru));	
				}
				
			}
		}
	}
	if(dist[n-1][m-1]==inf){printf("-1\n");}
	else{printf("%d\n",dist[n-1][m-1]);}
	return 0;
}