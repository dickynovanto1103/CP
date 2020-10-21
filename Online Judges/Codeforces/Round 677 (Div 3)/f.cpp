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

int n,m,k;
int dp[71][71][71][71];
int a[71][71];
int solve(int row, int col, int diambil, int sumModK) {
	if(row == n){
		if(sumModK == 0){
			return 0;
		}else{
			return -inf;
		}
	}
	if(col == m){
		return solve(row+1, 0, 0, sumModK);
	}
	if(diambil == m/2) {
		return solve(row+1, 0, 0, sumModK);
	}
	int& ans = dp[row][col][diambil][sumModK];
	if(ans != -1){
		return ans;
	}
	return ans = max(solve(row, col+1, diambil, sumModK), a[row][col] + solve(row, col+1, diambil + 1, (sumModK + a[row][col]) % k));
}

int main(){
	int i,j;
	while(scanf("%d %d %d",&n,&m,&k) !=EOF){
		memset(dp, -1, sizeof dp);
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				scanf("%d",&a[i][j]);
			}
		}
		int ans = max(solve(0, 0, 0, 0), 0);
		printf("%d\n",ans);	
	}
	
	return 0;
};