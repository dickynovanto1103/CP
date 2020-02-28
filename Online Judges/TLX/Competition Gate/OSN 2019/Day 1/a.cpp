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

const int maxn = 1e5 + 5;

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	int pref[n+1][m+1];
	memset(pref, 0, sizeof pref);
	char s[n+1][m+1];
	for(i=0;i<n;i++){
		scanf("%s",s[i]);
	}
	int cnt1 = 0;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(s[i][j] == '1') {
				cnt1++;
				pref[i+1][j+1] = 1;
			}
			pref[i+1][j+1] += pref[i][j+1];
			pref[i+1][j+1] += pref[i+1][j];
			pref[i+1][j+1] -= pref[i][j];
			// printf("%d ",pref[i+1][j+1]);
		}
		// printf("\n");
	}

	int ans = inf;
	// printf("cnt1: %d\n",cnt1);
	for(int t=1;t*t<=cnt1;t++){
		if(cnt1 % t == 0) {
			int row = t, col = cnt1/t;
			// printf("row: %d col: %d\n",row, col);
			if(row > n || col > m){continue;}
			for(i=1;i<=n-row+1;i++){
				int nextRow = i+row-1;

				for(j=1;j<=m-col+1;j++){
					int nextCol = j+col-1;

					int banyak = pref[nextRow][nextCol] - pref[nextRow][j-1] - pref[i-1][nextCol] + pref[i-1][j-1];
					// printf("i: %d nextRow: %d j: %d nextCol: %d banyak: %d ans: %d\n",i,nextRow, j, nextCol, banyak, cnt1-banyak);
					ans = min(ans, cnt1 - banyak);
				}
			}
		}
	}
	for(int t=1;t*t<=cnt1;t++){
		if(cnt1 % t == 0) {
			int row = cnt1/t, col = t;
			// printf("row: %d col: %d\n",row, col);
			if(row > n || col > m){continue;}
			for(i=1;i<=n-row+1;i++){
				int nextRow = i+row-1;

				for(j=1;j<=m-col+1;j++){
					int nextCol = j+col-1;

					int banyak = pref[nextRow][nextCol] - pref[nextRow][j-1] - pref[i-1][nextCol] + pref[i-1][j-1];
					// printf("i: %d nextRow: %d j: %d nextCol: %d banyak: %d ans: %d\n",i,nextRow, j, nextCol, banyak, cnt1-banyak);
					ans = min(ans, cnt1 - banyak);
				}
			}
		}
	}
	if(ans == inf){
		printf("-1\n");
	}else{
		printf("%d\n",ans);	
	}
	
	return 0;
};