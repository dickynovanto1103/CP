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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 2e5 + 5;

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	int a[maxn];
	while(tc--){
		scanf("%d", &n);
		ll sum = 0;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			sum += a[i];
		}

		if(2LL * sum % n > 0) {puts("0"); continue;}

		sort(a, a+n);

		ll toRemove = 2LL * sum / n;
		ll ans = 0;
		for(i=0;i<n;i++){
			int ambil = a[i];
			ll target = toRemove - ambil;
			int lower = lower_bound(a+i+1, a+n, target) - a;
			int upper = upper_bound(a+i+1, a+n, target) - a;
			ans += (upper - lower);
		}
		printf("%lld\n", ans);
		
	}
	
	return 0;
};
