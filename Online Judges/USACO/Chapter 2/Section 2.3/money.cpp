/*
ID: dickyno1
LANG: C++14
TASK: money
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

int a[26];
ll dp[26][10001];
int numCoin;

ll solve(int idx, int sisa) {
	// printf("idx: %d sisa: %d\n", idx, sisa);
	if(sisa == 0)return 1;
	if(idx == numCoin) {
		if(sisa == 0){return 1;}
		return 0;
	}
	if(sisa < a[idx]) return solve(idx+1, sisa);

	if(dp[idx][sisa] != -1) return dp[idx][sisa];
	return dp[idx][sisa] = solve(idx, sisa - a[idx]) + solve(idx+1, sisa);
}

int main(){
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);

	int n,i,j;
	scanf("%d %d",&numCoin, &n);
	for(int i=0;i<numCoin;i++){
		scanf("%d",&a[i]);
		// printf("a[%d]: %d\n", i, a[i]);
	}
	// printf("numCoin: %d n: %d\n", numCoin, n);

	memset(dp, -1, sizeof dp);
	ll ans = solve(0, n);
	printf("%lld\n", ans);

	
	return 0;
};