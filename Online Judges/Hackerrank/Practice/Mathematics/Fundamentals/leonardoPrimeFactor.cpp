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

bool isPrime(int n) {
	if (n == 1) {return false;}
	for(int i=2;i<n;i++) {
		if(n % i == 0){return false;}
	}
	return true;
}

int main(){
	int tc,i,j;
	int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
	
	ll ans[] = {2, 6, 30, 210, 2310, 30030, 510510, 9699690, 223092870, 6469693230, 200560490130, 7420738134810, 304250263527210, 13082761331670030, 614889782588491410};
	
	scanf("%d",&tc);
	while(tc--){
		ll n;
		scanf("%lld",&n);
		int cnt = 0;
		for(i=0;i<15;i++){
			if(ans[i] <= n) {
				cnt++;
			} else {
				break;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
};