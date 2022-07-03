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

int main(){
	ll l, r;
	while(scanf("%lld %lld",&l,&r) != EOF) {
		ll ans = 1;
		ll i;
		for(i=l;i<r;i++){
			if(__gcd(i, r) == 1){
				ans = max(ans, r - i);
				break;
			}

		}

		for(i=l;i<r-1;i++){
			if(__gcd(i, r-1) == 1) {
				ans = max(ans, r-1-i);
				break;
			}
		}

		for(i=r;i>l;i--){
			if(__gcd(i, l) == 1) {
				ans = max(ans, i - l);
				break;
			}
		}

		for(i=r;i>l+1;i--){
			if(__gcd(i, l+1) == 1) {
				ans = max(ans, i - (l+1));
				break;
			}
		}

		printf("%lld\n", ans);
	}
	
	
	return 0;
};