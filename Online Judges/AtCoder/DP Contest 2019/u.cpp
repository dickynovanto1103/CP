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

ll pre[1<<16];

ll dp[1<<16];

void solve(int idx, const vector<int>& notMarked, ll scoreSekarang, int maskTotal, int maskGroup) {
	if(idx == notMarked.size()) {
		dp[maskTotal] = max(dp[maskTotal], scoreSekarang + pre[maskGroup]);
		return;
	}
	solve(idx+1, notMarked, scoreSekarang, maskTotal, maskGroup);
	solve(idx+1, notMarked, scoreSekarang, maskTotal | (1<<notMarked[idx]), maskGroup | (1<<notMarked[idx]));
	return dp[maskTotal] = max(ans1,ans2);
}	

int main(){
	int n,i,j;
	scanf("%d",&n);

	ll a[n][n];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%lld",&a[i][j]);
		}
	}

	for(int mask = 0;mask < (1<<n);mask++){
		for(i=0;i<n;i++){
			if(mask & (1<<i)){
				for(j=i+1;j<n;j++){
					if(mask & (1<<j)){
						pre[mask] += a[i][j];
					}
				}
			}
		}
	}

	for(int mask = 0;mask < (1<<n);mask++){
		vector<int> notMarked;
		for(i=0;i<n;i++){
			if(!(mask & (1<<i))){notMarked.pb(i);}
		}
		solve(0, notMarked, dp[mask], mask, 0);
	}
	// for(int mask = 0;mask < (1<<n);mask++){
	// 	printf("dp[%d]: %lld\n",mask,dp[mask]);
	// }
	printf("%lld\n",dp[(1<<n) - 1]);

	return 0;
};