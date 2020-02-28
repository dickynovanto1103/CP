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

int main(){
	int dp[101][101],i,j;
	memset(dp,0, sizeof dp);
	dp[0][0] = 1; dp[0][1] = 0; dp[1][0] = 0;

	for(i=1;i<100;i++){
		for(j=1;j<100;j++){
			dp[i][j] = j*dp[i-1][j] + dp[i-1][j-1];
			// dp[i][j] %= 2;
		}
	}
	vii list;
	for(i=0;i<100;i++){
		for(j=0;j<100;j++){
			if(j){printf(" ");}
			printf("%d",dp[i][j]);
			// if(dp[i][j]){printf("%d %d\n",i,j);}
		}
		printf("\n");
	}
	return 0;
};