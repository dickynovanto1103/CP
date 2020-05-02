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
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,n,i;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		ll ans = 0, ans2 = 0;
		ll tot = 0;
		for(i=1;i<=n;i++){
			tot += 1<<i;
		}
		int bagi2 = n/2;
		ans += 1<<n;
		// printf("ans: %lld\n",ans);
		for(i=1;i<bagi2;i++){
			ans += 1<<i;
		}
		// printf("akhir ans: %lld\n",ans);
		// printf("tot: %lld\n", tot);
		ll sisa = tot - ans;
		printf("%lld\n",abs(ans - sisa));
	}
	return 0;
};