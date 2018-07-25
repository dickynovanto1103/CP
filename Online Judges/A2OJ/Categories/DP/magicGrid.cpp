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

const int maxn =501;
int dp[maxn][maxn];
int a[maxn][maxn];
int r,c;
int dx[] = {0,1};
int dy[] = {1,0};

bool can(int input){
	int i,j;

	dp[0][0] = input;
	for(i=1;i<r;i++){
		if(dp[i-1][0] == -1){
			dp[i][0] = -1;
			continue;
		}

		int hasilAkhir = dp[i-1][0] + a[i][0];
		if(hasilAkhir > 0){
			dp[i][0] = hasilAkhir;
		}else{
			dp[i][0] = -1;
		}
	}

	for(i=1;i<c;i++){
		if(dp[0][i-1] == -1){
			dp[0][i] = -1; 
			continue;
		}

		int hasilAkhir = dp[0][i-1] + a[0][i];
		
		if(hasilAkhir > 0){
			dp[0][i] = hasilAkhir;
		}else{
			dp[0][i] = -1;
		}
	}

	for(i=1;i<r;i++){
		for(j=1;j<c;j++){
			int maksSebelum = max(dp[i-1][j], dp[i][j-1]);
			if(maksSebelum == -1){
				dp[i][j] = -1;
			}else{
				int total = maksSebelum + a[i][j];
				if(total > 0){
					dp[i][j] = total;
				}else{
					dp[i][j] = -1;
				}
			}
		}
	}

	return dp[r-1][c-1] > 0;
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	
	while(tc--){
		scanf("%d %d",&r,&c);
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				scanf("%d",&a[i][j]);
			}
		}

		int kiri = 1, kanan = 1000000, mid;
		int ans = 1;
		while(kiri<=kanan){
			mid = (kiri+kanan)/2;
			if(can(mid)){
				ans = mid;
				kanan = mid-1;
			}else{
				kiri = mid+1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
};