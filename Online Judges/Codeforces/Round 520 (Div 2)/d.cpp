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
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

const int maxn = 1e5;

bool isprime[maxn + 10];
int prime[maxn];

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

ll ans = 0;
int cnt;
int awal;
set<ii> s;

void insertToSet(int minim, int maks, int tambah, int masuk);
void dfs(ll n);

int main(){
	int n,i,j;
	memset(isprime, true, sizeof isprime);
	sieve(maxn);
	cnt = 0;
	for(i=0;i<maxn;i++){
		if(isprime[i]){
			prime[cnt++] = i;
		}
	}
	scanf("%d",&n);
	awal = n;
	
	for(i=0;i<cnt;i++){
		if(prime[i] > awal){break;}
		dfs(prime[i]);
	}
	printf("%lld\n",ans);
	return 0;
};

void insertToSet(int minim, int maks, int tambah, ll masuk){
	// if(minim == -2 && maks == 4){printf("halo\n");}
	if(s.find(ii(minim, maks)) == s.end()){
		s.insert(ii(minim, maks));
		ans += abs(tambah);
		// printf("minim: %d maks: %d tambah; %d masuk: %lld ans jd: %lld\n",minim, maks, tambah, masuk,ans);
		dfs(masuk);
	}
}
void dfs(ll n){
	//kali faktor
	// printf("n: %lld\n",n);
	int i,j;
	for(i=0;i<cnt;i++){
		ll kali = n * (ll)prime[i];
		
		if(abs(kali) > awal){break;}
		// printf("kali: %lld n; %lld prime[%d] %d\n",kali,n, i, prime[i]);
		ll minim = min(n, kali);
		ll maks = max(n, kali);

		insertToSet(minim, maks, prime[i], kali);
		minim = min(n, -kali);
		minim = max(n, -kali);
		insertToSet(minim, maks, prime[i], -kali);
	}
	//cari pembagi
	for(i=2;i*i<=n;i++){
		if(n%i == 0){
			ll angka1 = i, angka2 = n/i;
			if(angka1 != angka2){
				ll minim = min(n, angka1);
				ll maks = max(n, angka1);
				// printf("minim: %lld maks: %lld\n",minim, maks);
				insertToSet(minim, maks, angka2, angka1);

				minim = min(n, -angka1);
				maks = max(n, -angka1);
				// printf("minim: %lld maks: %lld\n",minim, maks);
				insertToSet(minim, maks, angka2, -angka1);

				minim = min(n, angka2);
				maks = max(n, angka2);
				// printf("minim: %lld maks: %lld\n",minim, maks);
				insertToSet(minim, maks, angka1, angka2);

				minim = min(n, -angka2);
				maks = max(n, -angka2);
				// printf("minim: %lld maks: %lld\n",minim, maks);
				insertToSet(minim, maks, angka1, -angka2);
			}else{
				// printf("halo\n");
				ll minim = min(n, angka2);
				ll maks = max(n, angka2);

				insertToSet(minim, maks, angka1, angka2);
				minim = min(n, -angka2);
				maks = max(n, -angka2);
				insertToSet(minim, maks, angka1, -angka2);
			}
		}
		
	}
}