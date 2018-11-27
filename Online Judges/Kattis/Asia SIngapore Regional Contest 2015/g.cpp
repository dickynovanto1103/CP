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

const int maxn = 3002;
int dp[maxn];
ll a[maxn];
ll maks[maxn];
ll pref[maxn];


int main(){
	int i,j;
	int n;
	scanf("%d",&n);
	for(i=1;i<=n;i++){scanf("%lld",&a[i]); pref[i] = a[i];}
	for(i=2;i<=n;i++){pref[i] += pref[i-1];}
	dp[1] = 1; maks[1] = a[1];
	for(i=2;i<=n;i++){
		dp[i] = 1, maks[i] = pref[i];
		for(j=1;j<i;j++){
			ll sumSetelah = pref[i] - pref[j];
			if(sumSetelah >= maks[j]){
				if((dp[j] + 1) > dp[i]){
					dp[i] = dp[j]+1;
					maks[i] = sumSetelah;
				}else if((dp[j] + 1) == dp[i]){
					if(sumSetelah < maks[i]){
						maks[i] = sumSetelah;
					}
				}
			}
		}
	}
	int ans = dp[n];
	printf("%d\n",ans);
	return 0;
};