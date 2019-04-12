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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 2e3 + 3;

int pref[maxn];

void normalize(int &a) {
	if(a % 10 < 5){a -= (a%10);}
	else{a += (10 - a%10);}
}

int main(){
	int n,d,i,j;
	scanf("%d %d",&n,&d);
	int a[maxn];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		pref[i] = a[i];
		if(i){pref[i] += pref[i-1];}
	}
	// if(n == 1){printf("%d\n",n);}
	int dp[maxn][22];

	for(i=0;i<n;i++){
		for(j=0;j<=d;j++){
			dp[i][j] = inf;
		}
	}

	for(i=0;i<n;i++){
		dp[i][0] = pref[i];
		// printf("dp[%d][%d]: %d\n",i,0,dp[i][0]);
		normalize(dp[i][0]);
	}

	for(i=0;i<n;i++){
		for(j=1;j<=d;j++){
			for(int k=0;k<=i;k++){
				// printf("k: %d j: %d\n",k,j);
				dp[i][j] = min(dp[i][j], dp[k][j-1] + (pref[i] - pref[k]));
				// printf("dp[%d][%d] jd: %d\n",i,j,dp[i][j]);
			}
			normalize(dp[i][j]);
			// printf("dp[%d][%d]: %d\n",i,j,dp[i][j]);
		}
	}
	printf("%d\n",dp[n-1][d]);
	return 0;
};