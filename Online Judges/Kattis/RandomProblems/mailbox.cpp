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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int dp[11][101][101];

int pref[101];

int solve(int sisa, int l, int r) {
	if(l > r){return 0;}
	if(sisa == 1){return pref[r] - pref[l-1];}
	if(dp[sisa][l][r] != -1){return dp[sisa][l][r];}
	dp[sisa][l][r] = inf;
	for(int i=l;i<=r;++i){
		dp[sisa][l][r] = min(dp[sisa][l][r], i + max(solve(sisa-1, l, i-1), solve(sisa, i + 1, r)));
	}
	return dp[sisa][l][r];
}

int main(){
	int tc,i,j;
	int k,n;
	scanf("%d",&tc);
	for(i=1;i<=100;i++) {
		pref[i] = i;
		pref[i] += pref[i-1];
	}
	while(tc--){
		memset(dp, -1, sizeof dp);
		scanf("%d %d",&k,&n);
		printf("%d\n",solve(k, 1, n));
	}
	return 0;
};