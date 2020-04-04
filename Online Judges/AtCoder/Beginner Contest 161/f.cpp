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

bool isprime[1000001];
int prime[78500];

void sieve(int n) {
	int i,j;
	isprime[0] = isprime[1] = false;
	for(i=2;i*i<=n;i++){
		if(isprime[i]){
			for(j=i*i;j<=n;j+=i){
				isprime[j] = false;
			}
		}
	}
}


vii factorize(ll n) {
	ll pf_idx = 0, pf = prime[pf_idx];
	vii ans;
	while(pf*pf <= n){
		int cnt = 0;
		while(n % pf == 0) {
			cnt++;

			n /= pf;
		}
		if(cnt){
			ans.pb(ii(pf, cnt));
		}
	}
	if(n != 1){
		ans.pb(ii(n, 1));
	}
	return ans;
}

int main(){
	int i,j;
	memset(isprime, true, sizeof isprime);
	sieve(1000000);
	int cnt = 0;

	for(i=2;i<=1000000;i++){
		if(isprime[i]){
			prime[cnt++] = i;
		}
	}

	ll n;
	cin>>n;
	
	// vii fac = factorize(n);
	ll ans = 0;
	// if(fac.size() == 1){
	// 	//find num of divisor of fac[0].second;
	// 	int pangkat = fac[0].second;
	// 	for(i=1;i*i<=pangkat;i++){
	// 		if(pangkat % i == 0){
	// 			int div1 = i;
	// 			int div2 = pangkat / i;
	// 			if(div1 == div2){
	// 				printf("%d\n",div1);
	// 				ans++;
	// 			}else {
	// 				printf("%d %d\n",div1, div2);
	// 				ans+=2;
	// 			}
	// 		}
	// 	}
	// }

	//find divisors of n
	vector<ll> listDiv;
	for(ll i=1;i*i<=n;i++){
		if(n % i == 0){
			ll div1 = i;
			ll div2 = n/i;
			if(div1 == div2) {
				if(div1 != 1){
					listDiv.pb(div1);
				}
			}else{
				if(div1 != 1){
					listDiv.pb(div1);
				}
				if(div2 != 1){
					listDiv.pb(div2);
				}
			}
		}
	}

	for(i=0;i<listDiv.size();i++){
		ll bil = listDiv[i];

		ll temp = n;
		while(temp % bil == 0){
			temp /= bil;
		}
		temp %= bil;
		if(temp == 1){
			// printf("bil: %lld\n",bil);
			ans++;
		}
	}

	//find num divisor dr n-1
	ll angka = n-1;
	for(ll i=1;i*i<=angka;i++){
		if(angka % i == 0){
			ll div1 = i;
			ll div2 = angka / i;
			if(div1 == div2){
				if(div1 != 1){
					ans++;
				}
				// printf("%lld\n",div1);
				// ans++;
			}else{
				if(div1 != 1){
					ans++;
				}
				if(div2 != 1){
					ans++;
				}
				// printf("%lld %lld\n",div1, div2);
				// ans += 2;
			}
		}
	}

	printf("%lld\n",ans);

	return 0;
};