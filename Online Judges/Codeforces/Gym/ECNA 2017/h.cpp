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
string kata[maxn];
int n,m;
int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,1,1,1,0,-1,-1,-1};

void dfs(int x,int y){
	char kar = kata[x][y];
	// printf("x: %d y: %d\n",x,y);
	kata[x][y] = '.';
	for(int i=0;i<8;i++){
		int xbaru = x + dx[i], ybaru = y + dy[i];
		// printf("xbaru: %d ybaru: %d\n",xbaru,ybaru);
		if(xbaru>=0 && xbaru<n && ybaru>=0 && ybaru<m) {
			if(kata[xbaru][ybaru] == '#'){
				dfs(xbaru,ybaru);
			}
		}
		
	}
	
}

int main(){
	int i,j;
	scanf("%d %d",&n,&m);
	
	for(i=0;i<n;i++){
		cin>>kata[i];
	}
	int ans = 0;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(kata[i][j] == '#') {
				ans++;
				// printf("ans: %d\n",ans);
				dfs(i,j);
			}
		}
	}

	printf("%d\n",ans);
	return 0;
};