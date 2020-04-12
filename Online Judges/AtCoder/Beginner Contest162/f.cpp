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

ll a[200001];
ll dp[200001][4];

int n;

ll maks;

ll solve(int idx, int rem) {
	if(idx >= n){return 0;}
	if(idx == (n-1) && rem >= 1){return 0;}
	if(rem == 0){return dp[idx][rem] = a[idx] + solve(idx+2, rem);}
	if(dp[idx][rem] != -maks){return dp[idx][rem];}
	return dp[idx][rem] = max(a[idx] + solve(idx+2, rem), solve(idx+1, rem-1));
}

int main(){
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}

	if(n % 2 == 0){
		ll sum1 = 0;
		for(i=0;i<n;i+=2){
			sum1 += a[i];
		}
		ll sum2 = 0;
		for(i=1;i<n;i+=2){
			sum2 += a[i];
		}
		printf("%lld\n",max(sum1, sum2));
		return 0;
	}
	maks = (ll)inf*(ll)inf;
	for(i=0;i<=200000;i++){
		for(j=0;j<=3;j++){
			dp[i][j] = -maks;
		}
	}
	// memset(dp, -1, sizeof dp);

	ll ans = solve(0, 2);
	printf("%lld\n",ans);

	return 0;
};