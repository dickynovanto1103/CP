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

const int maxn = 1e5 + 5;

const int mod = 1e9 + 7;

vector<vi> AdjList;

ll dp[maxn][2];

void mul(ll &a, ll b){
	a *= b;
	a %= mod;	
}

void add(ll &a, ll b){
	a += b;
	if(a >= mod){
		a -= mod;
	}
}

ll solve(int idx, int warna, int p){
	int i,j;
	bool isTraversed = false;
	if(dp[idx][warna] != -1){
		return dp[idx][warna];
	}
	ll ans = 1;
	for(i=0;i<AdjList[idx].size();i++) {
		int v = AdjList[idx][i];
		if(v != p){
			isTraversed = true;
			if(warna == 0) {
				ll jawab = solve(v, 0, idx) + solve(v, 1, idx);
				mul(ans, jawab);
			}else{

				mul(ans, solve(v, 0, idx));
			}
		}
	}
	
	return dp[idx][warna] = ans;
}


int main(){
	int n,i,j;
	scanf("%d",&n);
	AdjList.assign(maxn, vi());
	for(i=0;i<(n-1);i++){
		int a,b;
		scanf("%d %d",&a,&b);
		AdjList[a].pb(b); AdjList[b].pb(a);
	}

	memset(dp, -1, sizeof dp);
	int ans = solve(1, 0, -1) + solve(1,1,-1);
	for(i=1;i<=n;i++){
		for(j=0;j<2;j++){
			// printf("dp[%d][%d]: %d\n",i,j,dp[i][j]);
		}
	}
	if(ans >= mod){ans -= mod;}
	printf("%d\n",ans);

	return 0;
};