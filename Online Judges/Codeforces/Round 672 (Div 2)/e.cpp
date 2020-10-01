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

int dp[81][81][6500]; //dp[idx][sum0 until i][num of pouring] = the minimum number of sum of f[i]^2 until i

void mini(int& a, const int& b){
	a = min(a, b);
}

int main(){
	int n,i,j,a[81],k;
	while(scanf("%d",&n) != EOF) {
		int cnt = 0, sum = 0;

		vi freq0;
		int pref[81];
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(a[i] == 0){
				cnt++;
				sum++;
			}else{
				freq0.pb(cnt);
				cnt = 0;
			}
		}

		freq0.pb(cnt);
		pref[0] = freq0[0];
		for(i=1;i<freq0.size();i++){
			pref[i] = freq0[i] + pref[i-1];
		}

		for(i=0;i<=80;i++){
			for(j=0;j<=80;j++){
				for(k=0;k<=6400;k++){
					dp[i][j][k] = inf;
				}
			}
		}
		dp[0][0][0] = 0;
		//coba melakukan puring diantara freq0 sehingga bisa meminimalkan sum dari freq0[i]^2
		int sz = freq0.size();
		for(i=0;i<sz;i++) {
			for(j=0;j<=sum;j++){
				for(int turn = 0;turn <= n*(n-1)/2; turn++) {
					if(dp[i][j][turn] == inf){continue;} //berarti ga ada path yang bs sampe titik ini, ga perlu ditelusuri lg
					for(int tambah = 0;tambah <= sum - j; tambah++){
						int total0 = tambah + j;
						mini(dp[i+1][total0][turn + abs(pref[i] - total0)], dp[i][j][turn] + (tambah*tambah));
						// printf("dp[%d][%d][%d] jadi: %d\n", i+1, total0, turn + abs(pref[i] - total0), dp[i+1][total0][turn + abs(pref[i] - total0)]);
					}
				}
			}
		}
		int minim = inf;
		for(int turn = 0; turn <= n*(n-1)/2; turn++) {
			minim = min(minim, dp[sz][sum][turn]); //perlu melakukan ini karena bs jadi ga perlu gerak sampe exactly turn, jadi ambil minimal aja
			int ans = (sum*sum - minim)/2;
			if(turn){printf(" ");}
			printf("%d",ans);
		}
		printf("\n");
	}
	

	return 0;
};