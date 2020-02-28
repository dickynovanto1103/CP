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

int main(){
	int n,k,i,j;
	scanf("%d %d",&n,&k);
	int dp[501][501];
	for(i=0;i<=500;i++){
		for(j=0;j<=500;j++){
			dp[i][j] = inf;
		}
	}
	int a[501], temp[501], anstemp[501];

	for(i=0;i<n;i++){scanf("%d",&a[i]); temp[i] = a[i];}
	int ans = 0;
	for(i=1;i<n;i++){
		int selisih = k - (a[i] + a[i-1]);
		if(selisih > 0){ans += selisih; a[i] += selisih;}
	}

	for(i=0;i<n;i++){
		anstemp[i] = a[i]; a[i] = temp[i];
	}
	int ans2 = 0;
	for(i=n-2;i>=0;i--){
		int selisih = k - (a[i] + a[i+1]);
		if(selisih > 0){ans2 += selisih; a[i] += selisih;}
	}
	if(ans2 < ans){
		for(i=0;i<n;i++){
			anstemp[i] = a[i];
		}

	}

	// printf("ans: %d\n",ans2);
	printf("%d\n",min(ans, ans2));
	for(i=0;i<n;i++){
		printf("%d ",anstemp[i]);
	}
	printf("\n");
	// for(i=0;i<=k;i++){
	// 	int tot = i+a[0]+a[1];
	// 	if(tot >= k && tot <= 500){
	// 		dp[1][tot] = i;
	// 	}
	// }

	// for(i=2;i<n;i++){
	// 	for(j=0;j<=k;j++) {//val last
	// 		for(int l=0;l<=k;l++){//tambahan
	// 			int tot = l + j + a[i];
	// 			if(tot >= k && tot <= 500){
	// 				dp[i][tot] = dp[i-1][j] + 
	// 			}	
	// 		}
			
	// 		for(int l=0;l<=k;l++){
	// 			if(l + a[i] )
	// 		}
	// 	}
	// }
	return 0;
};