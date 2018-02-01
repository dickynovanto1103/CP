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

const int maxn = 5e3 + 3;
const ll mod = 1e9 + 7;
ll dp[maxn][maxn];

int main(){
	int n,i,j;
	char kar, lastKar;
	scanf("%d %c",&n,&lastKar);
	dp[0][0] = 1;//pasti untuk awal-awal cuman ada 1 cara
	for(i=1;i<n;i++){	
		scanf("\n%c",&kar);
		if(lastKar=='f'){
			dp[i][0] = 0;//ga mungkin ada caranya statement itu tiba"mblesek ke indentasi pertama banget
			for(j=n;j>0;j--){dp[i][j] = dp[i-1][j-1];}
		}else{
			ll sum = 0;
			for(j=n;j>=0;j--){
				sum+=dp[i-1][j];
				sum%=mod;
				dp[i][j] = sum;
			}
		}

		lastKar = kar;
	}
	ll ans = 0;
	for(i=0;i<=n;i++){
		ans+=dp[n-1][i];
		ans%=mod;
	}
	printf("%lld\n",ans);
	return 0;
};