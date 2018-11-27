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

const int maxn = 21;

int a[21][21];
ll dp[21][1<<20];
int n;

ll solve(int idx, int bit){
	if(idx == n){
		if(bit == ((1<<n) - 1)){return 1;}
		else{return 0;}
	}
	ll ans = 0;
	if(dp[idx][bit]!=-1){return dp[idx][bit];}
	for(int i=0;i<n;i++){
		if(a[idx][i] == 1 && ((bit) & (1<<i)) == 0){
			ans += solve(idx+1, bit | (1<<i));
		}
	}
	return dp[idx][bit] = ans;
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		memset(dp, -1, sizeof dp);
		scanf("%d",&n);
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d",&a[i][j]);
			}
		}
		ll ans = solve(0,0);
		printf("%lld\n",ans);
	}
	return 0;
};