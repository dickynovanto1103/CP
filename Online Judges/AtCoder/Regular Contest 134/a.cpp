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

ll a[100010];

int main(){
	ll n, l, w;
	while(scanf("%lld %lld %lld",&n,&l,&w) != EOF) {
		for(int i=0;i<n;i++){
			scanf("%lld",&a[i]);
		}
		a[n] = l;

		ll start = 0;
		ll banyak = 0;
		for(int i=0;i<=n;i++){
			ll selisih = a[i] - start;
			// printf("a[%d]: %lld start: %lld selisih: %lld\n", i, a[i], start, selisih);
			start = a[i] + w;
			if(selisih <= 0){
				continue;
			}
			banyak += ((selisih + w - 1) / w);
			// printf("banyak: %lld\n", banyak);
			
		}

		printf("%lld\n", banyak);
	}

	
	return 0;
};