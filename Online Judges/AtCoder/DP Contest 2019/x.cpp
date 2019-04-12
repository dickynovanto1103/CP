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
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

const int maxn = 1e3 + 3;

struct box{
	int w, s, val;
};

bool cmp(box a, box b){
	return a.w + a.s < b.w + b.s;
}

// ll dp[maxn][maxn]; //dp[i][j] menyatakan jumlah minimal total weight yang dapat diperoleh sampe idx i dengan adanya j box, j <= i

int main(){
	int n,i,j;
	box a[maxn];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d %d",&a[i].w, &a[i].s, &a[i].val);
	}

	sort(a,a+n, cmp);
	
	// DP versi 1
	ll dp[20010]; //dp[i] menyatakan jumlah value maksimal apabila total weight adalah i
	memset(dp, 0, sizeof dp);
	for(i=0;i<n;i++){
		int maksBerat = a[i].s;
		printf("s: %d w: %d val; %d\n",a[i].s, a[i].w ,a[i].val);
		for(j=maksBerat;j>=0;j--){
			dp[j+a[i].w] = max(dp[j+a[i].w], dp[j] + a[i].val);
		}
	}
	ll maks = 0;
	for(i=0;i<20001;i++){
		maks = max(maks, dp[i]);
	}
	printf("%lld\n",maks);

	//wrong DP..cannot only have 1 state of idx since weight property is important and need to save the state of it or save it as a value of dp

	// for(i=1;i<=n;i++){
	// 	scanf("%d %d %d",&a[i].w, &a[i].s, &a[i].val);
	// }

	// sort(a+1,a+n+1, cmp);

	// for(i=1;i<=n;i++){
	// 	for(j=0;j<=i-1;j++){
	// 		dp[i][j] = dp[i-1][j];
	// 	}
	// 	dp[i][j] = inf;
	// 	int w = a[i].w, s = a[i].s;
	// 	for(j=i-1;j>=0;j--){
	// 		if(s >= dp[i-1][j]){
	// 			dp[i][j+1] = min(dp[i][j+1],dp[i-1][j] + w);
	// 		}
	// 	}
	// }

	// int ans = 0;

	// for(i=1;i<=n;i++){
	// 	for(j=0;j<=i;j++){
	// 		if(dp[i][j] != inf){
	// 			ans = max(ans, j);
	// 		}
	// 	}
	// }

	
	
	return 0;
};