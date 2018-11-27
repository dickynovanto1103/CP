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

int prime[maxn];
bool isprime[maxn + 10];

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

void factorize(ll n){
	ll idx = 0, pf = prime[idx];
	while(pf*pf <= n){
		if(n%pf == 0){
			ll loop = n/pf;
			n -= (loop*pf);
			ans += loop;
		}
	}
}

int main(){
	memset(isprime, true, sizeof isprime);
	sieve(maxn);
	int cnt = 0;
	int i,j;
	for(i=0;i<maxn;i++){
		if(isprime[i]){
			prime[cnt] = i;
			cnt++;
		}
	}
	ll n;
	scanf("%lld",&n);
	bool apakahPrima = true;
	for(i=0;i<cnt;i++){
		if(n%prime[i] == 0){
			apakahPrima = false;
			n-=prime[i];
			ans++;
			break;
		}
	}
	if(apakahPrima){
		printf("1\n");
	}else{
		ll loop = n / 2LL;
		ans += loop;
		printf("%lld\n",ans);	
	}
	
	return 0;
};