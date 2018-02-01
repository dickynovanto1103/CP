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
struct Mat{
	ll mat[maxn][maxn];
};

const ll mod = 1e9 + 7;



Mat multiply(Mat a, Mat b){
	Mat hasil;
	int i,j,k;
	for(i=0;i<maxn;i++){
		for(k=0;k<maxn;k++){
			ll sum = 0;
			for(j=0;j<maxn;j++){
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

Mat modPow(Mat a, ll b){
	Mat ans; int i,j;
	if(b==0){return identity;}
	else{
		if(b%2==1){return multiply(a,modPow(a,b-1));}
		else{
			Mat temp = modPow(a,b/2);
			return multiply(temp,temp);
		}
	}
}

int main(){
	ll n,a,b;
	int i,j;
	int tc;
	for(i=0;i<maxn;i++){
		for(j=0;j<maxn;j++){
			identity.mat[i][j] = (i==j);
		}
	}
	
	scanf("%d",&tc);
	while(tc--){
		scanf("%lld %lld %lld",&a,&b,&n);
		
		Mat pengali,temp;

		pengali.mat[0][0] = 0;
		pengali.mat[0][1] = pengali.mat[1][1] = pengali.mat[1][0] = 1;
		Mat sementara = modPow(pengali,n);
		
		memset(temp.mat, 0, sizeof temp.mat);
		temp.mat[0][0] = a; temp.mat[1][0] = b;

		Mat hasil = multiply(sementara, temp);

		printf("%lld\n",hasil.mat[0][0]);
	}
	

	return 0;
};