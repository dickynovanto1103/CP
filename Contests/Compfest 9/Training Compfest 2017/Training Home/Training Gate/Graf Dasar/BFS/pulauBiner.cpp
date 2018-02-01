#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int dist[1010][1010];

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int main() {
	int n,i,j;
	scanf("%d",&n);
	string kata[1010];
	for(i=0;i<n;i++){cin>>kata[i];}
	for(i=0;i<1000;i++){
		for(j=0;j<1000;j++){
			dist[i][j] = inf;
		}
	}
	int ans = inf;
	deque<ii> q; q.push_back(ii(0,0)); dist[0][0] = 0;
	while(!q.empty()){
		ii front = q.front(); q.pop_front();
		int x = front.first, y = front.second;
		for(i=0;i<4;i++){
			int xbaru = x+dx[i], ybaru = y+dy[i];
			if(xbaru>=0 && xbaru<n && ybaru>=0 && ybaru<n){
				int berat = kata[xbaru][ybaru] - '0';
				if(dist[xbaru][ybaru] > dist[x][y] + berat){
					dist[xbaru][ybaru] = dist[x][y] + berat;
					if(berat==0){q.push_front(ii(xbaru,ybaru));}
					else{q.push_back(ii(xbaru,ybaru));}
				}
			}
		}
	}

	printf("%d\n",dist[n-1][n-1]);
	
	return 0;
}