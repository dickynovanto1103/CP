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
	int n,c,i,j;
	scanf("%d %d",&n,&c);
	int a[200010], b[200010];
	int dp[200001][2];
	for(i=0;i<n;i++){
		dp[i][0] = dp[i][1] = inf;
	}
	for(i=1;i<=n-1;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n-1;i++){
		scanf("%d",&b[i]);
	}
	printf("0");
	dp[0][0] = 0;
	for(i=1;i<=n-1;i++){
		dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + a[i];
		dp[i][1] = min(dp[i-1][0] + b[i] + c, dp[i-1][1] + b[i]);
		printf(" %d",min(dp[i][0], dp[i][1]));
	}
	printf("\n");
	return 0;
};