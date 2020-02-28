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
	int n,i,j;
	scanf("%d",&n);
	int dp[101][3];
	for(i=0;i<=n;i++){
		for(j=0;j<3;j++){
			dp[i][j] = 10000;
		}
	}
	int a[101];
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	if(a[0] == 0){dp[0][0] = 1;}
	else if(a[0] == 1){dp[0][1] = 0; dp[0][0]=1;}
	else if(a[0] == 2){dp[0][2] = 0; dp[0][0] = 1;}
	else{dp[0][1] = dp[0][2] = 0; dp[0][0] = 1;}
	for(i=1;i<n;i++){
		if(a[i] == 1){dp[i][1] = min(dp[i-1][0], dp[i-1][2]);}
		else if(a[i] == 2){dp[i][2] = min(dp[i-1][0], dp[i-1][1]);}
		else if(a[i] == 3){dp[i][1] = min(dp[i-1][0], dp[i-1][2]); dp[i][2] = min(dp[i-1][0], dp[i-1][1]);}
		dp[i][0] = min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2])) + 1;
	}
	printf("%d\n",min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2])));

	return 0;
};