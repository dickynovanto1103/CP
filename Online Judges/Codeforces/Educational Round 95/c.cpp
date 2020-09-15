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

int n;
int dp[200001][2];
int a[200001];

int solve(int idx, int orang){
	if(idx >= n){return 0;}
	int& ans = dp[idx][orang];
	if(ans != -1){return ans;}
	for(int i=1;i<=2;i++) {
		int cost1 = (a[idx] == 1);
		int cost2 = ((idx + 1) < n && a[idx + 1] == 1);
		ans = min(solve(idx+1, 1 - orang) + (orang % 2 == 1 ? cost1 : 0), solve(idx+2, 1 - orang) + (orang % 2 == 1 ? cost1 + cost2 : 0));
	}
	return ans;
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	
	while(tc--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			dp[i][0] = dp[i][1] = -1;
		}
		int ans = solve(0, 1);
		
		printf("%d\n",ans);
	}
	
	return 0;
};