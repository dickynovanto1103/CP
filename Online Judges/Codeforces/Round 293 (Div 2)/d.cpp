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

const int maxn = 2e3 + 3;

double dp[maxn][maxn];
int n,t;
double p;

double solve(int idx, int banyak){
	if(idx == t){
		return banyak;
	}
	if(fabs(dp[idx][banyak] + 1) > eps){
		return dp[idx][banyak];
	}
	double ans = 0;
	ans += p*solve(idx+1, min(banyak+1,n));
	ans += (1.0 - p)*solve(idx+1, banyak);
	
	return dp[idx][banyak] = ans;
}

int main(){
	int i,j;
	
	scanf("%d %lf %d",&n,&p,&t);
	for(i=0;i<maxn;i++){
		for(j=0;j<maxn;j++){
			dp[i][j] = -1;
		}
	}
	
	double ans = solve(0,0);
	printf("%.9lf\n",ans);
	return 0;
};