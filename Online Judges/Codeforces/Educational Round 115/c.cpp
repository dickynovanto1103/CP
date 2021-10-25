//haram karena make int128
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
typedef __int128_t lll;
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
		lll sum = 0;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			sum += a[i];
		}
		// printf("sum: %lld n: %d n-2: %d kali: %lld mod: %lld\n", sum, n, n-2, sum * (ll)(n-2), sum * (n-2) % n);
		if(sum * (ll)(n-2) % (ll)n != 0){
			puts("0");
			continue;
		}
		sort(a,a+n);

		ll anotherSum = sum * (n-2) / n;
		ll ans = 0;
		for(i=0;i<n;i++){
			int ambil = a[i];
			int another = sum - anotherSum - ambil;
			if(another < 0) continue;
			int lower = lower_bound(a+i+1, a+n, another) - a;
			int upper = upper_bound(a+i+1, a+n, another) - a;
			ans += (upper - lower);
		}
		printf("%lld\n", ans);
	}
	
	return 0;
};

// 39999600000000000000
// 9223372036854775808