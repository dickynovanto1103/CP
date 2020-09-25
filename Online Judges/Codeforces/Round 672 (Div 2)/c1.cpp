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

ll dp[300001][2];
int a[300001];
int n,q;

ll solve(int idx, int isPlus) {
	if(idx == n){return 0;}
	ll& ans = dp[idx][isPlus];
	if(ans != -1){return ans;}
	ll nilai = a[idx] * (isPlus ? 1 : -1);
	ans = max(solve(idx+1, isPlus), nilai + solve(idx+1, 1-isPlus));
	return ans;
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	
	while(tc--){
		scanf("%d %d",&n,&q);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			dp[i][0] = dp[i][1] = -1;
		}
		ll ans = solve(0, 1);
		printf("%lld\n",ans);
	}
	
	return 0;
};