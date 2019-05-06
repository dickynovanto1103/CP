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

const int maxn = 1e3 + 3;
const int mod = 1e9 + 7;

void maks(int &a, int b){
	a = max(a,b);
}

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		int a[maxn];
		int lis[maxn], dp[maxn];
		memset(dp, 0, sizeof dp);

		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			lis[i] = 1;
		}
		for(i=0;i<n;i++){
			for(j=0;j<i;j++){
				if(a[j] < a[i]){
					maks(lis[i], lis[j] + 1);
				}
			}
			if(lis[i] == 1)
				dp[i] = 1;
			else{
				dp[i] = 0;
				for(j=0;j<i;j++){
					if(a[j] < a[i] && lis[j] == lis[i]-1){
						dp[i] = (dp[i] + dp[j]) % mod;
					}
				}
			}
		}

		int nilaiLIS = *max_element(lis, lis+n);
		int ans = 0;
		for(int i=0;i<n;++i){
			if(lis[i] == nilaiLIS){
				ans = (ans + dp[i]) % mod;
			}
		}
		printf("%d %d\n", nilaiLIS, ans);
	}
	return 0;
};