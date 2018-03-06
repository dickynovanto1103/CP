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

const int maxn = 1e3 + 2;
int n,s,p;
int k[maxn],v[maxn];
ll dp[maxn][maxn][2];

ll solve(int kota, int sisa, int isOnPlane){
	if(sisa<0){return -inf;}
	if(kota==n){return 0;}
	
	if(dp[kota][sisa][isOnPlane]!=-1){return dp[kota][sisa][isOnPlane];}
	if(isOnPlane==1){return dp[kota][sisa][isOnPlane] = max(solve(kota+1,sisa,isOnPlane), v[kota] + solve(kota+1,sisa-k[kota],0));}
	else{return dp[kota][sisa][isOnPlane] = max(solve(kota+1,sisa-p,1), v[kota] + solve(kota+1,sisa-k[kota],0));}
} 

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		memset(dp,-1,sizeof dp);
		scanf("%d %d %d",&n,&s,&p);
		for(i=1;i<=(n-1);i++){scanf("%d %d",&k[i],&v[i]);}
		ll ans = solve(1,s,0);
		if(ans<0){ans=-1;}
		printf("%lld\n",ans);
	}
	return 0;
};