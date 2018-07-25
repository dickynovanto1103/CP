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

int dx[] = {-2,-1,1,2,1,-1};
int dy[] = {0,1,1,0,-1,-1};

int dp[15][100][100];

int xAwal = 50, yAwal = 50;

int solve(int sisaStep, int x, int y){
	if(sisaStep == 0){
		if(x == xAwal && y == yAwal){return 1;}
		else{return 0;}
	}
	if(dp[sisaStep][x][y]!=-1){return dp[sisaStep][x][y];}
	int ans = 0;
	for(int i=0;i<6;i++){
		int xbaru = x+dx[i], ybaru = y+dy[i];
		ans+=solve(sisaStep-1, xbaru, ybaru);
	}
	return dp[sisaStep][x][y] = ans;
}

int main(){
	memset(dp,-1,sizeof dp);
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int n;
		scanf("%d",&n);
		printf("%d\n",solve(n, xAwal, yAwal));
	}
	return 0;
};