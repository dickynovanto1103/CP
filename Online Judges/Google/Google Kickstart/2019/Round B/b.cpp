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

const int maxn = 1e2 + 2;

struct pas{
	int s, e, l;
	double b;
};

bool cmp(pas a, pas b){
	return a.b > b.b;
}

int dp[10001];//dp[i][j] = maks value yang dapat diperoleh sampe idx i dan dengan wkatu j

void maks(int &a, int b){
	a = max(a,b);
}

int getNilai(int val, int t, int kurang) {
	return max(0, val - t*kurang);
}

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	pas p[maxn];
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d %d %d",&p[i].s,&p[i].e,&p[i].l);
			p[i].b = (double)p[i].l / (double)p[i].s;
		}
		sort(p,p+n, cmp);
		// for(i=0;i<n;i++){
		// 	printf("%d %d %d\n",p[i].s,p[i].e,p[i].l);
		// }
		
		dp[0] = 0;
		for(j=1;j<=10000;j++){
			dp[j] = -1;
		}
		
		for(i=0;i<n;i++){
			for(j=10000;j>=0;j--){
				if(p[i].s + j > 10000){continue;}
				if(dp[j] == -1){continue;}
				maks(dp[j + p[i].s], dp[j] + getNilai(p[i].e, j, p[i].l));
				// printf("dp[%d][%d]: %d\n", i,j + p[i].s, dp[i][j + p[i].s]);
			}

		}
		// printf("dp[%d][%d]: %d\n",0,5,dp[0][5]);
		int ans = 0;
		for(j=0;j<=10000;j++){
			maks(ans, dp[j]);
		}
		printf("%d\n",ans);

	}
	return 0;
};