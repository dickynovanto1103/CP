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

const int maxn = 1e3 + 3;

int dp[maxn][maxn];
int a[maxn];
int n;
int solve(int idx, int val) {
	if(idx >= n){return 0;}
	if(dp[idx][val] != -1){return dp[idx][val];}
	if(val < a[idx]){return solve(idx+1, val);}
	return dp[idx][val] = max(solve(idx+1, val), a[idx] + solve(idx+2, val - a[idx]));
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	int tt = 1;
	while(tc--){
		printf("Scenario #%d: ",tt++);
		memset(dp, -1, sizeof dp);
		int w;
		scanf("%d %d",&n,&w);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		printf("%d\n",solve(0, w));
	}
	return 0;
};