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

string kata[101];

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int n,m;

void dfs(int x, int y) {
	kata[x][y] = '3';
	for(int i=0;i<4;i++) {
		int xbaru = x + dx[i], ybaru = y+dy[i];
		if(xbaru >=0 && xbaru<n && ybaru >=0 && ybaru<m){
			if(kata[xbaru][ybaru] == '-'){
				dfs(xbaru, ybaru);
			}
		}
	}
}

int main(){
	int i,j;
	int tc = 1;
	while(scanf("%d %d",&n,&m)!=EOF){
		
		for(i=0;i<n;i++){
			cin>>kata[i];
		}
		int cnt = 0;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(kata[i][j] == '-'){
					cnt++;
					// printf("i: %d j: %d\n",i,j);
					dfs(i,j);
				}
			}
		}
		printf("Case %d: %d\n",tc++, cnt);
	}
	return 0;
};