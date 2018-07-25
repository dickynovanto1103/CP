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

const int maxn = 15;

int dp[maxn][21];
int n;
int a[maxn];

int solve(int idx, int lastBil){
	// printf("idx: %d lastBil: %d\n",idx, lastBil);
	if(idx==n){return 0;}
	if(dp[idx][lastBil] != -1){
		// printf("idx: %d dp: %d\n",idx, dp[idx]);
		return dp[idx][lastBil];
	}
	if(a[idx] > lastBil){
		//antara mau skip atau ambil
		int ans2 = solve(idx+1, lastBil);
		int ans1 = 1 + solve(idx+1, a[idx]);
		
		// printf("ans1: %d ans2; %d lastBil: %d a[%d]: %d\n",ans1,ans2,lastBil, idx,a[idx]);
		int ans = max(ans1,ans2);
		return dp[idx][lastBil] = ans;
	}else{
		int ans = solve(idx+1, lastBil);
		return dp[idx][lastBil] = ans;
	}
}

int main(){
	int i,j;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	memset(dp,-1,sizeof dp);
	solve(0, 0);
	int ans = 0;
	for(i=0;i<n;i++){
		for(j=0;j<20;j++){
			ans = max(ans, dp[i][j]);	
		}
		
		
	}
	printf("%d\n",ans);
	return 0;
};