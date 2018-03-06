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

const int maxn = 33;
const ll mod = 1e9 + 7;
int n,x;
ll dp[maxn];
int a[maxn];

struct Mat{
	ll mat[maxn][maxn];
};

Mat multiply(Mat a, Mat b, int ukuran){
	Mat hasil;
	int i,j,k;
	for(i=1;i<ukuran;i++){
		for(k=1;k<ukuran;k++){
			ll sum = 0;
			for(j=1;j<ukuran;j++){
				ll ans = (a.mat[i][j]%mod*b.mat[j][k]%mod)%mod;
				sum+=ans;
				sum%=mod;
			}
			hasil.mat[i][k] =  sum;
		}
	}
	return hasil;
}

Mat modPow(Mat a, ll b, int ukuran){
	Mat ans; int i,j;
	for(i=1;i<ukuran;i++){
		for(j=1;j<ukuran;j++){
			ans.mat[i][j] = (i==j);
		}
	}
	while(b){
		if(b&1){ans = multiply(ans,a,ukuran);}
		a = multiply(a,a,ukuran);
		b>>=1;
	}
	return ans;
}

ll solve(int bil){
	int i;
	// printf("bil: %d\n",bil);
	if(bil<0){return 0;}
	if(bil==0){return 1;}
	if(dp[bil]!=-1){return dp[bil];}
	ll ans = 0;
	for(i=1;i<=n;i++){
		// printf("a[%d]: %d\n",i,a[i]);
		ans+=solve(bil-a[i]);
		ans%=mod;
	}
	return dp[bil] = ans;
}

Mat pengali;
Mat transform1;

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	// for(i=1;i<maxn;i++){ //bikin matriks identitas
	// 	for(j=1;j<maxn;j++){
	// 		identity.mat[i][j] = (i==j);
	// 	}
	// }
	
	while(tc--){
		memset(dp,-1,sizeof dp);
		memset(a,0,sizeof a);

		scanf("%d %d",&n,&x);
		dp[0] = 1;
		for(i=1;i<=n;i++){scanf("%d",&a[i]);}
		for(i=1;i<maxn;i++){
			dp[i] = 0;
			for(j=1;j<=n;j++){
				if((i-a[j])<0){continue;}
				dp[i]+=dp[i-a[j]];
			}
		}
		//cari banyak cara dari 1 sampe 32
		// for(i=1;i<maxn;i++){
		// 	solve(i);
		// }
		// for(i=1;i<maxn;i++){
		// 	printf("dp[%d]: %lld\n",i,dp[i]);
		// }
		
		for(i=1;i<maxn;i++){
			pengali.mat[i][1] = dp[i];
		}

		
		for(i=1;i<(maxn-1);i++){
			for(j=1;j<maxn;j++){
				if(j==(i+1)){transform1.mat[i][j] = 1;}
				else{transform1.mat[i][j] = 0;}
			}
		}
		//urus baris terakhir
		for(j=1;j<maxn;j++){
			transform1.mat[maxn-1][j] = 0;
		}
		for(j=1;j<maxn;j++){
			transform1.mat[maxn-1][maxn-a[j]] = 1;
		}
		// printf("matriks transform:\n");
		// for(i=1;i<maxn;i++){
		// 	for(j=1;j<maxn;j++){
		// 		if(j){printf(" ");}
		// 		printf("%lld",transform.mat[i][j]);
		// 	}
		// 	printf("\n");
		// }

		//hitung
		Mat hasil = multiply(modPow(transform1,x-1,maxn),pengali,maxn);
		// printf("matriks hasil:\n");
		// for(i=1;i<maxn;i++){
		// 	for(j=1;j<maxn;j++){
		// 		if(j){printf(" ");}
		// 		printf("%lld",hasil.mat[i][j]);
		// 	}
		// 	printf("\n");
		// }
		// printf("matriks hasilPangkat:\n");
		// for(i=1;i<maxn;i++){
		// 	for(j=1;j<maxn;j++){
		// 		if(j){printf(" ");}
		// 		printf("%lld",hasilPangkat.mat[i][j]);
		// 	}
		// 	printf("\n");
		// }
		// printf("matriks pengali:\n");
		// for(i=1;i<maxn;i++){
		// 	for(j=1;j<maxn;j++){
		// 		if(j){printf(" ");}
		// 		printf("%lld",pengali.mat[i][j]);
		// 	}
		// 	printf("\n");
		// }
		printf("%lld\n",hasil.mat[1][1]);
	}
	return 0;
};