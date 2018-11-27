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

ll dp[100000];
map<int, int> mapper;
int cnt = 1;
ll solve(int n){
	// printf("n: %d\n",n);
	if(mapper.find(n) != mapper.end()){
		int idx = mapper[n];
		return dp[idx];
	}else{
		mapper[n] = cnt;

		int temp = cnt;
		cnt++;
		// printf("dimap n: %d ke %d\n",n,cnt);
		return dp[temp] = max((ll)n, solve(n/2) + solve(n/3) + solve(n/4));
	}
}

int main(){
	int n;
	memset(dp, -1, sizeof dp);
	mapper[0] = 0;
	dp[0] = 0;
	while(scanf("%d",&n)!=EOF){
		// printf("n: %d\n",n);
		ll ans = solve(n);
		printf("%lld\n",ans);
	}
	
	return 0;
};