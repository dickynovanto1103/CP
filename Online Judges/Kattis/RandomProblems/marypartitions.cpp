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

int dp[10001];
int m;

int solve(int sisa) {
	if(sisa == 0){return 1;}
	if(dp[sisa] != -1){return dp[sisa];}
	int awal = 1,i;
	int ans = 0;
	for(i=awal;i<=sisa;i*=m){
		printf("sisa awal: %d i: %d jd: %d\n",sisa, i, sisa - i);
		ans += solve(sisa - i);
	}
	return dp[sisa] = ans;
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		int dum, n;
		scanf("%d %d %d",&dum,&m,&n);
		memset(dp, 0, sizeof dp);
		for(i=0;i<m;i++){dp[i] = 1;}
		dp[m] = 2;
		for(i=m+1;i<=n;i++){
			printf("i: %d\n",i);
			set<ii> s;
			for(j=1;j<i;j*=m){
				
				int minim = min(j, i-j), maks = max(j, i-j);
				if(!s.count(ii(minim, maks))){
					s.insert(ii(minim, maks));
					dp[i] += dp[j];
					printf("dp[%d] ditambah dp[%d]: %d dan dp[%d]: %d jd: %d\n",i, j, dp[j], i-j, dp[i-j], dp[i]);
				}
				
			}
		}
		// for(i=m;i<=n;i++){
		// 	dp[i] = 1;
		// 	for(j=m;j<=i;j*=m){
		// 		dp[i] += dp[i-j];
		// 	}
		// }
		for(i=0;i<=n;i++)
			printf("dp[%d]: %d\n",i,dp[i]);
		printf("%d %d\n",dum, dp[n]);
	}
	return 0;
};