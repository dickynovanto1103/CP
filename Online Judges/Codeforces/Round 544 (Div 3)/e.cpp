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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 5e3 + 3;

int dp[maxn][maxn]; //menyatakan jumlah maksimal student sampe idx i dengan udah j grup terbentuk
int dpPrev[maxn][maxn];

void maks(int &a, int b){
	a = max(a, b);
}
int n;
int a[maxn];

int solve(int idx, int banyakGrup, int firstMember) {
	if(banyakGrup == 0){return 0;}
	if(idx == n+1){return 0;}
	if(dp[idx][banyakGrup] != -1){return dp[idx][banyakGrup];}
	if(a[idx] - firstMember <= 5){
		return dp[idx][banyakGrup] = max(1 + solve(idx+1, banyakGrup, firstMember), max(solve(idx+1, banyakGrup, firstMember), 1 + solve(idx+1, banyakGrup - 1, a[idx])));
	}else{
		return dp[idx][banyakGrup] = max(solve(idx+1, banyakGrup, firstMember), 1 + solve(idx+1, banyakGrup - 1, a[idx]));
	}
	// return dp[idx][banyakGrup] = max(solve(idx+1, ))
}

int main(){
	int k,i,j;
	scanf("%d %d",&n,&k);
	
	for(i=1;i<=n;i++){scanf("%d",&a[i]);}
	memset(dp, -1, sizeof dp);
	sort(a+1, a+n+1);
	
	//bottom up..need to repair
	// dp[1][1] = 1;
	// dpPrev[1][1] = a[1];

	// for(i=2;i<=n;i++){
	// 	printf("%d: ",i);
	// 	for(j=1;j<=i;j++){
	// 		if(j > k){break;}
	// 		if(j == i){
	// 			dp[i][j] = dp[i-1][j-1] + 1;
	// 			dpPrev[i][j] = a[i];
	// 			continue;
	// 		}

	// 		dp[i][j] = dp[i-1][j];
	// 		//masalah ada disini
	// 		int idxSebelum = i-dp[i-1][j]+1;

	// 		if(a[i] - a[idxSebelum] <= 5){
	// 			dpPrev[i][j] = a[idxSebelum];
	// 		}else{
	// 			dpPrev[i][j] = dpPrev[i-1][j];	
	// 		}
	// 	}

	// 	for(j=1;j<=i;j++){
	// 		if(j > k){break;}
	// 		if(dp[i][j] < dp[i-1][j-1] + 1) { //ambil kasus grup baru
	// 			dp[i][j] = dp[i-1][j-1] + 1;
	// 			dpPrev[i][j] = a[i];
	// 		}else if(dp[i][j] == dp[i-1][j-1] + 1) {
	// 			dpPrev[i][j] = a[i];
	// 		}
	// 		//ambil kasus grup sama
	// 		if(a[i] - dpPrev[i-1][j] <= 5){
	// 			if(dp[i][j] < dp[i-1][j] + 1){
	// 				dp[i][j] = dp[i-1][j] + 1;
	// 				dpPrev[i][j] = dpPrev[i-1][j];
	// 			}else if(dp[i][j] == dp[i-1][j] + 1) {
	// 				maks(dpPrev[i][j], dpPrev[i-1][j]);
	// 			}
	// 		}
	// 		printf("%d(%d) ",dp[i][j], dpPrev[i][j]);
	// 	}
	// 	printf("\n");


	// }
	// int ans = 0;
	// for(i=1;i<=n;i++){
	// 	for(j=1;j<=k;j++){
	// 		maks(ans, dp[i][j]);
	// 	}
	// }
	printf("%d\n",solve(1, k, a[1]));
	return 0;
};