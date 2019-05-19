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
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

const int maxn = 1e6;

bool isprime[maxn + 2];
int prime[78500];

ll power(ll a, ll b){
	if(b == 0){return 1;}
	else{
		if(b%2){
			return a*power(a,b-1);
		}else{
			ll temp = power(a,b/2);
			return temp*temp;
		}
	}
}

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

vii ans;
int cnt = 0;

void factorize(ll n) {
	ll pf_idx = 0, pf = prime[pf_idx];
	
	while(pf*pf <= n && pf_idx < cnt) {
		// printf("pf: %lld n: %lld\n",pf,n);
		if(n%pf == 0){
			
			int cnt = 0;
			while(n%pf == 0){
				n/=pf;
				cnt++;
			}
			ans.pb(ii(pf,cnt));
		}
		pf = prime[++pf_idx];
	}
	if(n!=1){
		ans.pb(ii(n, 1));
	}
}

int main(){
	ll n,b;
	scanf("%lld %lld",&n,&b);
	memset(isprime, true, sizeof isprime);
	sieve(maxn);
	
	int i,j;
	for(i=0;i<=maxn;i++){
		if(isprime[i]){
			prime[cnt++] = i;
		}
	}
	// printf("%d\n",prime[cnt - 1]);
	factorize(b);
	ll jawab = 1e18;
	for(i=0;i<ans.size();i++){
		ll prime = ans[i].first, occ = ans[i].second;
		ll temp = prime;
		ll a = 0;
		while(temp <= n) {
			a += (n/temp);
			if(temp > n/prime){break;}
			temp *= prime;
		}
		jawab = min(jawab, (a/occ));
	}
	
	printf("%lld\n",jawab);
	return 0;
};