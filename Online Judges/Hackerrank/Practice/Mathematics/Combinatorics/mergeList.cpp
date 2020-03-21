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
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int dp[101][101];
const int mod = 1e9 + 7;

void processDP() {
	int i,j;
	dp[0][0] = 0;
	for(i=1;i<=100;i++){
		dp[i][0] = 1;
		dp[0][i] = 1;
	}

	for(i=1;i<=100;i++){
		for(j=1;j<=100;j++){
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
			dp[i][j] %= mod;
		}
	}
}

int main(){
	int tc,i,j;

	processDP();

	scanf("%d",&tc);
	while(tc--){
		int n,m;
		scanf("%d %d",&n,&m);
		printf("%d\n",dp[n][m]);
	}
	return 0;
};