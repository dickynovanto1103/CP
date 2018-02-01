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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5;
const ll mod = 1e9 + 7;

bool isprime[maxn+10];
ll faktorPrima[maxn+10];
ll prime[10000];

void sieve(ll n){
	ll i,j;
	isprime[0] = isprime[1] = false;
	for(i=2;i*i<=n;i++){
		if(isprime[i]){
			for(j=i*2;j<=n;j+=i){
				isprime[j] = false;
			}
		}
	}
}

void factorize(ll n){
	ll idx = 0, pf = prime[idx];
	while(pf*pf<=n){
		while(n%pf==0){n/=pf;faktorPrima[pf]++;}
		pf = prime[++idx];
	}
	if(n!=1){faktorPrima[n]++;}
}

ll modPow(ll a, ll b){
	if(b==0){return 1;}
	else{
		if(b%2==1){
			return ((a%mod)*(modPow(a,b-1)%mod))%mod;
		}else{
			ll temp = modPow(a,b/2);
			return ((temp%mod)*(temp%mod))%mod;
		}
	}
}

ll fac[16*maxn+5*maxn];
// ll invFac[16*maxn+10];

ll c(ll a, ll b){
	return (((fac[a]%mod)*(modPow(fac[a-b],mod-2)%mod))%mod*(modPow(fac[b],mod-2)%mod))%mod;
}

int main(){
	int n,tc;
	ll i,j;

	memset(isprime,true,sizeof isprime);
	fac[0] = 1;
	//invFac[0] = 1;
	for(i=1;i<=16*maxn+5*maxn - 5;i++){
		fac[i] = ((i%mod)*fac[i-1]%mod)%mod;
		//invFac[i] = modPow(fac[i],mod-2);
	}
	sieve(maxn);
	int cnt = 0;
	for(i=0;i<=maxn;i++){
		if(isprime[i]){
			prime[cnt] = i;
			cnt++;
		}
	}
	//printf("cnt: %d\n",cnt);
	// ll maks = 0;
	// for(i=1;i<=maxn;i++){
	// 	memset(faktorPrima,0,sizeof faktorPrima);
	// 	factorize(i);
	// 	ll maksFaktorPrima = 0;
	// 	for(j=0;j<cnt;j++){
	// 		maksFaktorPrima = max(maksFaktorPrima,faktorPrima[prime[j]]);
	// 	}
	// 	maks = max(maks,maksFaktorPrima);
	// 	printf("i: %lld maks: %lld\n",i,maks);
	// }
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		memset(faktorPrima,0,sizeof faktorPrima);
		for(i=0;i<n;i++){
			int bil;
			scanf("%d",&bil);
			//faktorkan bilangan
			factorize(bil);


		}
		ll ans = 1;
		//ll maksFaktorPrima = 0;
		for(i=0;i<cnt;i++){
			//maksFaktorPrima = max(maksFaktorPrima,faktorPrima[prime[i]]);
			//printf("jumlah faktor prima dari: %lld adalah %d\n",prime[i],faktorPrima[prime[i]]);
			ans = (ans%mod*c((ll)faktorPrima[prime[i]]+n-1,n-1)%mod)%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
};