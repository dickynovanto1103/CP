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

const int maxn = 50000;
bool isprime[maxn + 10];
ll prime[5140];

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
int cntPrime;
map<int,int> mapper;
int mapperPrime[40];
int pangkatGcd[40];
int pangkatLcm[40];

void factorize(ll n, bool isGCD) {
	ll pf_idx = 0, pf = prime[pf_idx];
	while(pf*pf <= n) {
		if(n%pf==0){
			if(mapper.find(pf) == mapper.end()) {
				mapperPrime[cntPrime] = pf;
				mapper[pf] = cntPrime++;
			}
			int idx = mapper[pf];
			while(n%pf==0){
				if(isGCD){
					pangkatGcd[idx]++;
				}else{
					pangkatLcm[idx]++;
				}
				n/=pf;
			}
		}
		pf = prime[++pf_idx];
	}
	if(n!=1){
		if(mapper.find(n) == mapper.end()){
			mapperPrime[cntPrime] = n;
			
			if(isGCD){
				pangkatGcd[cntPrime]++;
			}else{
				pangkatLcm[cntPrime]++;
			}
			mapper[n] = cntPrime++;
		}else{
			int idx = mapper[n];
			if(isGCD){
				pangkatGcd[idx]++;
			}else{
				pangkatLcm[idx]++;
			}
			
		}
	}
}

ll power(ll a, ll b){
	if(b==0){
		return 1;
	}else{
		if(b%2==1){
			return a*power(a, b-1);
		}else{
			ll temp = power(a,b/2);
			return temp*temp;
		}
	}
}

int main(){
	int i,j;
	ll l,r,x,y;
	memset(isprime, true,sizeof isprime);
	sieve(maxn);
	int cnt = 0;
	for(i=2;i<=maxn;i++){
		if(isprime[i]){
			prime[cnt] = i;
			cnt++;
		}
	}	
	scanf("%lld %lld %lld %lld",&l,&r,&x,&y);
	factorize(x, true);
	factorize(y, false);

	set<ii> s;
	for(i=0;i<(1<<11);i++){
		// printf("i; %d\n",i);
		ll a = 1;
		ll b = 1;
		for(j=0;j<11;j++){
			if(1<<j & i) {
				a*=(ll)power(mapperPrime[j], pangkatGcd[j]);
				b*=(ll)power(mapperPrime[j], pangkatLcm[j]);

			}else{
				a*=(ll)power(mapperPrime[j], pangkatLcm[j]);
				b*=(ll)power(mapperPrime[j], pangkatGcd[j]);
			}
		}

		if(a>=l && a<=r && b>=l && b<=r){
			// printf("a: %lld b: %lld\n",a,b);
			ll gcd = __gcd(a,b);
			ll lcm = a*(b/gcd);
			if(gcd == x && lcm == y){
				s.insert(ii(b,a));
				s.insert(ii(a,b));	
			}
			
		}
	}
	ll kali = x*y;
	ll a = 1;
	ll b = kali;
	if(a>=l && a<=r && b>=l && b<=r){
		// printf("insert;\n");
		ll gcd = __gcd(a,b);
		ll lcm = a*(b/gcd);
		if(gcd == x && lcm == y){
			s.insert(ii(a,b));
			s.insert(ii(b,a));	
		}
		
	}
	printf("%d\n",(int)s.size());
	return 0;
};