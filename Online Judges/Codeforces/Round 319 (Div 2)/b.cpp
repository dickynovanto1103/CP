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

int a[1000001];
int dp[1001][1001][2];
int n,m;

int solve(int idx, int sumMod, int added) {
	// printf("idx: %d sumMod: %d added: %d\n", idx, sumMod, added);
	if(sumMod == 0 && added){
		return 1;
	}
	if(idx == n){
		return 0;
	}

	int& ans = dp[idx][sumMod][added];

	if(ans != -1){
		return ans;
	}
	return ans = max(solve(idx+1, (sumMod + a[idx]) % m, 1), solve(idx+1, sumMod, added));
}

int main(){
	int i,j;
	
	while(scanf("%d %d",&n,&m)!=EOF) {
		
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			a[i] %= m;
		}	
		if(n > m){
			printf("YES\n");
		}else{
			memset(dp, -1, sizeof dp);
			bool ans = solve(0, 0, 0);

			printf("%s\n", ans == true ? "YES": "NO");
		}
	}
	
	
	return 0;
};