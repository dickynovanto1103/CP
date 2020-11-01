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


const int maxn = 1e5;
bool isprime[maxn + 3];
int prime[10010];

void sieve(int n){
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

vi factorize(ll n){
	int i,j;
	vi primeFac;
	ll pf = prime[0], pf_idx = 0, ans = 1;
	while(pf * pf <= n){
		if(n % pf == 0){
			while(n % pf == 0) {
				n/=pf;	
			}
			primeFac.pb(pf);
		}
		pf = prime[++pf_idx];
	}
	if(n != 1) {
		primeFac.pb(n);
	}
	return primeFac;
}

int main(){
	int tc,i,j;
	memset(isprime, true, sizeof isprime);
	sieve(maxn);
	int cnt = 0;
	for(i=0;i<=maxn;i++){
		if(isprime[i]){
			prime[cnt] = i;
			cnt++;
		}
	}

	scanf("%d",&tc);
	while(tc--){
		ll a,b;
		scanf("%lld %lld",&a,&b);
		if(a % b != 0){
			printf("%lld\n",a);
		}else{
			vi primeFac = factorize(b);
			ll bagi = a;
			for(ll p: primeFac){
				while(bagi % p == 0){
					bagi /= p;
				}
				// printf("p: %lld bagi jd: %lld\n",p, bagi);
			}
			ll maks = 0;
			for(int start = 0; start < primeFac.size();start++){
				ll ans = bagi;
				for(int idx=start;idx<(start + primeFac.size());idx++){
					i = idx % primeFac.size();
					ll p = primeFac[i];
					ll kali = ans * p;
					// printf("p: %lld kali: %lld\n",p, kali);
					while(a % kali == 0 && kali % b != 0) {
						ans = kali;
						kali *= p;
					}
				}
				// printf("start: %d as: %lld maks: %lld\n",start, ans, maks);
				maks = max(maks, ans);
			}
			
			printf("%lld\n",maks);
		}
	}
	
	return 0;
};