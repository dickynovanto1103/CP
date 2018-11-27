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

int n,k;
const int maxn = 501;
int dp[2][2000001];

int w[maxn], val[maxn];

int main(){
	int i,j;
	scanf("%d %d",&k,&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&val[i],&w[i]);
	}
	
	for(i=0;i<n;i++){
		if(i%2==0){
			for(j=0;j<=k;j++){
				if(j < w[i]){
					dp[0][j] = dp[1][j];
				}else{
					dp[0][j] = max(val[i] + dp[1][j - w[i]], dp[1][j]);
				}
			}
		}else{
			for(j=0;j<=k;j++){
				if(j < w[i]){
					dp[1][j] = dp[0][j];
				}else{
					dp[1][j] = max(val[i] + dp[0][j - w[i]], dp[0][j]);
				}
			}
		}
	}
	
	int ans;
	if(n%2==1){
		ans = dp[0][k];
	}else{
		ans = dp[1][k];
	}
	printf("%d\n",ans);
	return 0;
};