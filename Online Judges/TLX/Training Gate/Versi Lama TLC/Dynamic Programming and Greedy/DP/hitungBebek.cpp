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

int dp[1000001];

int main(){
	dp[1] = 1;
	dp[2] = 2;
	bool sudah = false;
	int n,i,j;
	scanf("%d",&n);
	if(n<=2){printf("%d\n", n); return 0;}
	for(i=3;i<=1000000;i++){
		dp[i] = dp[i-1] + dp[i-2];
		if(dp[i] > 1000000){
			sudah = true;
		}
		dp[i] %= 1000000;
		if(i==n){break;}
	}
	// printf("sudah: %d\n",sudah);
	if(sudah){
		printf("%.6d\n",dp[n]);	
	}else{
		printf("%d\n",dp[n]);
	}
	
	return 0;
};