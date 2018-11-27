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

const ll mod = 1e9 + 7;
const int maxn = 1e5 + 5;
int dp[maxn];

int main(){
	int n,i,j;
	int a[maxn];
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dp[0] = 1;
	int div[1000];
	for(i=1;i<=n;i++){
		//cari semua divisor
		int cnt = 0;
		for(j=1;j*j<=a[i];j++){
			if(a[i]%j == 0){
				int bil1 = a[i]/j, bil2 = j;
				if(bil1 == bil2){
					div[cnt++] = bil1;
				}else{
					div[cnt++] = bil1;
					div[cnt++] = bil2;	
				}
				
			}
		}
		sort(div, div+cnt);

		for(j=cnt-1;j>=0;j--){
			int bil = div[j];
			if(bil > n){continue;}
			dp[bil] += dp[bil-1];
			dp[bil] %= mod;
			
		}
	}
	int ans = 0;
	for(i=1;i<=n;i++){
		ans += dp[i];
		// printf("dp[%d][%d]: %lld\n",idx,i,dp[idx][i]);
		ans %= mod;
	}
	printf("%d\n",ans);
	return 0;
};