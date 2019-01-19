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

const int maxn = 1e3 + 3;

string kata[maxn];

const int mod = 1e9 + 7;

int dp[maxn][maxn];
int h,w;

int solve(int r, int c) {
	if(r == (h-1) && c == (w-1)){return 1;}
	if(dp[r][c] != -1){return dp[r][c];}
	int ans = 0;
	if(r == (h-1)){
		if(kata[r][c+1] == '.'){
			ans += solve(r, c+1);
			ans %= mod;	
		}
		
	}else if(c == (w-1)){
		if(kata[r+1][c] == '.'){
			ans += solve(r+1, c);
			ans %= mod;	
		}
		
	}else{
		if(kata[r][c+1] == '.'){
			ans += solve(r, c+1);
			ans %= mod;	
		}
		if(kata[r+1][c] == '.'){
			ans += solve(r+1, c);
			ans%= mod;	
		}
		
		
	}
	return dp[r][c] = ans;
}

int main(){
	int i,j;
	scanf("%d %d",&h,&w);

	for(i=0;i<h;i++){
		cin>>kata[i];
	}
	memset(dp, -1, sizeof dp);

	printf("%d\n",solve(0,0));
	// dp[h-1][w-1] = 1;
	// for(i=0;i<h;i++){
	// 	for(j=0;j<w;j++){
	// 		printf("%d ",dp[i][j]);
	// 	}
	// 	printf("\n");
	// }
	return 0;
};