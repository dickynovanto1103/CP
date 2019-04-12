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

const int maxn = 1e6;

bool isprime[maxn + 5];
int prime[78500];
int id[maxn];
int counter[78500];

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

vector<vii> fac;

void factorize(ll n, int indeks) {
	ll idx = 0, pf = prime[idx];
	while(pf*pf <= n){
		int cnt = 0;
		if(n%pf == 0){
			while(n%pf == 0){
				n/=pf;
				cnt++;
			}
			fac[indeks].pb(ii(pf, cnt));
			counter[id[pf]] += cnt;
		}
		pf = prime[++idx];
	}
	if(n != 1){
		fac[indeks].pb(ii(n, 1));
		counter[id[n]] += 1;
	}
}

ll modPow(ll a, ll b){
	if(b == 0){return 1;}
	else{
		if(b%2 == 1){
			return a*modPow(a,b-1);
		}else{
			ll temp = modPow(a,b/2);
			return temp*temp;
		}
	}
}

int main(){
	memset(isprime, true, sizeof isprime);
	sieve(maxn);
	int cnt = 0;
	int i,j;
	fac.assign(101, vii());
	for(i=0;i<maxn;i++){
		if(isprime[i]){
			prime[cnt] = i;
			id[i] = cnt;
			cnt++;
		}
	}

	int n;
	scanf("%d",&n);
	int a[101];
	for(i=0;i<n;i++){
		
		scanf("%d",&a[i]);
		factorize(a[i], i);
	}
	ll gcd = 1;
	int langkah = 0;
	for(i=0;i<cnt;i++){

		int total = counter[i];
		int pangkat = 0;
		for(j=1;;j++){
			if(total < j*n){
				break;
			}else{
				pangkat = j;
			}
		}
		if(pangkat == 0){continue;}
		// printf("i: %d tinjau prime: %d pangkat: %d\n",i,prime[i], pangkat);
		gcd *= modPow(prime[i], pangkat);
		priority_queue<int> lebih, kurang;
		
		for(j=0;j<n;j++){//liat di hasil faktorisasi
			bool pernah = false;
			// printf("a[%d]: %d\n",j,a[j]);
			if(fac[j].size() == 0){
				pernah = true;
				kurang.push(pangkat);
				// printf("dipush kurang: %d\n",pangkat);
				continue;
			}
			int maks = 0;
			for(int k=0;k<fac[j].size();k++){
				ii elemen = fac[j][k];
				maks = max(maks, elemen.first);
				if(elemen.first == prime[i]){
					pernah = true;
					if(elemen.second > pangkat){
					}else if(elemen.second < pangkat){
						kurang.push(pangkat - elemen.second);
					}
				}else if(elemen.first > prime[i]){

					
					break;
				}
			}
			if(!pernah && maks > prime[i]){
				kurang.push(pangkat);	
				// printf("1 dipush kurang: %d\n",pangkat);
			}
			if(maks < prime[i]){
				kurang.push(pangkat);
				// printf("2 dipush kurang: %d\n",pangkat);
			}
		}

		while(!kurang.empty()){
			// printf("halo gan\n");
			int elemen = kurang.top(); kurang.pop();
			langkah+=elemen;
		}

	}
	printf("%lld %d\n",gcd, langkah);
	return 0;
};