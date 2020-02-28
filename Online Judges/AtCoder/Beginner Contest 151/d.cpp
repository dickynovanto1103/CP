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

int dis[21][21];
string a[21];

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int n,m;

int bfs(int x, int y){
	queue<ii> q;
	q.push(ii(x,y));
	int i,j;
	int maks = 0;
	dis[x][y] = 0;
	// printf("x: %d y: %d\n",x,y);
	while(!q.empty()){
		ii pas = q.front(); q.pop();
		int x = pas.first, y = pas.second;

		for(i=0;i<4;i++){
			int xbaru = x + dx[i], ybaru = y + dy[i];
			if(xbaru >= 0 && xbaru < n && ybaru >= 0 && ybaru < m){
				if(dis[xbaru][ybaru] == -1 && a[xbaru][ybaru] == '.'){
					dis[xbaru][ybaru] = dis[x][y] + 1;
					maks = max(maks, dis[xbaru][ybaru]);
					q.push(ii(xbaru, ybaru));
				}
			}
		}	
	}
	// printf("maks: %d\n",maks);
	return maks;	
}

int main(){
	int i,j;
	scanf("%d %d",&n,&m);
	
	for(i=0;i<n;i++){cin>>a[i];}
	int ans = 0;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(a[i][j] == '.'){
				memset(dis, -1, sizeof dis);
				ans = max(ans, bfs(i,j));
			}
		}
	}
	printf("%d\n",ans);
	return 0;
};