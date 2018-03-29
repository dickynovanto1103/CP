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

const int maxn = 210;
int n,m;
bool isVisited[maxn][maxn];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
string kata[maxn];

int dfs(int r, int c){
	int i,j;
	isVisited[r][c] = true;
	int ans = 1;
	for(i=0;i<4;i++){
		int xbaru = r+dx[i], ybaru = c + dy[i];
		if(xbaru>=0 && xbaru<n && ybaru>=0 && ybaru<m){
			if(!isVisited[xbaru][ybaru] && kata[xbaru][ybaru] == '1'){
				ans+=dfs(xbaru,ybaru);
			}
		}
	}
	return ans;
}

int main(){
	
	scanf("%d %d",&n,&m);
	int i,j;
	memset(isVisited,false,sizeof isVisited);

	for(i=0;i<n;i++){cin>>kata[i];}
	int ans = 0;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(!isVisited[i][j] && kata[i][j]=='1'){
				int banyak = dfs(i,j);
				ans+=4; ans+=((banyak-1)*3);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
};