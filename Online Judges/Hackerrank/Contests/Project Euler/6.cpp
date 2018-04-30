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

int main(){
	int i,j,tc;
	ll n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%lld",&n);
		ll sum[10010];
		sum[0] = 0;
		for(i=1;i<=n;i++){
			sum[i] = i + sum[i-1];
		}
		ll ans = 0;
		for(i=1;i<n;i++){
			ans+=((ll)i*(sum[n] - sum[i]));
		}
		ans*=2LL;
		printf("%lld\n",ans);
	}
	return 0;
};