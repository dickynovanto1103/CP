#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int n;
string s[26];
int vis[26][26];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
deque<ii > q;
map<ii, int > me,ms;

int main(){
	int t;
	scanf("%d", &t);
	for(int cc=1;cc<=t;++cc){
		int i,j,sx,sy,ex,ey;
		scanf("%d", &n);
		for(i=0;i<n;i++)
			cin>>s[i];
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(s[i][j]=='S')
					sx=i,sy=j;
				else if(s[i][j]=='E')
					ex = i, ey = j;
			}
		}
		memset(vis, -1, sizeof vis);
		q.push_back({sx,sy});
		vis[sx][sy]=0;
		while(!q.empty()){
			ii tt = q.front();
			if(s[tt.fi][tt.se]=='K'){
				ms[{tt.fi,tt.se}] = vis[tt.fi][tt.se];
			}
			q.pop_front();
			for(int i=0;i<4;i++){
				int xx = tt.fi+dx[i];
				int yy = tt.se+dy[i];
				if(xx>=0&&xx<n&&yy>=0&&yy<n){
					if(vis[xx][yy]==-1){
						if(s[xx][yy]=='#'){
							vis[xx][yy] = vis[tt.fi][tt.se]+1;
							q.push_back({xx, yy});
						}
						else{
							vis[xx][yy] = vis[tt.fi][tt.se];
							q.push_front({xx, yy});
						}
					}
				}
			}
		}
		memset(vis, -1, sizeof vis);
		q.push_back({ex,ey});
		vis[ex][ey]=0;
		while(!q.empty()){
			ii tt = q.front();
			if(s[tt.fi][tt.se]=='K'){
				me[{tt.fi,tt.se}] = vis[tt.fi][tt.se];
			}
			q.pop_front();
			for(int i=0;i<4;i++){
				int xx = tt.fi+dx[i];
				int yy = tt.se+dy[i];
				if(xx>=0&&xx<n&&yy>=0&&yy<n){
					if(vis[xx][yy]==-1){
						if(s[xx][yy]=='#'){
							vis[xx][yy] = vis[tt.fi][tt.se]+1;
							q.push_back({xx, yy});
						}
						else{
							vis[xx][yy] = vis[tt.fi][tt.se];
							q.push_front({xx, yy});
						}
					}
				}
			}
		}
		int mi = 1e4;
		for(pair<pair<int, int>, int> x : ms){
			mi = min(mi, x.se + me[x.fi]);
		}
		printf("Case #%d: %d\n", cc, mi);
		me.clear();
		ms.clear();
	}
	return 0;
};