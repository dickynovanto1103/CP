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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const ll mod = 1e9 + 9;

bool isprime[10001];
int prime[10100];

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

ll modPow(ll a, ll b){
	if(b == 0){return 1;}
	else{
		if(b%2 == 1){return a*modPow(a,b-1)%mod;}
		else{
			ll temp = modPow(a,b/2);
			return temp*temp%mod;
		}
	}
}

ll modInverse(ll a) {
	return modPow(a, mod-2);
}

int main(){
	memset(isprime, true, sizeof isprime);
	sieve(10000);
	int cnt = 0;
	int i,j;
	for(i=1;i<=10000;i++){
		if(isprime[i]){
			prime[cnt++] = i;
		}
	}

	map<int,ii> mapper;
	for(i=0;i<cnt;i++){
		for(j=i;j<cnt;j++){
			int a = prime[i], b = prime[j];
			mapper[a*b] = ii(a,b);
		}
	}

	int n;
	scanf("%d",&n);
	ll last = 1;
	vi listBil;
	for(i=2;i<=n;i+=2) {
		printf("? 1 %d\n",i);
		fflush(stdout);
		ll bil;
		scanf("%lld",&bil);
		ll cari = bil*modInverse(last)%mod;
		if(mapper.find(cari) == mapper.end()){assert(false);}
		else{
			ii pas = mapper[cari];
			listBil.pb(pas.first); listBil.pb(pas.second);
		}
		last = bil;
	}
	if(i == (n+1)){
		printf("? 1 %d\n",n);
		fflush(stdout);
		ll bil;
		scanf("%lld",&bil);
		ll cari = bil*modInverse(last)%mod;
		listBil.pb(cari);
	}
	printf("!");
	for(i=0;i<n;i++){
		printf(" %d",listBil[i]);
	}
	printf("\n");
	return 0;
};