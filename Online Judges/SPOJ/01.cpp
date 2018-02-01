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

const int maxn = 1e4 + 1;
ll dp[maxn][2];
int n;

ll solve(int idx, int angka){
	if(idx==n){return 1;}
	if(dp[idx][angka]!=-1){return dp[idx][angka];}
	ll ans = 0;
	if(angka==0){
		ans+=solve(idx+1,1);
	}else{
		ans+=(solve(idx+1,1) + solve(idx+1,0));
	}
	return dp[idx][angka] = ans;
}

int main(){
	int i,j;
	scanf("%d",&n);
	memset(dp,-1,sizeof dp);
	ll ans = solve(1,0) + solve(1,1);
	printf("%lld\n",ans);
	return 0;
};