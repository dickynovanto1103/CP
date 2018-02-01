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

ll dp[100];

ll solve(int n){
	int i;
	if(n==0){return 1;}
	if(n==1){return 0;}
	if(dp[n]!=-1){return dp[n];}
	ll ans = 0;

	for(i=2;i<=n;i++){
		ans+=(solve(i-2) * solve(n-i));
	}
	return dp[n] = ans;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	memset(dp,-1,sizeof dp);
	ll ans = solve(n);
	printf("%lld\n",ans);
	return 0;
};