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

const int maxn = 202;
const ll mod = 1e9 + 7;
ll dp[maxn][maxn][maxn];
string kata;

ll modPow(ll a, ll b){
	if(b == 0){return 1;}
	else{
		if(b%2==1){return a*modPow(a,b-1)%mod;;}
		else{
			ll temp = modPow(a,b/2);
			return temp*temp%mod;
		}
	}
}

ll solve(int awal, int akhir, int sisa){

	if(awal == akhir){
		ll ans = modPow(26, (sisa + 1) / 2) - modPow(25, (sisa+1) / 2);
		if(ans < 0){ans += mod;}
		return ans;
	}else if(awal > akhir){
		ll ans = modPow(26, sisa/2);
		return ans;
	}
	if(sisa < 0){return 0;}
	if(dp[awal][akhir][sisa]!=-1){return dp[awal][akhir][sisa];}
	if(kata[awal] == kata[akhir]){
		return dp[awal][akhir][sisa] = ((25LL * solve(awal, akhir, sisa-2))%mod + (solve(awal+1, akhir - 1, sisa)%mod))%mod;
	}else{
		ll ans1 = 24LL * solve(awal, akhir, sisa-2);
		ll ans2 = solve(awal+1, akhir, sisa - 1);
		ll ans3 = solve(awal, akhir-1, sisa - 1);
		return dp[awal][akhir][sisa] =  ((ans1 + ans2)%mod + ans3)%mod;

	}
}

int main(){
	int n,i,j;
	
	scanf("%d",&n);
	if(n == 0){printf("1\n"); return 0;}
	cin>>kata;
	memset(dp,-1,sizeof dp);
	ll ans = solve(0,n-1,n);
	printf("%lld\n",ans);
	return 0;
};