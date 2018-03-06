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

ll dp[101][11][101];
ll a[101][11];
int n,m,k;

ll solve(int baris, int kolom, int sisa){
	if(baris==n){return 0;}
	if(sisa==0){return dp[baris][kolom][sisa] = max(dp[baris][kolom][sisa], a[baris][kolom] + solve(baris+1,kolom,sisa));} //lanjut ke bawah
	if(dp[baris][kolom][sisa]!=-1){return dp[baris][kolom][sisa];}
	int i,j;
	dp[baris][kolom][sisa] = max(dp[baris][kolom][sisa], a[baris][kolom] + solve(baris+1,kolom,sisa));
	for(j=0;j<m;j++){
		if(j!=kolom){
			dp[baris][kolom][sisa] = max(dp[baris][kolom][sisa], a[baris][kolom] + solve(baris+1,j,sisa-1));
		}
	}
	return dp[baris][kolom][sisa];
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		memset(dp,-1,sizeof dp);
		scanf("%d %d %d",&n,&m,&k);
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				scanf("%lld",&a[i][j]);
			}
		}
		ll ans = 0;
		for(j=0;j<m;j++){
			ans = max(ans, solve(0,j,k));
		}
		printf("%lld\n",ans);

	}
	return 0;
};