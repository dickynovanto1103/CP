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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const ll mod = 1e9 + 7;

ll modPoww(ll a, ll b){
	if(b==0){return 1;}
	else{
		if(b%2 == 1){
			return a*modPoww(a,b-1)%mod;
		}else{
			ll temp = modPoww(a,b/2);
			return temp*temp%mod;
		}
	}
}

struct Mat{
	ll mat[5][5];
};

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

Mat modPow(Mat a, ll b, int ukuran){
	Mat ans; int i,j;
	for(i=0;i<ukuran;i++){
		for(j=0;j<ukuran;j++){
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

int main(){
	int i,j;
	ll n,f1,f2,f3,c;
	scanf("%lld %lld %lld %lld %lld",&n,&f1,&f2,&f3,&c);
	Mat trans, kali;
	for(i=0;i<5;i++){

		for(j=0;j<5;j++){
			if(i == 0){
				if(j < 4){trans.mat[i][j] = 1;}
				else{trans.mat[i][j] = 0;}
			}else if(i == 1){
				if(j == 0){trans.mat[i][j] = 1;}
				else{trans.mat[i][j] = 0;}
			}else if(i == 2){
				if(j==1){trans.mat[i][j] = 1;}
				else{trans.mat[i][j] = 0;}
			}else if(i == 3){
				if(j < 3){trans.mat[i][j] = 0;}
				else{trans.mat[i][j] = 1;}
			}else{
				if(j == 4){trans.mat[i][j] = 1;}
				else{trans.mat[i][j] = 0;}
			}
		}
	}
	for(i=0;i<5;i++){
		if(i<3){kali.mat[i][0] = 0;}
		else{kali.mat[i][0] = 2;}
	}
	Mat hasil = multiply(modPow(trans, n-3, 5), kali, 5);
	ll pangkatC = 2LL*(hasil.mat[0][3] + hasil.mat[0][4]);
	pangkatC %= (mod-1);
	Mat pengali, transform;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(i == 2){transform.mat[i][j] = 1;}
			else{
				if(j == (i+1)){transform.mat[i][j] = 1;}
				else{transform.mat[i][j] = 0;}
			}
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			pengali.mat[i][j] = 0;
		}
	}

	pengali.mat[0][0] = 1;
	Mat hasilModPow = modPow(transform, n-3, 3);
	// printf("hasilModPow\n");
	// for(i=0;i<3;i++){
	// 	for(j=0;j<3;j++){
	// 		printf("%lld ",hasilModPow.mat[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("\n");
	Mat hasil1 = multiply(modPow(transform, n-3, 3), pengali, 3);

	pengali.mat[0][0] = 0;
	pengali.mat[1][0] = 1;
	Mat hasil2 = multiply(modPow(transform, n-3, 3), pengali, 3);

	pengali.mat[1][0] = 0;
	pengali.mat[2][0] = 1;
	Mat hasil3 = multiply(modPow(transform, n-3, 3), pengali, 3);
	// printf("%lld %lld %lld\n", hasil1.mat[2][0], hasil2.mat[2][0], hasil3.mat[2][0]);
	ll ans = modPoww(c, pangkatC);
	ans *= modPoww(f1, hasil1.mat[2][0]);
	ans %= mod;
	ans *= modPoww(f2, hasil2.mat[2][0]);
	ans %= mod;
	ans *= modPoww(f3, hasil3.mat[2][0]);
	ans %= mod;
	printf("%lld\n",ans);
	// printf("pangkatC: %lld\n",pangkatC);
	return 0;
};