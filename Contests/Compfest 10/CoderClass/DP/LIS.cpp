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

const int maxn = 5e3 + 1;
int n,a[maxn];
int lis[maxn];

int getPanjangLIS() {
	int i,j;
	
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){
			if(a[i] > a[j] && (lis[j] + 1) > lis[i]){
				lis[i] = lis[j] + 1;
			}
		}
	}
	int maks = 0;
	for(i=0;i<n;i++){
		maks = max(maks, lis[i]);
	}
	return maks;
}

ll dp[maxn][maxn][2];

ll solve(int idx, int sisaPanjangLIS, int lastBil, int isDiambil){
	
	if(idx == n){
		if(sisaPanjangLIS == 0){
			return 1;
		}
		else{
			return 0;
		}
	}
	if(sisaPanjangLIS == 0){return 1;}
	if(dp[idx][sisaPanjangLIS][isDiambil] != -1){return dp[idx][sisaPanjangLIS][isDiambil];}

	if(a[idx] > lastBil){
		ll ans1 = solve(idx+1, sisaPanjangLIS-1, a[idx], 1);
		ll ans2 = solve(idx+1, sisaPanjangLIS, lastBil, 0);

		return dp[idx][sisaPanjangLIS][isDiambil] = ans1 + ans2;
	}else{
		return dp[idx][sisaPanjangLIS][isDiambil] = solve(idx+1, sisaPanjangLIS, lastBil,0);
	}
}

int main(){
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		lis[i] = 1;
		scanf("%d",&a[i]);
	}

	int pjgLis = getPanjangLIS();

	memset(dp,-1,sizeof dp);
	solve(0, pjgLis, 0,0);
	
	// for(i=0;i<=n;i++){
	// 	for(j=0;j<=pjgLis;j++){
	// 		if(j){printf(" ");}
	// 		printf("%lld", dp[i][j]);
	// 	}
	// 	printf("\n");
	// }
	ll ans = 0;
	for(i=0;i<n;i++){
		// printf("dp[%d][%d]: %lld\n",i,pjgLis, dp[i][pjgLis]);
		for(j=0;j<2;j++){
			if(dp[i][pjgLis][j] > 0){
				ans+=dp[i][pjgLis][j];
			}
		}
		
		
	}
	printf("%d %lld\n",pjgLis, ans);
	return 0;
};