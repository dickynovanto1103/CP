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

int getIdx(int idx, int minus, int row) {
	idx -= minus;
	return (idx + row) % row;
}

void maks(int& a, int b){
	a = max(a, b);
}

int a[12][1011];
int dp[1<<12];

int main(){
	int tc;
	scanf("%d",&tc);
	
	while(tc--){
		int n,m,i,j,k;
		scanf("%d %d",&n,&m);
		memset(dp, 0, sizeof dp);
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				scanf("%d",&a[i][j]);
			}
		}
		for(int col = 0; col < m; col++) {
			printf("col: %d\n",col);
			for(i=0;i<(1<<n);i++){
				for(j=0;j<n;j++){
					for(k=0;k<n;k++){
						//idx ke k minus j
						int newIdx = getIdx(k, j, n);
						if(!((1<<newIdx) & i)) {
							maks(dp[i|(1<<newIdx)], dp[i] + a[k][col]);
						}
					}
				}
			}
		}
		int ans = dp[(1<<n)-1];
		// for(i=0;i<m;i++){
		// 	printf("i: %d => %d\n",i, dp[(1<<n)-1][i]);
		// 	ans = max(ans, dp[(1<<n)-1][i]);
		// }
		printf("%d\n",ans);
		
	}
	return 0;
};