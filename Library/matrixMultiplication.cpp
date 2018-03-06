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
const ll mod = 1e9;
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

	return 0;
}