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

const ll mod = 1e9 + 7;
const int maxn = 101;
ll dp[maxn][maxn];

ll solve(int sisa, int nilaiXor){
	if(sisa == 0){
		if(nilaiXor != 0){return 1;}
		else{return 0;}
	}else{
		if(dp[sisa][nilaiXor]!=-1){return dp[sisa][nilaiXor];}
		ll ans = 0;
		for(int i=1;i<=sisa;i++){
			ans+=(solve(sisa - i, nilaiXor^i));
			ans%=mod;
		}
		return dp[sisa][nilaiXor] = ans;
	}
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		memset(dp,-1,sizeof dp);
		int n;
		scanf("%d",&n);
		printf("%lld\n",solve(n,0));
	}
	return 0;
};