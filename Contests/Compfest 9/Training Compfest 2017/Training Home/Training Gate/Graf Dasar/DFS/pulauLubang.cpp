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

int n,m;
string kata[110];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int floodFill(int x, int y){
	int ans = 1,i,j;
	kata[x][y] = '*';
	for(i=0;i<4;i++){
		int xbaru = x+dx[i], ybaru = y+dy[i];
		if(xbaru>=0 && xbaru<n && ybaru>=0 && ybaru<m){
			if(kata[xbaru][ybaru]=='.'){
				ans+=floodFill(xbaru,ybaru);
			}
		}
	}
	return ans;
}

int main() {
	int i,j;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		cin>>kata[i];
	}
	int cnt = 0, maks = 0;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(kata[i][j]=='.'){
				cnt++; 
				maks = max(maks,floodFill(i,j));
			}
		}
	}
	printf("%d %d\n",cnt,maks);
	return 0;
}