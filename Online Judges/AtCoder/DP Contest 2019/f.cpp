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

const int maxn = 3e3 + 3;

int dp[maxn][maxn];
string kata1, kata2;

void trace(int r, int c) {
	char ans[3001];
	int rawal = r, cawal = c;
	int idx = dp[r][c];
	while(r > 0 && c > 0){
		if(kata1[r-1] == kata2[c-1]){
			// printf("r: %d c: %d %c\n",r,c,kata1[r-1]);
			ans[idx] = kata1[r-1];

			r--; c--; idx--;
		}else if(dp[r-1][c] > dp[r][c-1]){
			r--;
		}else{
			c--;
		}
	}
	for(int i=1;i<=dp[rawal][cawal];i++){
		printf("%c",ans[i]);
	}
	printf("\n");
}

int main(){
	int i,j;
	cin>>kata1>>kata2;
	int pjg1 = kata1.length(), pjg2 = kata2.length();
	for(i=1;i<=pjg1;i++){
		for(j=1;j<=pjg2;j++){
			if(kata1[i-1] == kata2[j-1]){
				dp[i][j] = max(1 + dp[i-1][j-1], max(dp[i-1][j], dp[i][j-1]));
			}else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	// for(i=1;i<=pjg1;i++){
	// 	for(j=1;j<=pjg2;j++){
	// 		printf("%d ",dp[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("%d\n",dp[pjg1][pjg2]);
	trace(pjg1, pjg2);
	// for(i=ans.length()-1;i>=0;i--){
	// 	printf("%c",ans[i]);
	// }
	// printf("\n");
	return 0;
};