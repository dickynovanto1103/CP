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

string s[1000];

int dist[1001][1001];

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int mx[] = {-1,-1,1,1,-2,-2,-2,-2,-2,-1,0,1,2,2,2,2,2,1,0,-1};
int my[] = {-1,1,1,-1,-2,-1,0,1,2,2,2,2,2,1,0,-1,-2,-2,-2,-2};

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	int r1,c1,r2,c2;
	scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
	r1--; r2--;c1--;c2--;
	for(i=0;i<n;i++){
		cin>>s[i];
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			dist[i][j] = inf;
		}
	}

	dist[r1][c1] = 0;
	deque<ii> q;
	q.push_front(ii(r1,c1));
	while(!q.empty()) {
		ii front = q.front(); q.pop_front();
		int x = front.first, y = front.second;
		for(i=0;i<4;i++){
			int xbaru = x + dx[i], ybaru = y + dy[i];
			if(xbaru >= 0 && xbaru < n && ybaru >=0 && ybaru < m) {
				if(s[xbaru][ybaru] == '.' && dist[xbaru][ybaru] > dist[x][y]){
					dist[xbaru][ybaru] = dist[x][y];
					q.push_front(ii(xbaru, ybaru));
				}
			}
		}
		for(i=0;i<20;i++){
			int xbaru = x + mx[i], ybaru = y + my[i];
			if(xbaru >= 0 && xbaru < n && ybaru >=0 && ybaru < m) {
				if(s[xbaru][ybaru] == '.' && dist[xbaru][ybaru] > (dist[x][y] + 1)){
					dist[xbaru][ybaru] = dist[x][y] + 1;
					q.push_back(ii(xbaru, ybaru));
				}
			}
		}
	}

	if(dist[r2][c2] == inf){printf("-1\n");}
	else{printf("%d\n",dist[r2][c2]);}

	
	return 0;
};