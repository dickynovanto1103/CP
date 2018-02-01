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

const ll maxn = 1000000;
bool isPrime[maxn+10];
ll prime[78500];

void sieve(ll n) {
	int i,j;
	isPrime[0] = isPrime[1] = false;
	for(i=2;i*i<=n;i++) {
		if(isPrime[i]) {
			for(j=i*2;j<=n;j+=i) {
				isPrime[j] = false;
			}
		}
	}
}

ll eulerPhi(ll N) {
	int i,j;
	ll pfIdx = 0, pf = prime[pfIdx], ans = N;
	while(pf*pf<=N) {
		if(N%pf==0) {ans-=(ans/pf);}
		while(N%pf==0){N/=pf;}
		pfIdx++;
		pf = prime[pfIdx];
	}
	if(N!=1){ans-=(ans/N);}// N prima
	return ans;
}

int main(){
	int n,i,j;
	memset(isPrime,true,sizeof isPrime);
	sieve(maxn);
	int cnt = 0;
	for(i=0;i<=maxn;i++){
		if(isPrime[i]){
			prime[cnt] = i;
			cnt++;
		}
	}
	
	scanf("%d",&n);
	ll ans = 0;
	for(i=1;i<=n;i++){
		ans += eulerPhi((ll)i);
	}
	printf("%lld\n",ans);
	return 0;
};