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

const int maxn = 3001;

int cnt[maxn];
double dp[maxn][maxn];

double solve(int banyak0, int banyak1){
	if(banyak0 == 0 && banyak1 == 0){return 0;}
	if(dp[banyak0][banyak1] < 0){
		double ans = 0;
		double ans1 = (banyak0 == 0? 0: ((double)banyak0/(double)(banyak0+banyak1))*solve(banyak0-1, banyak1+1));
		double ans2 = (banyak1 == 0? 0: ((double)banyak1/(double)(banyak0+banyak1))*solve(banyak0, banyak1-1));
		

		ans = ((double)1.0/(double)(banyak1 + banyak0))+(ans1 + ans2);
		dp[banyak0][banyak1] = ans;
	}
	return dp[banyak0][banyak1];
}

int main(){
	int k,i,j;
	int n;
	int tc;
	scanf("%d",&tc);
	for(i=0;i<maxn;i++){
		for(j=0;j<maxn;j++){
			dp[i][j] = -1;
		}
	}
	while(tc--){
		scanf("%d %d",&n,&k);
		memset(cnt, 0, sizeof cnt);
		for(i=0;i<k;i++){
			int bil;
			scanf("%d",&bil);
			cnt[bil]++;
		}

		int banyak0 = 0, banyak1 = 0, banyak2 = 0;
		for(i=1;i<=n;i++){
			if(cnt[i] == 0){banyak0++;}
			else if(cnt[i] == 1){banyak1++;}
			else{banyak2++;}
		}
		double ans = solve(banyak0, banyak1);
		printf("%.9lf\n",ans*(double)n);

	}
	return 0;
};