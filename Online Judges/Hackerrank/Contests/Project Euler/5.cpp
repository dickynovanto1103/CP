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

const int maxn = 100;
bool isprime[maxn + 3];
int prime[30];

void sieve(int n) {
	isprime[0] = isprime[1] = false;
	int i,j;
	for(i=2;i*i<=n;i++) {
		if(isprime[i]){
			for(j=i*i;j<=n;j+=i) {
				isprime[j] = false;
			}
		}
	}
}

int cntPrime[50];

void factorize(int n) {
	ll pf_idx = 0, pf = prime[pf_idx];
	int tempN = n;
	int banyak[n+1];
	memset(banyak, 0,sizeof banyak);
	
	while(pf*pf<=n) {
		// printf("test\n");
		while(n%pf==0){n/=pf; banyak[pf]++;}
		pf = prime[++pf_idx];
	}
	if(n!=1){banyak[n]++;}
	for(int i=1;i<=tempN;i++){

		cntPrime[i] = max(cntPrime[i], banyak[i]);
		// printf("banyak[%d]: %d cntPrime[%d]: %d\n",i,banyak[i], i, cntPrime[i]);
	}
}

int main(){
	int tc,i,j,n;
	memset(isprime, true, sizeof isprime);
	sieve(maxn);
	int cnt = 0;
	for(i=2;i<=maxn;i++){
		if(isprime[i]){
			prime[cnt] = i;
			cnt++;
		}
	}

	scanf("%d",&tc);
	while(tc--){
		memset(cntPrime, 0, sizeof cntPrime);
		// cntPrime[1] = 1;
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			factorize(i);
		}

		ll ans = 1;
		for(i=1;i<=n;i++){
	
			ans*=(ll)pow(i,cntPrime[i]);
	
		}
		printf("%lld\n",ans);
	}
	return 0;
};