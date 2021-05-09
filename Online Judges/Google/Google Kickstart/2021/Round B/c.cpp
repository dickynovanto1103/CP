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
	for(int i=2;i*i<=n;i++){
		if(n%i == 0){
			return false;
		}
	}
	return true;
}


int main(){
	int tc, i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ", tt);
		ll bil;
		scanf("%lld",&bil);
		int root = (ll)sqrt(bil);
		vi primeList;
		if(isPrime(root)) {
			primeList.pb(root);
		}
		for(int i=1;i<2000;i++) {
			if(isPrime(root-i)) {
				primeList.pb(root-i);
			}
			if(isPrime(root+i)) {
				primeList.pb(root+i);
			}
		}
		sort(primeList.begin(), primeList.end());
		int sz = primeList.size();
		ll ans = 6;
		for(i=0;i<sz-1;i++){
			ll kali = (ll)primeList[i] * primeList[i+1];
			if(kali <= bil){
				ans = kali;
			}
		}
		printf("%lld\n", ans);
	}
	
	
	return 0;
};