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

int a[51][31];
int dp[51][31][1501];
int n,k,p;

int solve1(int row, int col, int sisa) {
	if(row == n){return 0;}
	if(col == k){return solve1(row+1, 0, sisa);}
	if(sisa == 0){return 0;}
	if(dp[row][col][sisa] != -1){return dp[row][col][sisa];}

	return dp[row][col][sisa] = max(solve1(row+1, 0, sisa), a[row][col] + solve1(row, col+1, sisa-1));
}

int solve() {
	int i,j,k;
	// for(i=0;i<=n;i++){
	// 	for(j=0;j<=ka;j++){
	// 		for(k=0;k<=p;k++){
	// 			dp[i][j][k] = 0;
	// 		}
	// 	}
	// }

	memset(dp, -1, sizeof dp);

	// for(i=0;i<n;i++){
	// 	for(j=0;j<ka;j++){
	// 		for(k=p;k>=0;k--){
	// 			dp[i][j][k] = 
	// 		}
	// 	}
	// }
	return solve1(0,0,p);
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		scanf("%d %d %d",&n,&k,&p);
		
		for(i=0;i<n;i++){
			for(j=0;j<k;j++){
				scanf("%d",&a[i][j]);
			}
		}
		printf("Case #%d: %d\n",tt, solve());
	}
	return 0;
};