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

const int maxn = 100000;

bool isprime[maxn+10];
int prime[10000];

int banyakPrima;

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

vector<ll> fac;

void factorize(ll n) {
	ll pf_idx = 0, pf = prime[pf_idx];
	while(pf*pf <= n) {
		if(n % pf == 0){
			fac.pb(pf);
			while(n % pf == 0) {
				n/=pf;
			}
		}
		pf = prime[++pf_idx];
		if(pf_idx == banyakPrima){break;}
	}
	if(n!= -1){
		fac.pb(n);
	}
}

const ll mod = 1e9 + 7;

ll modPow(ll a, ll b){
	if(b == 0){return 1;}
	else{
		if(b%2 == 1){return (a%mod)*modPow(a,b-1)%mod;}
		else{
			ll temp = modPow(a,b/2LL);
			return temp*temp%mod;
		}
	}
}

int main(){
	ll x, n;
	int i,j;
	memset(isprime, true, sizeof isprime);
	sieve(maxn);
	int cnt = 0;
	for(i=1;i<maxn;i++){
		if(isprime[i]){
			prime[cnt++] = i;
		}
	}
	banyakPrima = cnt;
	// printf("cnt: %d\n",cnt);
	scanf("%lld %lld",&x,&n);
	factorize(x);
	ll ans = 1;
	for(i=0;i<fac.size();i++){
		ll factor = fac[i];
		// printf("factor: %lld\n",factor);
		ll temp = factor;
		vector<ll> v;
		if(temp > n){
			continue;
		}
		v.pb(temp);
		while(temp <= n/factor) {
			//ll banyak = (n-temp) / temp*2LL;
			temp *= factor;
			v.pb(temp);
			if(v.size() > 65){break;}
		}
		ll cnt = 0;
		for(j=v.size()-1;j>=0;j--){
			ll angka = v[j];
			if(angka < 0){continue;}
			// printf("angka: %lld\n",angka);
			ll banyak = n / angka;
			// printf("banyak asli: %lld cntSekarang: %lld\n",banyak,cnt);
			banyak -= cnt;
			// printf("banyak: %lld\n",banyak);
			// angka %= mod;
			ll tambah = modPow(angka, banyak);
			// printf("tambah ans: %lld\n",tambah);
			ans *= tambah;
			ans %= mod;
			cnt = n/angka;
			// printf("cnt jd: %lld\n",cnt);
		}
	}
	printf("%lld\n",ans);
	return 0;
};
