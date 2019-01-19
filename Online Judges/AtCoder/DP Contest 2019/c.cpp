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

const int maxn = 1e5 + 5;

int main(){
	int n,i,j;
	int a[maxn][4];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<3;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int dp[maxn][4];
	memset(dp, 0, sizeof dp);
	for(i=0;i<3;i++){dp[0][i] = a[0][i];}
	for(i=1;i<n;i++){
		for(j=0;j<3;j++){
			for(int k=0;k<3;k++){
				if(k != j){
					dp[i][j] = max(dp[i][j], dp[i-1][k] + a[i][j]);	
				}
				
			}
			
		}
	}
	printf("%d\n",max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2])));
	return 0;
};