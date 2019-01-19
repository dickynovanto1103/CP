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

ll v[101], w[101];

ll dp[101][100001];

int n;

ll solve(int idx, int sisaV) {
	// printf("idx: %d n: %d\n",idx,n);
	if(idx == n){
		// printf("halo\n");
		if(sisaV == 0){return 0;}
		else{return inf + 100;}
		
	}
	if(dp[idx][sisaV] != -1){return dp[idx][sisaV];}
	if(sisaV < v[idx]){return solve(idx+1, sisaV);}
	return dp[idx][sisaV] = min(solve(idx+1, sisaV), w[idx] + solve(idx+1, sisaV - v[idx]));
}

int main(){
	ll W,i,j;
	scanf("%d %lld",&n,&W);
	// printf("n: %d\n",n);
	int tot = 0;
	for(i=0;i<n;i++){
		scanf("%lld %lld",&w[i],&v[i]);
		tot += v[i];
	}
	
	//brp weight minimal untuk dapet value dari 0 sampe tot
	memset(dp, -1, sizeof dp);
	int jawab = 0;
	for(i=0;i<=tot;i++){
		ll ans = solve(0,i);
		// printf("i: %lld ans: %lld\n",i,ans);
		if(ans <= W){
			jawab = i;
		}
	}
	
	printf("%d\n",jawab);
	return 0;
};