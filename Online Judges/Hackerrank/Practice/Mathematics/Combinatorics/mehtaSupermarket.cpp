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

uint64_t lcm(uint64_t a, uint64_t b) {
	uint64_t gcd = __gcd(a,b);
	return a*(b/gcd);
}

uint64_t lcmArr[150000];
int cnt[150000];

uint64_t banyak(uint64_t l, uint64_t r, uint64_t val) {
	// assert(r >= l);
	uint64_t val1 = r/val;
	uint64_t val2 = (l-1)/val;
	assert(val > 0);
	// assert(val1 >= val2);
	return val1 - val2;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[18];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	for(i=0;i<(1<<n);i++){
		int bil = 0;
		ll lcmVal = 1;
		for(j=0;j<n;j++){
			if((1<<j) & i){
				cnt[i]++;
				bil += (1<<j);
				lcmVal = lcm(lcmVal, a[j]);
			}
		}
		lcmArr[i] = lcmVal;
	}
	int d;
	scanf("%d",&d);
	for(i=0;i<d;i++){
		ll l, r;
		scanf("%lld %lld",&l,&r);
		uint64_t ans = 0;
		for(j=1;j<(1<<n);j++){
			uint64_t pengali = -1;
			if(cnt[j] & 1){pengali = 1;}
			uint64_t jawab = banyak(l, r, lcmArr[j]);
			// assert(jawab >= 0);
			// printf("jawab: %lld cnt[%d]: %d\n",jawab, j, cnt[j]);
			uint64_t temp = pengali * jawab;
			// printf("temp: %lld\n",temp);
			ans += temp;
			// printf("ans: %lld\n", ans);
		}
		cout<<ans<<endl;
		// printf("%lld\n",ans);
	}
	return 0;
};