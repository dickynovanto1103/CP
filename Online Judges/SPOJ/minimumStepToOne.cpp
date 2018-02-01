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

const int maxn = 2e7 + 5;
int dp[maxn];

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	int test = 1;
	for(i=0;i<maxn;i++){
		dp[i] = inf;
	}
	dp[1] = 0;
	for(i=2;i<maxn-4;i++){
		if(i%2==0){dp[i] = min(dp[i],1+dp[i/2]);}
		if(i%3==0){dp[i] = min(dp[i],1+dp[i/3]);}
		dp[i] = min(dp[i],1+dp[i-1]);
	}
	while(tc--){
		scanf("%d",&n);

		printf("Case %d: ",test++);
		printf("%d\n",dp[n]);
	}
	return 0;
};