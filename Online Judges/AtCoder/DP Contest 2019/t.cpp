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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 3005;

int dp[maxn][maxn]; //dp[i][j] is the number of valid permutation until index i with j is the last number

const int mod = 1e9 + 7;

void add(int &a, int b){
	if(b < 0){b += mod;}
	a += b;
	if(a < 0){a += mod;}
	if(a >= mod){a -= mod;}
}

int main(){
	int n,i,j,k;
	string kata;
	scanf("%d",&n);
	cin>>kata;

	for(i=1;i<=n;i++){
		dp[1][i] = 1;
	}
	int pref[n+1];
	
	for(i=2;i<=n;i++){
		memset(pref, 0, sizeof pref);
		for(j=1;j<i;j++) {
			pref[j] = dp[i-1][j];
			add(pref[j], pref[j-1]);
		}
		for(j=1;j<=i;j++){ //mau coba place dari 1 sampe i
			if(kata[i-2] == '>'){
				add(dp[i][j], pref[j-1]);
				// for(k=1;k<j;k++){
				// 	add(dp[i][j], dp[i-1][k]);
				// }
			}else{
				add(dp[i][j], pref[i-1] - pref[j-1]);
				// for(k=j;k<i;k++){
				// 	add(dp[i][j], dp[i-1][k]);
				// }
			}
		}
	}
	int ans = 0;
	for(i=1;i<=n;i++){
		add(ans, dp[n][i]);
	}
	printf("%d\n",ans);
	return 0;
};