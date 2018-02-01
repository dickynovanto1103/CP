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
const int maxn = 5e2 + 5;
ll dp[maxn][maxn];
const ll mod = 1e9 + 7;

int main(){
	int tc,n,m,i,j;
	
	for(i=1;i<maxn;i++){dp[i][1] = 1;}
	for(i=1;i<maxn;i++){dp[1][i] = 1;}
	for(i=2;i<maxn;i++){
		for(j=2;j<maxn;j++){
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
			dp[i][j]%=mod;
		}
	}
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&m);
		printf("%lld\n",dp[n+1][m+1]);
	}

	return 0;
};