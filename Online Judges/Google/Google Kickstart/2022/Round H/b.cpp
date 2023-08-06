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

int dp[100010];

int main(){
	int tc;

	
	fill(dp, dp+100001, inf);
	dp[1] = 1;
	for(int i=1;i<100000;i++){
		dp[i+1] = min(dp[i+1], dp[i] + 1);
		int cnt = 1;
		for(int j=i*2;j<=100000;j+=i) {
			dp[j] = min(dp[j], dp[i] + 4 + 2 * cnt);
			cnt++;
		}
	}

	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ", tt);
		int n;
		scanf("%d",&n);
		printf("%d\n", dp[n]);
	}
	
	return 0;
};