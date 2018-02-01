#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int mod = 1e9 + 7;
ll memo[2001][501];

ll solve(int n, int m, int batas){
	if(n<=0){return 0;}
	if(m==1){
		if(n>=10){return 0;}
		return 1;
	}
	if(memo[n][m]!=-1){return memo[n][m];}
	ll ans = 0;
	for(int i=1;i<=batas;i++){
		ans+=solve(n-i,m-1,batas);
		ans%=mod;
	}
	return memo[n][m] = ans;
}

int main() {
	int tc,n,m,i,j;
	memset(memo,-1,sizeof memo);
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&m);
		int batas = min(n,9);
		ll ans = solve(n,m,batas);
		ans%=mod;
		printf("%lld\n",ans);
	}
	return 0;
}