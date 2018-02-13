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

const int maxn = 10;
struct Mat{
	ll mat[maxn][maxn];
};

const ll mod = 1e9;

Mat multiply(Mat a, Mat b, int ukuran){
	Mat hasil;
	int i,j,k;
	for(i=0;i<ukuran;i++){
		for(k=0;k<ukuran;k++){
			ll sum = 0;
			for(j=0;j<ukuran;j++){
				ll ans = (a.mat[i][j]%mod*b.mat[j][k]%mod)%mod;
				sum+=ans;
				sum%=mod;
			}
			hasil.mat[i][k] =  sum;
		}
	}
	return hasil;
}

Mat identity;

Mat modPow(Mat a, ll b, int ukuran){
	Mat ans; int i,j;
	if(b==0){return identity;}
	else{
		if(b%2==1){return multiply(a,modPow(a,b-1, ukuran), ukuran);}
		else{
			Mat temp = modPow(a,b/2,ukuran);
			return multiply(temp,temp, ukuran);
		}
	}
}

int main(){
	int k,n,b[13], c[13],i,j,tc;
	Mat pengali;
	scanf("%d",&tc);
	for(i=0;i<maxn;i++){ //bikin matriks identitas
		for(j=0;j<maxn;j++){
			identity.mat[i][j] = (i==j);
		}
	}

	while(tc--){
		scanf("%d",&k);
		Mat transform;
		for(i=0;i<k;i++){
			scanf("%d",&b[i]);
			pengali.mat[i][0] = b[i];
		}
		for(i=0;i<k;i++){
			scanf("%d",&c[i]);
		}
		for(i=0;i<k-1;i++){
			for(j=0;j<k;j++){
				if(j==(i+1)){
					transform.mat[i][j] = 1;
				}else{
					transform.mat[i][j] = 0;
				}
			}
		}
		for(i=0;i<k;i++){
			transform.mat[k-1][i] = c[k-i-1];
		}
		// printf("matriks transform\n");
		// for(i=0;i<k;i++){
		// 	for(j=0;j<k;j++){
		// 		if(j){printf(" ");}
		// 		printf("%lld",transform.mat[i][j]);
		// 	}
		// 	printf("\n");
		// }
		scanf("%d",&n);
		
		int pangkat = n-1;
		Mat hasil = multiply(modPow(transform,pangkat,k),pengali,k);
		// printf("matriks hasil\n");
		// for(i=0;i<k;i++){
		// 	for(j=0;j<k;j++){
		// 		if(j){printf(" ");}
		// 		printf("%lld",hasil.mat[i][j]);
		// 	}
		// 	printf("\n");
		// }
		printf("%lld\n",hasil.mat[0][0]);
	}
	return 0;
};