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

const int maxn = 5e3 + 2;

int dp[maxn][maxn];

int main(){
	int n,i,j;
	scanf("%d",&n);
	string kata;
	cin>>kata;
	string rev = kata;
	reverse(rev.begin(), rev.end());
	// printf("kata: "); cout<<kata<<" rev: "<<rev<<endl;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			char kar1 = kata[i-1], kar2 = rev[j-1];
			if(kar1 == kar2){
				dp[i][j] = dp[i-1][j-1] + 1;
			}else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	printf("%d\n",n-dp[n][n]);
	return 0;
};