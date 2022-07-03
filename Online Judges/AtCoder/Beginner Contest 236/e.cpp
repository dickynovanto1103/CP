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
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

ll a[100010];
int n;

ii dp[100010][2];

ii maksDouble(ii a, ii b) {
	if(a.first * b.second > a.second * b.first){return a;}
	return b;
}

ii tambah(ii a, ii b) {
	return ii(a.first + b.first, a.second + b.second);
}

int main(){
	int i,j;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}

	dp[0][0] = ii(0, 0);
	dp[0][1] = ii(a[0], 1);
	for(int i=1;i<n;i++){
		dp[i][0] = dp[i-1][1];
		dp[i][1] = maksDouble(tambah(dp[i-1][0], ii(a[i], 1)), tambah(dp[i-1][1], ii(a[i], 1)));
	}

	double maksAvg = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++) {
			ii pas = dp[i][j];
			printf("dp[%d][%d]: %lld %lld\n", i, j, pas.first, pas.second);
			if(dp[i][j].second == 0){continue;}
			maksAvg = max(maksAvg, (double)dp[i][j].first / dp[i][j].second);
		}
		
	}


	printf("%.4lf\n", maksAvg);

	return 0;
};