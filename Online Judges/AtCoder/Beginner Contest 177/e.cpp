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

const int maxn = 1e6;	

int gcd(int a, int b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}

int a[1000001];

bool isprime[1000001];
int prime[78500];

set<int> primeList;

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

bool allNewPrime(ll n) {
	ll pf_idx = 0, pf = prime[pf_idx];
	while(pf*pf <= n) {
		if(n % pf == 0){
			if(primeList.find(pf) != primeList.end()){
				return false;
			}
			primeList.insert(pf);
			while(n % pf == 0){
				n /= pf;
			}
		}
		pf = prime[++pf_idx];
	}

	if(n != 1){
		if(primeList.find(n) != primeList.end()){
			return false;
		}
		primeList.insert(n);
	}
	return true;
}

int main(){
	int n,i,j;
	memset(isprime, true, sizeof isprime);
	sieve(maxn);
	int cntPrime = 0;
	for(i=0;i<maxn;i++){
		if(isprime[i]){
			prime[cntPrime++] = i;
		}
	}
	
	scanf("%d",&n);
	int gcd1 = 0;
	bool isAllNew = true;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		isAllNew = isAllNew && allNewPrime(a[i]);
		gcd1 = gcd(gcd1, a[i]);
	}
	if(isAllNew){printf("pairwise coprime\n");}
	else{
		if(gcd1 == 1){printf("setwise coprime\n");}
		else{printf("not coprime\n");}
	}
	
	return 0;
};