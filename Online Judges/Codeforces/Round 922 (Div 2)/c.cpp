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

bool isIthBitOn(ll a, int i) {
	return ((1LL<<i) & a) > 0;
}

void printBinary(ll a) {
	for(int i=62;i>=0;i--){
		if((1LL<<i) & a) {
			printf("1");
		}else{
			printf("0");
		}
	}
	puts("");
}

void solve(){
	ll a, b, r;
	scanf("%lld %lld %lld",&a,&b,&r);

	// printf("a: %lld b: %lld, r: %lld\n", a, b, r);
	// printBinary(a);
	// printBinary(b);
	// for(int x=0;x<=3*max(a, b);x++) {
	// 	printf("x: %lld, result: abs(%lld - %lld): %lld\n", x, a^x, b^x, abs((a^x) - (b^x)));
	// }

	//finding x, the idea is to find the differing bit digits...we take note of those...x ideally is the bit on for all the different bits, except the most significant bit
	// however, x is limited by r, so we should try to reduce x to be <= r

	vi bitsA, bitsB;
	int biggest = -1;
	for(int i=0;i<=62;i++){
		int isA = isIthBitOn(a, i);
		int isB = isIthBitOn(b, i);
		if(isA ^ isB) {
			if(isA) {
				bitsA.pb(i);
				biggest = 0;
			}else{
				bitsB.pb(i);
				biggest = 1;
			}
		}
	}

	// check which one has the biggest
	if(biggest == 1) {
		swap(bitsA, bitsB);
	}

	ll minAns = abs(a - b);

	ll x = 0;
	for(int i=bitsA.size() - 2;i>=0;i--) {
		if((x + (1LL<<bitsA[i])) <= r) {
			x |= (1LL<<bitsA[i]);
			minAns = min(minAns, abs((a^x) - (b^x)));
		}
		
	}

	printf("%lld\n", minAns);
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};