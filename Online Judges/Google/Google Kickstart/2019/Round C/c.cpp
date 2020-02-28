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

const int maxn = 1e3 + 3;

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	int p[maxn];
	int col[maxn];
	ii pas[maxn];
	int dp[maxn][maxn];
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		int n,k;
		scanf("%d %d",&n,&k);
		for(i=1;i<=n;i++){
			scanf("%d",&p[i]);
			pas[i].first = p[i];
		}
		for(i=1;i<=n;i++){
			scanf("%d",&col[i]);
			pas[i].second = col[i];
		}
		sort(pas+1, pas+n+1);
		for(i=1;i<=n;i++){
			p[i] = pas[i].first; col[i] = pas[i].second;
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				dp[i][j] = inf;
			}
		}
		//dp[n][k] = minimal waktu yang diperlukan untuk mengobservasi k dogs dengan sampe observasi n indeks
		dp[1][0] = 0;
		dp[1][1] = p[1];

		for(i=2;i<=n;i++){
			//maks sama adalah i
			dp[i][0] = 0;
			dp[i][1] = p[i];
			for(int l=1;l<=i;l++){
				// dp[i][l] = dp[i-1][l];
				for(j=1;j<i;j++){
					dp[i][l] = min(dp[i][l], dp[j][l-1] + ((col[i] == col[j]) ? (p[i] - p[j]) : (p[j] + p[i])));
				}	
			}
			
		}

		int ans = inf;
		for(i=1;i<=n;i++){
			ans = min(ans, dp[i][k]);
		}
		printf("%d\n",ans );
	}
	return 0;
};