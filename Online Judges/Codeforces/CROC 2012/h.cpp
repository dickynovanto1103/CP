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
bool isPalindrome[maxn][maxn];

int main(){
	string kata;
	int q,n,i,j;
	cin>>kata;
	n = kata.length();

	memset(isPalindrome, false, sizeof isPalindrome);
	for(i=0;i<n;i++){
		dp[i][i] = 1;
		isPalindrome[i][i] = true;
	}
	//cek dengan panjang 2
	for(i=0;i<(n-1);i++){
		int j = i+1;
		dp[i][j] = dp[i+1][j] + dp[i][j-1];
		if(kata[i] == kata[j]){
			isPalindrome[i][j] = true;
			dp[i][j]++;
		}
	}

	for(int gap=2;gap<=n;gap++){
		for(i=0;i<(n-gap);i++){
			j = i+gap;
			if(kata[j] == kata[i] && isPalindrome[i+1][j-1]){
				isPalindrome[i][j] = true;
			}

			dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
			if(isPalindrome[i][j]){
				dp[i][j]++;
			}
		}
	}
	
	scanf("%d",&q);
	while(q--){
		int a,b;
		scanf("%d %d",&a,&b);
		a--; b--;
		printf("%d\n",dp[a][b]);
	}
	return 0;
};