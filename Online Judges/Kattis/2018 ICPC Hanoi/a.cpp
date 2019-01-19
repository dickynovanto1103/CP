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

const int maxn = 1e2 + 2;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

vector<char> path;
int n,m;
int dist[maxn][maxn];

bool isValid(int x, int y){
	return x>=0 && x < n && y >= 0 && y < m;
}

void findPath(int x, int y){
	if(dist[x][y] == 0){
		dist[x][y] = -1;\
		return;
	}

	for(int i=0;i<4;i++){
		int xbaru = x + dx[i], ybaru = y + dy[i];
		if(!isValid(xbaru,ybaru)){continue;}
		if(dist[xbaru][ybaru] == (dist[x][y] -1)){

			findPath(xbaru, ybaru);

			if(i==0){path.pb('U');}
			else if(i==1){path.pb('L');}
			else if(i==2){path.pb('D');}
			else if(i==3){path.pb('R');}

			break;
		}

	}
}

int main(){
	int i,j;
	int r[10], c[10];
	
	while(scanf("%d %d",&n,&m)){

		if(n == 0 && m == 0){break;}
		// printf("halog an n: %d m: %d\n",n,m);
		memset(dist, 0, sizeof dist);
		for(i=0;i<4;i++){
			scanf("%d %d",&r[i],&c[i]);
			r[i]--; c[i]--;
			dist[r[i]][c[i]] = -1;
		}
		dist[r[1]][c[1]] = inf;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(dist[i][j] != -1)
					dist[i][j] = inf;
			}
		}
		dist[r[0]][c[0]] = 0;
		queue<ii> q;
		q.push(ii(r[0], c[0]));
		while(!q.empty()){
			ii front = q.front(); q.pop();
			int x = front.first, y = front.second;
			for(i=0;i<4;i++){
				int xbaru = x + dx[i], ybaru = y + dy[i];
				if(!isValid(xbaru,ybaru)){continue;}
				if(dist[xbaru][ybaru] == inf){
					dist[xbaru][ybaru] = dist[x][y] + 1;
					q.push(ii(xbaru, ybaru));
				}
			}
		}


		if(dist[r[1]][c[1]] == inf){
			printf("NO\n");
			continue;
		}
		//cari path dan mark sebagai -1
		findPath(r[1], c[1]);
		int x = r[0], y = c[0];
		
		for(i=0;i<path.size();i++){
			char kar = path[i];
			dist[x][y] = -1;
			if(kar == 'L'){y--;}
			else if(kar == 'R'){y++;}
			else if(kar == 'U'){x++;}
			else if(kar == 'D'){x--;}
		
			dist[x][y] = -1;
		}
		

		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(dist[i][j] != -1)
					dist[i][j] = inf;
			}
		}
		dist[r[2]][c[2]] = inf;
		
		dist[r[1]][c[1]] = 0;
		
		q.push(ii(r[1], c[1]));
		while(!q.empty()){
			ii front = q.front(); q.pop();
			int x = front.first, y = front.second;
			// printf("x; %d y: %d\n",x,y);
			for(i=0;i<4;i++){
				int xbaru = x + dx[i], ybaru = y + dy[i];
				if(!isValid(xbaru,ybaru)){continue;}
				if(dist[xbaru][ybaru] == inf){
					dist[xbaru][ybaru] = dist[x][y] + 1;
					// printf("dipush xba\n");
					q.push(ii(xbaru, ybaru));
				}
			}
		}
		if(dist[r[2]][c[2]] == inf){printf("NO\n"); continue;}

		findPath(r[2], c[2]);
		printf("YES\n");
		for(char kar: path){
			printf("%c",kar);
		}
		printf("\n");
		path.clear();
	}
	return 0;
};