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

ll dp[5001][5001]; //dp[idx][group]: maximum value until index: idx and created that many group

int main(){
	int n,m,k,i,j;
	scanf("%d %d %d",&n,&m,&k);
	int a[5001];
	ll pref[5001];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		pref[i] = a[i];
		if(i){
			pref[i] += pref[i-1];
	}

	for(i=1;i<=k;i++){
		for(j=0;j<n;j++){
			if(j + m - 1 < n){
				dp[j+m-1][i] = max(dp[j+m-1][i], (j == 0 ? 0 : dp[j-1][i-1]) + pref[j+m-1] - (j == 0 ? 0 : pref[j-1]));
			}
			dp[j+1][i] = max(dp[j+1][i], dp[j][i]);
		}
	}
	ll ans = 0;
	for(i=0;i<n;i++){
		ans = max(ans, dp[i][k]);
		// printf("dp[%d]: %lld\n",i, dp[i][k]);
	}
	printf("%lld\n",ans);
	return 0;
};