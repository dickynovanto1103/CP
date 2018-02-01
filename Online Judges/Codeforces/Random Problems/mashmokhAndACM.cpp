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
ll dp[2002][2002];

int main(){
	int n,k,i,j,batas;
	scanf("%d %d",&n,&batas);
	for(i=1;i<=n;i++){dp[1][i] = 1;}
	for(i=2;i<=batas;i++){
		for(j=1;j<=n;j++){
			for(k=j;k<=n;k+=j){
				dp[i][j]+=dp[i-1][k];
				dp[i][j]%=mod;
			}
		}
	}
	// printf("tabel\n");
	// for(i=1;i<=batas;i++){
	// 	for(j=1;j<=n;j++){
	// 		if(j>1){printf(" ");}
	// 		printf("%lld",dp[i][j]);
	// 	}
	// 	printf("\n");
	// }
	ll ans = 0;
	for(i=1;i<=n;i++){ans+=dp[batas][i]; ans%=mod;}
	printf("%lld\n",ans);
	return 0;
};