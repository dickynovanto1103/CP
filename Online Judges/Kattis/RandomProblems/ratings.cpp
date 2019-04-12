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

ll dp[15][31][3];

int a[16], n;
int sum;

ll solve(int idx, int sumTemp, int status) {
	if(idx == n){
		if(sumTemp > sum){return 0;}
		else if(sumTemp == sum){
			if(status == 2){return 1;}
			else if(status == 1){return 0;}
			else{
				return 1;
			}
		}else{
			return 1;	
		}
		
	}
	if(dp[idx][sumTemp][status] != -1){return dp[idx][sumTemp][status];}
	ll ans = 0;
	for(int i=0;i<=(sum - sumTemp);i++){
		if(status == 2 || status == 1){
			ans += solve(idx+1, sumTemp + i, status);
		}else if(status == 0){
				if(i < a[idx]){ans += solve(idx+1, sumTemp + i, 2);}
				else if(i == a[idx]){ans += solve(idx+1, sumTemp + i, status);}
				else {ans += solve(idx+1, sumTemp + i, 1);}
		}
	}
	return dp[idx][sumTemp][status] = ans;
}

int main(){
	int i,j;

	while(scanf("%d",&n), n){
		sum = 0;

		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			sum += a[i];
		}

		memset(dp, -1, sizeof dp);
		ll ans = solve(0, 0, 0);
		
		printf("%lld\n",ans);
	}
	return 0;
};