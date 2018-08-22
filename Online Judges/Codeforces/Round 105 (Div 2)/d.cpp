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

const int maxn = 1e3 + 3;
const int princess = 0;
const int dragon = 1;
const int lepas = 2;


double dp[maxn][maxn][3];

double solve(int putih, int hitam, int idx){
	if(putih == 0){return 0;}
	if(hitam == 0){
		if(idx == dragon){return 0;}
		else if(idx == princess){return 1;}
		else{
			if(putih > 1){return 1;}
			else{return 0;}
		}
	}
	if(fabs(dp[putih][hitam][idx] + 1) > eps){return dp[putih][hitam][idx];}
	double jumlahPutih = (double)putih;
	double jumlahHitam = (double)hitam;
	double peluangAmbilPutih = jumlahPutih / (jumlahPutih+jumlahHitam);
	double peluangAmbilHitam = jumlahHitam / (jumlahPutih+jumlahHitam);

	double ans = 0;
	if(idx == princess){
		ans += peluangAmbilPutih;
		ans += peluangAmbilHitam*solve(putih, hitam-1, (idx+1) % 3);
	}else if(idx == dragon){
		ans += peluangAmbilHitam*solve(putih, hitam-1, (idx+1) % 3);
	}else{
		ans += peluangAmbilPutih*solve(putih-1, hitam, (idx+1) % 3);
		ans += peluangAmbilHitam*solve(putih, hitam-1, (idx+1) % 3);
	}

	return dp[putih][hitam][idx] = ans;
}

int main(){
	int i,j,k;
	int w,b;
	for(i=0;i<maxn;i++){
		for(j=0;j<maxn;j++){
			for(k=0;k<3;k++){
				dp[i][j][k] = -1;
			}
		}
	}
	scanf("%d %d",&w,&b);
	double ans = solve(w,b,princess);
	printf("%.11lf\n",ans);
	return 0;
};