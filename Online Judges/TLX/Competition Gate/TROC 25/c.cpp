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

bool cmp(int a, int b) {
	return a < b;
}

vi divisors(ll a){
	vi ans;
	for(int i=1;i*i<=a;i++){

		if(a % i == 0){
			if(i == a/i){
				ans.pb(i);	
			}else{
				ans.pb(i);
				ans.pb(a/i);
			}
			

		}
	}
	sort(ans.begin(), ans.end(), cmp);
	return ans;
}

bool isInRange(ll a){
	return 1 <= a && a <= inf;
}

int main(){
	ll n;
	scanf("%lld",&n);
	ll maksA = 0;
		// printf("n: %d\n", n);
		bool found = false;
		
		for(ll a=n+1;;a++){
			vi divList = divisors(a);
			for(ll div: divList) {
				ll pembilang = (div*div - a*n*div);
				ll penyebut = n*div - a;
				if(penyebut == 0){continue;}
				if(pembilang % penyebut != 0){
					continue;
				} 
				ll b = pembilang / penyebut;
				if(b < 0){continue;}
				// if(a != n+1){
				// 	printf("halo a: %lld\n", a);
				// }
				// if(div != 1){
				// 	printf("halo gcd: %lld\n", div);
				// }
				// if(div )
				if(isInRange(a) && isInRange(b)) {
					printf("%lld %lld\n", a, b);
					// printf("a: %lld b: %lld gcd: %lld\n", a, b, div);	
					maksA = max(maksA, a);
					// printf("maksA: %lld\n", maksA);
					// if(div != 1){
					// 	printf("n: %d gcd: %lld", n, div);
					// }
					found = true;
					break;
				}
				
				// if(div != 1){
				// 	printf("halo\n");
				// }
				
			}
			if(found)break;
			// if((n - 1) % (a - n) != 0) {continue;}
			// ll b = (n-1) / (a-n);
			// if(__gcd(a, b) == 1){printf("a: %lld b: %lld\n", a, b);}
		}
	//10000099999
	//1000000000

	
	// printf("%lld %lld\n", n + 1, -1 + n * n  + n);
	
	return 0;
};