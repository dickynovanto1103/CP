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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int m;

ll modPow(ll a, ll b){
	if(b == 0){return 1;}
	else{
		if(b%2==1){return a*modPow(a,b-1)%m;}
		else{
			ll temp = modPow(a,b/2);
			return temp*temp%m;
		}
	}
}

ll dp[100][100][100];

ll solve(int a, int b, int c) {

	if(a == 0 && b == 0 && c == 0){return 1;}

	ll ans = 0;
	
	if(dp[a][b][c]!=-1){return dp[a][b][c];}
	if(a > 0){
		ll bil = modPow(2,a)*solve(a-1,b+1,c);
		bil %= m;
		ans += bil;
		ans %= m;
	}
	if(b > 0) {
		ll bil = b*solve(a, b-1, c+1);
		bil%=m;
		ans += bil;
		ans %= m;
	}
	if(c > 0){
		ll bil = c*solve(a, b, c-1);
		bil%=m;
		ans += bil;
		ans %= m;
	}
	return dp[a][b][c] = ans;
}

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		memset(dp, -1, sizeof dp);
		scanf("%d %d",&n,&m);
		printf("%lld\n",solve(n, 0, 0));

	}
	return 0;
};