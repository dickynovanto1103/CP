#include <bits/stdc++.h>

using namespace std;
#define inf 100000000000000LL
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ll v[101], w[101];

ll dp[100001];

int main(){
	ll W;
	int i,j;
	int n;
	scanf("%d %lld",&n,&W);
	// printf("n: %d\n",n);
	int tot = 0;
	for(i=0;i<n;i++){
		scanf("%lld %lld",&w[i],&v[i]);
		tot += v[i];
	}
	
	for(i=1;i<=tot;i++){dp[i] = inf;}
	for(i=0;i<n;i++){
		// printf("i: %d w: %lld v; %lld\n",i,w[i], v[i]);
		for(j=tot;j>=v[i];j--){
			dp[j] = min(dp[j], dp[j-v[i]] + w[i]);
			// printf("dp[%d] jd: %lld\n",j,dp[j]);
		}
	}
	int ans = 0;
	for(i=1;i<=tot;i++){
		if(dp[i] <= W){ans = i;}
	}
	printf("%d\n",ans);
	return 0;
};