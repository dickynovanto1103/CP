//125000000

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

int w[501], h[501], b[501];
ll dp[500][500*500];
int prefWeight[501];
int n;

ll process(int idx, int weightHead) {
	if(idx >= n) {
		int weightBody = prefWeight[n-1] - weightHead;
		if(weightHead > weightBody) {
			return -1001LL * (ll)inf;
		}
		return 0;
	}

	if(dp[idx][weightHead] != -1) {
		return dp[idx][weightHead];
	}

	return dp[idx][weightHead] = max((ll)h[idx] + process(idx+1, weightHead + w[idx]), (ll)b[idx] + process(idx+1, weightHead));
}

void solve(){
	int tc = 1;
	while(scanf("%d",&n) != EOF) {
		memset(dp, -1, sizeof dp);
		tc++;
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&w[i],&h[i],&b[i]);
			prefWeight[i] = w[i];
			if(i){
				prefWeight[i] += prefWeight[i-1];
			}
		}
		
		ll ans = process(0, 0);
		printf("%lld\n", ans);
	}
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};