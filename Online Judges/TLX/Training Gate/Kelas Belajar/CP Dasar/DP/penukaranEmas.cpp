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

int dp[1010];

int main(){
	dp[1] = 1;
	dp[0] = 0;
	for(int i=2;i<=1000;i++){
		dp[i] = max(i, dp[i/2] + dp[i/3] + dp[i/4]);
	}
	int n;
	while(scanf("%d",&n) != EOF) {
		printf("%d\n", dp[n]);
	}
	
	return 0;
};