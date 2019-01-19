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

const int maxn = 3000;

double dp[maxn][maxn];
double a[maxn];
int n;

double solve(int idx, int head) {
	if(idx == n){
		if(head == 0){return 1;}
		else
			return 0;
	}
	
	if(fabs(dp[idx][head] + 1) > eps){return dp[idx][head];}
	return dp[idx][head] = a[idx] * solve(idx+1, head-1) + (1.0 - a[idx]) * solve(idx+1, head);
}

int main(){
	int i,j;
	for(i=0;i<maxn;i++){
		for(j=0;j<maxn;j++){
			dp[i][j] = -1;
		}
	}
	
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%lf",&a[i]);}
	int minim = n/2 + 1;
	double ans = 0;
	for(i=minim;i<=n;i++){
		ans += solve(0, i);
	}
	printf("%.10lf\n",ans);
	return 0;
};