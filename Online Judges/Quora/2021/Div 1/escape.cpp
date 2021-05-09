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
typedef pair<ii,int> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

string a[1001];

bool cmp(iii a, iii b){
	return a.second > b.second;
}

int n,m;

bool vis[1001][1001];

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void dfs(int x, int y, int d) {
	if(d == 0){
		return;
	}
	
	for(int i=0;i<4;i++){
		int xbaru = x + dx[i], ybaru = y + dy[i];
		if(xbaru >= 0 && xbaru < n && ybaru >= 0 && ybaru < m){
			if(a[xbaru][ybaru] != '#' && !vis[xbaru][ybaru]){
				vis[xbaru][ybaru] = true;
				a[xbaru][ybaru] = '#';
				// printf("xbaru: %d ybaru: %d d-1: %d\n",xbaru, ybaru, d-1);
				dfs(xbaru, ybaru, d-1);
			}
		}
	}
}

int dist[1001][1001];

int main(){
	int k,i,j;
	while(scanf("%d %d %d",&n,&m, &k)!=EOF) {
		memset(vis, false, sizeof vis);
		memset(dist, -1, sizeof dist);
		viii guards;
		for(i=0;i<n;i++){
			cin>>a[i];
		}

		ii start, end;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(a[i][j] == 'S'){start = ii(i, j);}
				else if(a[i][j] == 'E'){end = ii(i,j);}
			}
		}

		// printf("map before\n");
		// for(i=0;i<n;i++){
		// 	cout<<a[i]<<endl;
		// }

		for(i=0;i<k;i++){
			int x,y,d;
			scanf("%d %d %d",&x,&y,&d);
			x--; y--;
			guards.pb(iii(ii(x,y), d));
		}
		sort(guards.begin(), guards.end(), cmp);
		for(i=0;i<k;i++){
			iii g = guards[i];
			int x = g.first.first, y = g.first.second, d = g.second;
			a[x][y] = '#';
			// printf("passed x: %d y: %d d: %d\n",x,y,d);
			dfs(x, y, d);
		}

		// printf("map after\n");
		// for(i=0;i<n;i++){
		// 	cout<<a[i]<<endl;
		// }

		queue<ii> q;
		dist[start.first][start.second] = 0;
		q.push(start);
		while(!q.empty()){
			ii front = q.front(); q.pop();
			int x = front.first, y = front.second;
			for(i=0;i<4;i++){
				int xbaru = x + dx[i], ybaru = y + dy[i];
				if(xbaru >= 0 && xbaru < n && ybaru >= 0 && ybaru < m){
					if(a[xbaru][ybaru] != '#' && dist[xbaru][ybaru] == -1){
						dist[xbaru][ybaru] = dist[x][y] + 1;
						q.push(ii(xbaru, ybaru));
					}
				}
			}
		}

		if(dist[end.first][end.second] == -1){
			printf("IMPOSSIBLE\n");
		}else if(a[start.first][start.second] == '#' || a[end.first][end.second] == '#'){
			printf("IMPOSSIBLE\n");
		}else{
			printf("%d\n",dist[end.first][end.second]);
		}
	}
	

	
	return 0;
};