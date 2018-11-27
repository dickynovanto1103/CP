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

const int maxn = 101;

int a[maxn];
int dp[maxn][1001];
int n,k;

int solve(int idx, int sisa){
	if(idx == n){return 0;}
	if(dp[idx][sisa]!=-1){return dp[idx][sisa];}
	if(sisa < a[idx]){return solve(idx+1, sisa);}
	return dp[idx][sisa] = max(solve(idx+1, sisa), a[idx] + solve(idx+1, sisa - a[idx]));
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++){
			int banyak;
			scanf("%d",&banyak);
			int sum = 0;
			for(j=0;j<banyak;j++){
				int bil;
				scanf("%d",&bil);
				sum += bil;
			}
			a[i] = sum;
		}
		memset(dp, -1, sizeof dp);
		int ans = solve(0,k);
		printf("%d\n", ans);
	}
	return 0;
};