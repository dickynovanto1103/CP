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

int sumOfDigits(ll n) {
	int sum = 0;
	while(n) {
		int digit = n % 10;
		sum += digit;
		n /= 10;
	}
	return sum;
}

int main(){
	int tc,j;
	ll n, i;
	scanf("%d",&tc);
	while(tc--){
		scanf("%lld",&n);
		for(i=n;;i++){
			if(__gcd(i, (ll)sumOfDigits(i)) > 1) {
				printf("%lld\n",i);
				break;
			}
		}
	}
	
	return 0;
};