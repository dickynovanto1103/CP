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

const int maxn = 1010;
int a[maxn][maxn];
int dp[maxn][maxn];
int find(int rowBawah, int rowAtas, int kolBawah, int kolAtas){
	int i,j,k;
	int maks = -inf;
	for(i=kolBawah;i<=kolAtas;i++){
		for(j=i;j<=kolAtas;j++){
			if(dp[i][j] != -1){maks = max(maks, dp[i][j]); continue;}
			int sum = 0;
			int maksimal = -inf;
			for(k=rowBawah;k<=rowAtas;k++){
				if(i){sum += a[k][j] - a[k][i-1];}
				else{sum += a[k][j];}
				// printf("i; %d j: %d k: %d sum jadi: %d\n",i,j,k,sum);
				if(sum < 0){sum = 0;}
				if(maks < sum){
					maks = sum;
				}
				if(maksimal < sum){
					maksimal = sum;
				}
			}
			dp[i][j] = maksimal;

		}
	}
	return maks;
}

int main(){
	int n,m,i,j;
	clock_t begin, end;
	begin = clock();
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&a[i][j]);
			if(j>0){
				a[i][j] += a[i][j-1];
			}
		}
	}
	int ans = -inf;
	memset(dp,-1,sizeof dp);
	find(0,n-1,0,m-1);
	for(i=0;i<=2;i++){
		memset(dp,-1,sizeof dp);
		for(j=0;j<=2;j++){
			int penguranganRow = 2-i;
			int penguranganKol = 2-j;
			int jawab = find(i,n-1-penguranganRow,j,m-1-penguranganKol);
			if(ans < jawab){
				ans = jawab;
			}
		}
	}
	printf("%d\n",ans);
	cerr << "waktu "<<((double)clock() - (double)begin) / CLOCKS_PER_SEC<<endl;

	return 0;
};