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

int dp[maxn][maxn];
int a[maxn][maxn];
int n,m;
int solve(int r, int c){
	if(r == n){return 0;}
	if(dp[r][c]!=-1){return dp[r][c];}
	int ans = 0;
	if(c>0){
		ans = max(ans, a[r][c] + solve(r+1,c-1));
	}
	ans = max(ans, a[r][c] + solve(r+1,c));
	if(c<(m-1)){
		ans = max(ans, a[r][c] + solve(r+1,c+1));
	}
	return dp[r][c] = ans;
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		memset(dp, -1, sizeof dp);
		scanf("%d %d",&n,&m);
		

		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				scanf("%d",&a[i][j]);
			}
		}
		int ans = 0;
		for(i=0;i<m;i++){
			ans = max(ans, solve(0,i));
		}
		printf("%d\n",ans);
	}
	return 0;
};