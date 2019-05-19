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

const int maxn = 1e6;

bool isprime[maxn + 6];
int prime[78500];
int cnt;
int cntPrime[78500];
int idxPrime[maxn];

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

void factorize(ll n) {
	ll pf_idx = 0, pf = prime[pf_idx];
	// printf("n: %lld\n",n);
	while(pf*pf <= n) {
		int counter = 0;
		while(n % pf == 0) {
			counter++;
			n/=pf;
		}
		cntPrime[pf_idx] = max(cntPrime[pf_idx], counter);
		pf = prime[++pf_idx];
	}
	if(n != 1){
		cntPrime[idxPrime[n]] = max(cntPrime[idxPrime[n]], 1);
	}
}

ll modPow(ll a, ll b){
	if(b == 0){return 1;}
	else{
		if(b%2 == 1){return a*modPow(a,b-1);}
		else{
			ll temp = modPow(a,b/2);
			return temp*temp;
		}
	}
}

ll getNumber() {
	ll ans = 1;
	int i;
	for(i=0;i<cnt;i++) {
		// if(cntPrime[i])
			// printf("prime[%d]: %d cnt: %d\n",i, prime[i], cntPrime[i]);
		ans *= modPow(prime[i], cntPrime[i]);
	}
	return ans;
}

ll getNumDiv() {
	ll ans = 1;
	int i;
	for(i=0;i<cnt;i++) {
		ans *= (cntPrime[i]+1);
		if(ans > 300){return -1;}
	}
	return ans;	
}

ll numDiv;

ll isOnly1() {
	int ans = 0;
	ll bil = 0;
	ll counter = 0;
	for(int i=0;i<cnt;i++){
		if(cntPrime[i]){
			ans++;
			bil = prime[i];
			counter = cntPrime[i];
			if(ans > 1){return -1;}
		}
	}
	numDiv = counter+2;
	return modPow(bil, counter+1);
}

int main(){
	int tc,i,j,n;
	memset(isprime, true, sizeof isprime);
	sieve(maxn);
	cnt = 0;

	for(i=0;i<maxn;i++){
		if(isprime[i]){
			prime[cnt] = i;
			idxPrime[i] = cnt;
			cnt++;
		}
	}
	// printf("cnt: %d\n",cnt);
	scanf("%d",&tc);
	while(tc--){
		memset(cntPrime, 0, sizeof cntPrime);
		scanf("%d",&n);
		int a[344];
		set<ll> s;
		numDiv = 2;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			factorize(a[i]);
			s.insert(a[i]);
		}
		ll ans = getNumber();
		ll hasil = isOnly1();
		
		
		if(hasil != -1) {
			if(numDiv != (ll)n+2){
				printf("-1\n");
				continue;
			}
			printf("%lld\n",hasil);

			continue;
		}
		// if(n == 1) {
		// 	if(isprime[a[0]]){
		// 		printf("%lld\n",(ll)a[0]*a[0]);
		// 	}else{
		// 		printf("-1\n");
		// 	}
		// 	continue;
		// }
		
		numDiv = getNumDiv();
		// printf("ans: %lld numDiv: %lld\n",ans,numDiv);
		if((ll)n+2 != numDiv) {
			printf("-1\n");
			continue;
		}else if(s.find(ans) != s.end()){
			printf("-1\n");
		}else {
			printf("%lld\n",ans);
		}
	}
	return 0;
};