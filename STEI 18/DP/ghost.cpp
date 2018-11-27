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

const int maxn = 310;

int a[maxn][maxn];
int dp[2*maxn][maxn][maxn];
int n,m;

int solve(int step, int rowA, int rowB){
	if(step == (n+m-2)){
		return a[n][m];
	}

	int colA = step + 2 - rowA;
	int colB = step + 2 - rowB;
	if(colB > m || colA > m){return -inf;}
	if(rowA > n || rowB > n){return -inf;}
	int& ans = dp[step][rowA][rowB];
	if(ans != -1){return ans;}
	if(rowA == rowB){
		int ans1 = solve(step+1, rowA, rowB);
		int ans2 = solve(step+1, rowA+1, rowB);
		int ans3 = solve(step+1, rowA, rowB+1);
		int ans4 = solve(step+1, rowA+1, rowB+1);
		return ans = a[rowA][colA] + max(ans1,max(ans2,max(ans3,ans4)));
	}else{
		int ans1 = solve(step+1, rowA, rowB);
		int ans2 = solve(step+1, rowA+1, rowB);
		int ans3 = solve(step+1, rowA, rowB+1);
		int ans4 = solve(step+1, rowA+1, rowB+1);
		return ans = a[rowA][colA] + a[rowB][colB] + max(ans1,max(ans2,max(ans3,ans4)));
	}
}

int main(){
	int i,j;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			// printf("i: %d j: %d\n",i,j);
			scanf("%d",&a[i][j]);
			// printf("a[%d][%d]: %d\n",i,j,a[i][j]);
		}
	}
	memset(dp,-1,sizeof dp);
	int ans = solve(0,1,1);
	printf("%d\n",ans);
	return 0;
};