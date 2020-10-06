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

bool cmp(ii a, ii b) {
	return a.first > b.first;
}

int dp[201][201][201];

int r,g,b;

int main(){
	int i,j,k;

	while(scanf("%d %d %d",&r,&g,&b) != EOF) {
		int a[3][201];
		for(i=0;i<=r;i++){
			for(j=0;j<=g;j++){
				for(k=0;k<=b;k++){
					dp[i][j][k] = 0;
				}
			}
		}

		for(i=0;i<r;i++){
			int bil;
			scanf("%d",&a[0][i]);
		}
		for(i=0;i<g;i++){
			int bil;
			scanf("%d",&a[1][i]);
		}
		for(i=0;i<b;i++){
			int bil;
			scanf("%d",&a[2][i]);
		}
		//it needs to be sorted because optimally we want to pick 2 biggest numbers, then to the smallest, but the problem with not sorting it is that we can still pick the 2 biggest numbers
		// but potentially, we cannot pick the next biggest 2 numbers because the indices crosses
		//example: 
		// 100 ...
		// ... 900
		// if we don't sort it, it will only pick 100 * 900 and nothing else, but we want to pick 100 * 900, then the smaller ones as well...and we can achieve this by sorting the array first
		sort(a[0], a[0] + r);
		sort(a[1], a[1] + g);
		sort(a[2], a[2] + b);
 		
 		for(i=0;i<=r;i++){
 			for(j=0;j<=g;j++){
 				for(k=0;k<=b;k++){
 					if(i == r && j == g && k == b){

 					} else if(i == r && j == g) {
 						dp[i][j][k+1] = max(dp[i][j][k+1], dp[i][j][k]);
 						continue;
 					} else if(i == r && k == b) {
 						dp[i][j+1][k] = max(dp[i][j+1][k], dp[i][j][k]);
 						continue;
 					} else if(j == g && k == b) {
 						dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
 						continue;
 					} else if(i == r) {
 						dp[i][j+1][k+1] = max(dp[i][j+1][k+1], dp[i][j][k] + a[1][j] * a[2][k]);
 						dp[i][j+1][k] = max(dp[i][j+1][k], dp[i][j][k]); //skip
 						dp[i][j][k+1] = max(dp[i][j][k+1], dp[i][j][k]); //skip
 						continue;
 					} else if(j == g) {
 						dp[i+1][j][k+1] = max(dp[i+1][j][k+1], dp[i][j][k] + a[0][i] * a[2][k]);
 						dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
 						dp[i][j][k+1] = max(dp[i][j][k+1], dp[i][j][k]);
 						continue;
 					} else if(k == b) {
 						dp[i+1][j+1][k] = max(dp[i+1][j+1][k], dp[i][j][k] + a[0][i] * a[1][j]);
 						dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
 						dp[i][j+1][k] = max(dp[i][j+1][k], dp[i][j][k]);
 						continue;	
 					} else {
 						//either ambil ij, ik, jk, atau ga ngambil samsek dan cuman skip
	 					dp[i+1][j+1][k] = max(dp[i+1][j+1][k], dp[i][j][k] + a[0][i] * a[1][j]);
	 					dp[i+1][j][k+1] = max(dp[i+1][j][k+1], dp[i][j][k] + a[0][i] * a[2][k]);
	 					dp[i][j+1][k+1] = max(dp[i][j+1][k+1], dp[i][j][k] + a[1][j] * a[2][k]);
	 					dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
	 					dp[i][j+1][k] = max(dp[i][j+1][k], dp[i][j][k]);
	 					dp[i][j][k+1] = max(dp[i][j][k+1], dp[i][j][k]);	
 					}
 					
 				}
 			}
 		}

 		ll ans = 0;
 		for(i=0;i<=r;i++){
 			for(j=0;j<=g;j++){
 				for(k=0;k<=b;k++){
 					ans = max(ans, (ll)dp[i][j][k]);
 				}
 			}
 		}
		printf("%lld\n",ans);

	}
	
	return 0;
};