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

const int maxn = 6102;

int dp[maxn][maxn];

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	while(tc--){
		string kata, rev;
		cin>>kata;
		rev = kata;
		reverse(rev.begin(), rev.end());
		n = kata.length();
		for(i=0;i<=n;i++){
			dp[i][0] = 0;
		}
		for(j=0;j<=n;j++){
			dp[0][j] = 0;
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				char kar1 = kata[i-1], kar2 = rev[j-1];
				if(kar1 != kar2){
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}else{
					dp[i][j] = dp[i-1][j-1] + 1;
				}
			}
		}
		int ans = n - dp[n][n];
		printf("%d\n",ans);
	}
	return 0;
};