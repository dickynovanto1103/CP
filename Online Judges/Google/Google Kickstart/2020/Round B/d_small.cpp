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

int pet[302][302];
double dp[302][302];

int main(){
	int tc,i,j;
	scanf("%d",&tc);

	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		// printf("\n");
		int n,m,a,b,c,d;
		scanf("%d %d %d %d %d %d",&n,&m,&a,&b,&c,&d);
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				dp[i][j] = 0;
			}
		}
		for(i=a;i<=c;i++){
			for(j=b;j<=d;j++){
				dp[i][j] = 0;
			}
		}
		for(i=c+1;i<=n;i++){
			for(j=1;j<=m;j++){
				// printf("hai\n");
				dp[i][j] = 1;
			}
		}
		for(i=1;i<=n;i++){
			for(j=d+1;j<=m;j++){
				
				dp[i][j] = 1;
			}
		}
		// for(i=1;i<=n;i++){
		// 	for(j=1;j<=m;j++){
		// 		printf("%.2lf ",dp[i][j]);
		// 	}
		// 	printf("\n");
		// }
		//isi kiri lubang
		for(i=c;i>=a;i--){
			for(j=b-1;j>=1;j--){
				double tambah = 0;
				if((j + 1) <= m){tambah += dp[i][j+1];}
				if((i+1) <= n){tambah += dp[i+1][j];}
				dp[i][j] = tambah/2.0;
			}
		}
		//isi atas
		for(i=a-1;i>=1;i--){
			for(j=d;j>=1;j--){
				double tambah = 0;
				if((j + 1) <= m){tambah += dp[i][j+1];}
				if((i+1) <= n){tambah += dp[i+1][j];}
				dp[i][j] = tambah/2.0;
			}
		}
		// printf("akhir\n");
		// for(i=1;i<=n;i++){
		// 	for(j=1;j<=m;j++){
		// 		printf("%.2lf ",dp[i][j]);
		// 	}
		// 	printf("\n");
		// }
		printf("%.7lf\n",dp[1][1]);
	}
	return 0;
};