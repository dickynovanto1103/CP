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
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int MAXLEN = 2;

struct Mat {
	int r, c;
	int a[MAXLEN][MAXLEN];
};

Mat mul(Mat a, Mat b, int mod) {
	assert(a.c == b.r);
	int i,j,k;

	Mat ans;
	ans.r = a.r; ans.c = b.c;
	for(i=0;i<ans.r;i++){
		for(j=0;j<ans.c;j++){
			ans.a[i][j] = 0;
		}
	}

	for(i=0;i<a.r;i++){
		for(j=0;j<a.c;j++){
			for(k=0;k<b.c;k++){
				ll kali = ((ll)a.a[i][k] * b.a[k][j]);
				kali %= mod;
				if(kali < 0){kali += mod;}

				ans.a[i][j] += kali;
				ans.a[i][j] %= mod;
			}
		}
	}

	return ans;
}

Mat identity;

Mat pow(Mat a, ll power, int mod) {
	if(power == 0){
		return identity;
	} else {
		if(power % 2LL == 1) {
			return mul(a, pow(a, power-1, mod), mod);
		} else {
			Mat temp = pow(a, power / 2LL, mod);
			return mul(temp, temp, mod);
		}
	}
}

Mat initIdentity(int lenRowCol) {
	for(int i=0;i<lenRowCol;i++){
		for(int j=0;j<lenRowCol;j++){
			identity.a[i][j] = (i == j ? 1 : 0);
		}
	}

	identity.r = lenRowCol; identity.c = lenRowCol;
	return identity;
}

void printMatrix(Mat a) {
	for(int i=0;i<a.r;i++){
		for(int j=0;j<a.c;j++){
			printf("%d ",a.a[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int tc,i,j,a,b,m;
	ll k;

	identity = initIdentity(2);

	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %lld %d",&a,&b,&k,&m);
		Mat pengali;
		pengali.r = 2; pengali.c = 2;
		pengali.a[0][0] = a; pengali.a[0][1] = -b;
		pengali.a[1][0] = b; pengali.a[1][1] = a;
		// printMatrix(pengali);
		// printf("\npengali selesai\n");
		if(k == 0){
			printf("1 0\n");
			continue;
		}
		Mat hasil = pow(pengali, k-1, m);
		// printMatrix(hasil);
		// printf("\nhasil selesai\n");

		Mat awal;
		awal.r = 2; awal.c = 2;
		awal.a[0][0] = 0; awal.a[0][1] = a;
		awal.a[1][0] = 0; awal.a[1][1] = b;
		Mat ans = mul(hasil, awal, m);


		printf("%d %d\n",ans.a[0][1], ans.a[1][1]);
	}
	return 0;
};