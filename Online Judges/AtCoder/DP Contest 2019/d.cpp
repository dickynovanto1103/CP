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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ll dp[101][100001];

ll v[101], w[101];

int n;

ll solve(int idx, int sisaW){
	if(idx == n){return 0;}
	if(dp[idx][sisaW] != -1){return dp[idx][sisaW];}
	if(sisaW < w[idx]){return solve(idx+1, sisaW);}
	return dp[idx][sisaW] = max(solve(idx+1, sisaW), v[idx] + solve(idx+1, sisaW - w[idx]));
}

int main(){
	int W,i,j;
	scanf("%d %d",&n,&W);
	for(i=0;i<n;i++){
		scanf("%lld %lld",&w[i],&v[i]);
	}
	memset(dp, -1, sizeof dp);
	printf("%lld\n",solve(0, W));
	return 0;
};