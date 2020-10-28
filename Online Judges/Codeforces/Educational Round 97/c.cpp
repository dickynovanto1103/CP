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

const int maxn = 2e2 + 2;
int a[maxn];
int dp[maxn][maxn*maxn];

int n;

int solve(int idx, int curBil) {
	if(idx == n){return 0;}
	if(curBil > n*n){return inf;}
	int& ans = dp[idx][curBil];
	if(ans != -1){return ans;}
	return ans = min(solve(idx, curBil+1), abs(a[idx] - curBil) + solve(idx + 1, curBil + 1));
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		sort(a, a+n);
		for(i=0;i<=n;i++){
			for(j=0;j<=n*n;j++){
				dp[i][j] = -1;
			}
		}
		int ans = solve(0, 1);
		printf("%d\n",ans);
	}
	
	return 0;
};