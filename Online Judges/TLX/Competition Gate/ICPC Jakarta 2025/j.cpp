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

//1100011
//-> kalo and: 01100011
//-> 		   11000110 -> jadi 01000010

// first way to solve it:
// 1. find if there is only single 0 in between 1...so it's like 10, in base 2: 1010...if we do operation OR with 10100...it will be 11110 -> it will merge, and we cannot undo this
//   - but I forget that there is a case like this: 1110111 -> after AND with 11101110, we can reduce it to 1100110 -> and we can still make it same like before like with OR again...1100110 | 11001100 = 
//		11001100
//		 1100110 |
//		11101110
// so what we need to check that it should have 0 in between 2 1 and 1 in between 2 zero...if have both, then cannot

bool hasSmallGap(ll a) {
	string res;
	while(a) {
		int digit = a % 2;
		if(digit == 1) {res += "1";}
		else{res += "0";}
		a /= 2;
	}

	reverse(res.begin(), res.end());
	int ans = 0;
	for(int i=1;i<res.size()-1;i++){
		if(res[i] == '0' && res[i-1] == '1' && res[i+1] == '1') {
			ans |= 1;
		}

		if(res[i] == '1' && res[i-1] == '0' && res[i+1] == '0') {
			ans |= 2;
		}
	}

	return ans == 3;
}

void solve(){
	ll n,a,b;
	while(scanf("%lld%lld%lld",&n,&a,&b) != EOF) {
		if(a != b){
			puts("NO");
			continue;
		}

		if(hasSmallGap(n)) {
			puts("NO");
			continue;
		}
		puts("YES");
	}
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};