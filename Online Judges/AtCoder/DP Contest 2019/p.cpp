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

const ll mod = 1e9 + 7;

vector<vi> AdjList;

ll dp[maxn][2];

ll solve(int idx, int warna, int p){
	int i,j;
	printf("idx: %d\n",idx);
	if(dp[idx][warna] != -1){return dp[idx][warna];}
	ll ans = 0;
	bool isVisited = false;
	for(i=0;i<AdjList[idx].size();i++){
		int v = AdjList[idx][i];
		if(v != p){
			isVisited = true;
			if(warna == 0){
				//ga boleh 0 lagi
				ans += solve(v, 1,idx);
				ans %= mod;
			}else{
				ans += solve(v, 0,idx);

				ans %= mod;
				ans += solve(v, 1,idx);
				ans %= mod;
			}	
		}
		
	}
	if(!isVisited){
		ans = 1;
	}
	return dp[idx][warna] = ans;
}


int main(){
	int n,i,j;
	scanf("%d",&n);
	AdjList.assign(maxn, vi());
	for(i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		AdjList[a].pb(b); AdjList[b].pb(a);
	}

	memset(dp, -1, sizeof dp);
	ll ans = solve(1,0,1)+solve(1,1,1);
	ans %= mod;
	printf("%lld\n",ans);

	return 0;
};