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

const int maxn = 301;

double dp[maxn][maxn][maxn];

int n;

int tot;

double solve(int cnt1, int cnt2, int cnt3) {
	// printf("cnt1: %d cnt2: %d cnt3: %d\n",cnt1, cnt2, cnt3);
	if(cnt1 == 0 && cnt2 == 0 && cnt3 == 0){
		// printf("halo\n");
		return 0;
	}
	if(fabs(dp[cnt1][cnt2][cnt3] + 1) > eps){return dp[cnt1][cnt2][cnt3];}
	double ans1 = 0, ans2 = 0, ans3 = 0;
	int sisa = n - cnt1 - cnt2 - cnt3;

	if(cnt1 > 0){
		ans1 = ((double)cnt1/(double)(cnt1+cnt2+cnt3))*solve(cnt1-1, cnt2, cnt3);	
	}
	if(cnt2 > 0){
		ans2 = ((double)cnt2/(double)(cnt1+cnt2+cnt3))*solve(cnt1+1, cnt2-1, cnt3);	
	}
	if(cnt3 > 0){
		ans3 = ((double)cnt3/(double)(cnt1+cnt2+cnt3))*solve(cnt1, cnt2+1, cnt3-1);
	}
	// printf("ans1 : %lf ans2 : %lf ans3 : %lf\n",ans1,ans2,ans3);
	// printf("cnt1: %d cnt2: %d cnt3: %d\n",cnt1, cnt2, cnt3);
	
	return dp[cnt1][cnt2][cnt3] = ((double)1.0 / (double)(cnt1+cnt2+cnt3)) +  ans1 + ans2 + ans3;
}

int main(){
	int i,j,k;
	for(i=0;i<maxn;i++){
		for(j=0;j<maxn;j++){
			for(k=0;k<maxn;k++){
				dp[i][j][k] = -1;
			}
		}
	}

	scanf("%d",&n);
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	for(i=0;i<n;i++){
		int bil;
		scanf("%d",&bil);
		if(bil == 1){cnt1++;}
		else if(bil == 2){cnt2++;}
		else{cnt3++;}
	}
	// printf("cnt1: %d cnt2: %d cnt3: %d\n",cnt1,cnt2,cnt3);
	tot = cnt1 + cnt2 + cnt3;
	printf("%.10lf\n",solve(cnt1, cnt2, cnt3)*n);
	return 0;
};