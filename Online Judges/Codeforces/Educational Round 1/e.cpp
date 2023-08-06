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

int dp[31][31][51];

int solve(int l, int r, int sisa) {
	if(sisa == 0) return 0;
	if(sisa > l*r) return inf;
	if(sisa == l*r) return 0;

	if(dp[l][r][sisa] != -1) {return dp[l][r][sisa];}
	int ans = inf;
	for(int j=0;j<=sisa;j++) {
		for(int i=1;i<=l/2;i++){
			ans = min(ans, solve(i, r, j) + solve(l-i, r, sisa - j) + r * r);
		}
		for(int i=1;i<=r/2;i++){
			ans = min(ans, solve(l, i, j) + solve(l, r - i, sisa - j) + l * l);
		}
	}
	
	return dp[l][r][sisa] = ans;
}

int main(){
	int tc;
	memset(dp, -1, sizeof dp);

	scanf("%d",&tc);
	while(tc--){
		int n,m,k;
		scanf("%d %d %d",&n,&m,&k);
		printf("%d\n", solve(n,m,k));
	}
	
	return 0;
};