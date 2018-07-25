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

int dp[maxn];
int n,a[maxn];

int main(){
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		dp[i] = 1;
		scanf("%d",&a[i]);
	}

	for(i=1;i<n;i++){
		for(j=0;j<i;j++){
			if(a[i] > a[j] && (dp[j] + 1) > dp[i]){
				dp[i] = dp[j] + 1;
			}
		}
	}

	int ans = 0;
	for(i=0;i<n;i++){
		// printf("dp[%d]: %d\n",i,dp[i]);
		ans = max(ans, dp[i]);
	}
	printf("%d\n",ans);

	return 0;
};