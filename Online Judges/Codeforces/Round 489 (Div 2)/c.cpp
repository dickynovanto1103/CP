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

const int maxn = 2;
const ll mod = 1e9 + 7;
struct Mat{
	ll mat[maxn][maxn];
};

Mat multiply(Mat a, Mat b, int ukuran){
	Mat hasil;
	int i,j,k;
	
	for(i=0;i<ukuran;i++){
		for(k=0;k<ukuran;k++){
			ll sum = 0;
			for(j=0;j<ukuran;j++){
				ll ans = ((a.mat[i][j]%mod)*(b.mat[j][k]%mod))%mod;
				sum+=ans;
				sum%=mod;
				if(sum<0){sum+=mod;}
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

ll modPowBil(ll a, ll b){
	if(b==0){
		return 1;
	}else{
		if(b%2==1){
			return ((a%mod)*(modPowBil(a,b-1)%mod))%mod;
		}else{
			ll temp = modPowBil(a,b/2);
			return ((temp%mod)*(temp%mod)) % mod;
		}
	}
}

int main(){
	ll x,k;
	int i,j;
	scanf("%lld %lld",&x,&k);
	if(x==0){printf("0\n"); return 0;}

	identity.mat[0][0] = 1;
	identity.mat[1][1] = 1;
	identity.mat[0][1] = 0;
	identity.mat[1][0] = 0;

	Mat transformMatrix;
	transformMatrix.mat[0][0] = 4;
	transformMatrix.mat[0][1] = -1;
	transformMatrix.mat[1][0] = 0;
	transformMatrix.mat[1][1] = 2;

	Mat pengali;
	pengali.mat[0][0] = x;
	pengali.mat[0][1] = 0;
	pengali.mat[1][0] = 1;
	pengali.mat[1][1] = 0;

	Mat matrixPangkat = modPow(transformMatrix, k, 2);
	
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			if(matrixPangkat.mat[i][j] < 0){matrixPangkat.mat[i][j]+=mod;}
		}
	}

	Mat hasil = multiply(matrixPangkat, pengali, 2);
	ll jawab = hasil.mat[0][0];
	jawab*=2LL;
	jawab%=mod;
	if(jawab<0){jawab+=mod;}
	
	ll pangkatBaru = k%(mod-1LL);
	
	ll bagi = modPowBil(2LL, mod-1LL-pangkatBaru);
	
	ll ans;
	ans = (bagi*jawab)%mod;

	printf("%lld\n",ans);
	return 0;
}