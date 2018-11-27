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

int a,b;
ll dp[14][14];

ll solve(int pertama, int kedua){
	if(pertama == a && kedua == b){return 1;}
	if(pertama > a || kedua > b){return 0;}
	if(dp[pertama][kedua]!=-1){return dp[pertama][kedua];}
	ll ans = solve(pertama+1, kedua) + solve(pertama, kedua+1);
	return dp[pertama][kedua] = ans;
}

int main(){
	int i,j;
	while(scanf("%d %d",&a,&b), a!=-1 && b!=-1){
		memset(dp,-1,sizeof dp);
		ll ans = solve(0,0);
		if(ans == (a+b)){
			printf("%d+%d=%d\n",a,b,a+b);
		}else{
			printf("%d+%d!=%d\n",a,b,a+b);
		}
	}
	return 0;
};