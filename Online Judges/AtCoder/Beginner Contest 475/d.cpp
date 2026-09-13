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

const int maxn = 10000000;
int isPrime[maxn + 10];
vi primes(66500);
vi primesWithDigits[8];

int numDigits(int num) {
	int cnt = 0;
	while(num) {
		cnt++;
		num /= 10;
	}

	return cnt;
}

void sieve() {
	memset(isPrime, true, sizeof isPrime);
	isPrime[0] = isPrime[1] = false;
	for(int i=2;i*i<maxn;i++){
		for(int j=i*i;j<=maxn;j+=i) {
			isPrime[j] = false;
		}
	}

	for(int i=0;i<maxn;i++){
		if(isPrime[i]) {
			primesWithDigits[numDigits(i)].pb(i);
		}
	}
}

vi digits(int num) {
	vi ans;
	while(num > 0) {
		ans.pb(num % 10);
		num /= 10;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

void solve(){
	sieve();
	
	string s;
	while(cin>>s) {
		int sz = s.size();
		int ans = -1;
		// int testPrime = 10607;
		for(int prime: primesWithDigits[sz]) {
			//do mappiung
			// if(prime == testPrime) {
			// 	puts("here");
			// }
			vi digitsOfPrime = digits(prime);
			unordered_map<char, int> charToInt;
			unordered_map<int, char> intToChar;
			bool valid = true;
			for(int i=0;i<sz;i++){
				char c = s[i];
				int digit = digitsOfPrime[i];
				// if(prime == testPrime) {
				// 	// printf("i: %d c: %c digit: %d\n",i, c, digit);	
				// }
				
				if(charToInt.find(c) == charToInt.end() && intToChar.find(digit) == intToChar.end()) {
					charToInt[c] = digit;
					intToChar[digit] = c;
					// if(prime == testPrime) {
					// 	// puts("still valid");	
					// }
					
				}else{
					if(charToInt[c] == digit && intToChar[digit] == c) {
						continue;
					}
					valid = false;
					// if(prime == testPrime) {
					// 	// puts("invalid");	
					// }
					break;
				}
			}

			if(valid){
				ans = prime;
				break;
			}
		}
		printf("%d\n", ans);
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