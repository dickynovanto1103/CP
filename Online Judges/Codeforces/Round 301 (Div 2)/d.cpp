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

const int maxn = 101;

double dp[maxn][maxn][maxn];


int main(){
	int i,j,k,l;
	
	for(j=0;j<maxn;j++){
		for(k=0;k<maxn;k++){
			for(l=0;l<maxn;l++){
				dp[j][k][l] = 0;
			}
		}
	}
	
	int r,s,p;
	scanf("%d %d %d",&r,&s,&p);

	dp[r][s][p] = 1.0;

	for(i=r;i>=0;i--){
		for(j=s;j>=0;j--){
			for(k=p;k>=0;k--){
				int banyakKombinasi = i*j + i*k + j*k;
				int banyakBatuKetemuGunting = i*j, banyakBatuKetemuKertas = i*k, banyakGuntingKetemuKertas = j*k;

				if(i>0){
					if(banyakBatuKetemuKertas == 0){
						
					}else{
						dp[i-1][j][k] += dp[i][j][k]*((double)banyakBatuKetemuKertas/(double)banyakKombinasi);
					}
				}
				if(j>0){
					if(banyakBatuKetemuGunting == 0){
					}else{
						dp[i][j-1][k] += dp[i][j][k]*((double)banyakBatuKetemuGunting/(double)banyakKombinasi);		
					}
				}
				if(k>0){
					if(banyakGuntingKetemuKertas == 0){
					}else{
						dp[i][j][k-1] += dp[i][j][k]*((double)banyakGuntingKetemuKertas/(double)banyakKombinasi);	
					}
					
				}
			}
		}
	}

	// for(i=0;i<=r;i++){
	// 	for(j=0;j<=s;j++){
	// 		for(k=0;k<=p;k++){
	// 			printf("dp[%d][%d][%d]: %lf\n",i,j,k,dp[i][j][k]);
	// 		}
	// 	}
	// }

	double ans1 = 0, ans2 = 0, ans3 = 0;
	for(i=0;i<=r;i++){
		ans1+=dp[i][0][0];
		// printf("dp: %lf\n",dp[i][0][0]);
	}
	for(i=0;i<=s;i++){
		ans2+=dp[0][i][0];
	}
	for(i=0;i<=p;i++){
		ans3+=dp[0][0][i];
	}

	printf("%.10lf %.10lf %.10lf\n",ans1,ans2,ans3);

	return 0;
};