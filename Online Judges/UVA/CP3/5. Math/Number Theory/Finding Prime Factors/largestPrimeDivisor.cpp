#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int isprime[10000010], prime[665000];

void sieve(int n){
	int i,j;
	isprime[0] = isprime[1] = false;
	for(i=2;i*i<=n;i++){
		if(isprime[i]){
			for(j=i+i;j<=n;j+=i){
				isprime[j] = false;
			}
		}
	}
}

vi primefactor(ll n){
	vi factor;
	//printf("n: %d\n",n);
	if(n<0){n*=-1; factor.pb(-1);}
	ll idx = 0, pf = prime[idx];
	while(pf*pf<=n){
		while(n%pf==0){factor.pb(pf); n/=pf;}
		pf = prime[++idx];	
	}
	
	if(n!=1){factor.pb(n);}
	return factor;
	
}

int main() {
	ll n,i;
	memset(isprime,true,sizeof isprime);
	sieve(10000000);
	int cnt = 0;
	for(i=0;i<=10000000;i++){
		if(isprime[i]){prime[cnt] = i;cnt++;}
	}
	map<ll,ll> mapper;
	map<ll,ll>::iterator it;
	//printf("cnt: %d\n",cnt);
	while(scanf("%lld",&n),n){
		//printf("n: %lld\n",n);
		vi ans = primefactor(n);
		int ukuran = ans.size();
		int counter = 0;
		for(i=0;i<ukuran;i++){
			it = mapper.find(ans[i]);
			if(it==mapper.end()){mapper[ans[i]] = counter++;}
		}
		//printf("ukuran: %d\n",ukuran);
		if(n<0){
			if(counter<=2){printf("-1\n");}
			else{printf("%lld\n",ans[ukuran-1]);}
		}else{
			if(counter<=1){printf("-1\n");}
			else{printf("%lld\n",ans[ukuran-1]);}
		}
		
		mapper.clear();
	}
	return 0;
}