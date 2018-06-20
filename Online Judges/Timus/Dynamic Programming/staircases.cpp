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

const int maxn = 501;
ll dp[maxn][maxn];

ll solve(int sisa, int counter, int sebelum) {
	if(counter==1 && sisa == 0){return 0;}
	if(sisa == 0){return 1;}
	if(dp[sisa][sebelum]!=-1){return dp[sisa][sebelum];}
	ll ans = 0;
	for(int i=sebelum+1;i<=maxn;i++) {
		if((sisa-i) < 0){break;}
		ans+=solve(sisa-i, counter+1, i);
	}
	if(ans==0){return 0;}
	return dp[sisa][sebelum] = ans;
}

int main(){
	int n;
	scanf("%d",&n);
	memset(dp,-1,sizeof dp);

	ll ans = solve(n, 0, 0);
	printf("%lld\n",ans);
	return 0;
};