/*
ID: dickyno1
LANG: C++14
TASK: numtri
*/

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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int a[1001][1001];
int dp[1001][1001];

int main(){
	freopen("numtri.in", "r", stdin);
	freopen("numtri.out", "w", stdout);

	int n,i,j;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(j=1;j<=i;j++){
			scanf("%d",&a[i][j]);
		}
	}

	dp[1][1] = a[1][1];
	for(int i=2;i<=n;i++){
		for(j=1;j<=i;j++){
			dp[i][j] = a[i][j] + max(dp[i-1][j], dp[i-1][j-1]);
		}
	}
	int ans = 0;
	for(i=0;i<=n;i++){
		ans = max(ans,dp[n][i]);
	}
	printf("%d\n", ans);
	
	return 0;
};