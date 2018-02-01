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

bool dp[101][201];
int a[101];

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d",&n);
		int sum = 0;
		
		for(i=1;i<=n;i++){
			
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		for(i=0;i<=n;i++){
			dp[i][0] = true;
		}
		for(i=0;i<=sum;i++){
			dp[0][sum] = false;
		}
		for(i=1;i<=n;i++){
			for(j=0;j<=sum;j++){
				if(j<a[i]){
					dp[i][j] = dp[i-1][j];
				}else{
					dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i]];
				}
			}
		}
		// for(i=0;i<=n;i++){
		// 	for(j=0;j<=sum;j++){
		// 		if(j){printf(" ");}
		// 		cout<<dp[i][j];
		// 	}
		// 	printf("\n");
		// }
		for(i=sum/2;i>=0;i--){
			int sisa = sum-i;
			if(dp[n][i]){printf("%d\n",abs(i-sisa)); break;}

		}
	}
	return 0;
};