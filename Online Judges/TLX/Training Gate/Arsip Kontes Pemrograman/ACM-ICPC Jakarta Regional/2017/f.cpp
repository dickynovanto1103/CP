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

const int maxn = 1e5 + 5;
int a[maxn];
int counter[3001];
double dp[3001][3001];
int n;
double solve(int d0, int d1){
	// if(d0==0 && d1>0){
	// 	return dp[d0][d1] = 1+((double)d1/(double)n)*solve(d0,d1-1);
	// }
	// if(d0>0 && d1==0){
	// 	return dp[d0][d1] = 1+((double)d0/(double)n)*solve(d0-1,d1+1);
	// }
	if(d0<0){return 0;}
	if(d1<0){return 0;}
	if(d0==0 && d1==0){return 0;}
	//double batas = fabs(dp[d0][d1]+1.0);
	//printf("nilai batas: %.5lf\n",batas);
	if(fabs(dp[d0][d1]+1.0)!=0){
		//printf("masuk sini\n");
		return dp[d0][d1];
	}
	// printf("halo\n");
	//printf("d0: %d d1: %d\n",d0,d1);
	double ans1 = 1.0/(double)(d0+d1);
	//printf("ans1: %.5lf\n",ans1);
	double ans2 = ((double)d0/(double)(d0+d1))*solve(d0-1,d1+1);
	double ans3 = ((double)d1/(double)(d0+d1))*solve(d0,d1-1);

	return dp[d0][d1] =  ans1 + ans2 + ans3;
}

int main(){
	int tc,i,j,k;
	scanf("%d",&tc);
	for(i=0;i<=3000;i++){
		for(j=0;j<=3000;j++){
			dp[i][j] = -1.0;
		}
	}

	while(tc--){
		memset(counter,0,sizeof counter);
		scanf("%d %d",&n,&k);
		int cnt0=0, cnt1=0,cnt2=0;
		for(i=0;i<k;i++){
			scanf("%d",&a[i]);
			counter[a[i]]++;
		}
		for(i=1;i<=n;i++){
			if(counter[i]==0){
				cnt0++;
			}else if(counter[i]==1){
				cnt1++;
			}else{
				cnt2++;
			}
		}
		//printf("cnt0: %d cnt1: %d cnt2: %d\n",cnt0,cnt1,cnt2);
		double ans = (double)n*solve(cnt0,cnt1);
		printf("%.10lf\n",ans);
	}
	return 0;
};