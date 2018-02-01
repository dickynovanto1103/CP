#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1000000;
bool isprime[maxn+5];
ll prime[78500];

void sieve(int n){
	int i,j;
	isprime[0] = isprime[1] = false;
	for(i=2;i*i<=n;i++){
		if(isprime[i]){
			for(j=i*2;j<=n;j+=i){
				isprime[j] = false;
			}
		}
	}
}

vi factorize(ll n){
	vi factors;
	ll idx = 0, pf = prime[idx];
	//printf("n: %lld pf: %lld\n",n,pf);
	while(pf*pf<=n){
		if(n%pf==0){factors.pb(pf);}
		while(n%pf==0){n/=pf;}
		pf = prime[idx++];
	}
	if(n!=1){factors.pb(n);}
	return factors;
}

int main() {
	int tc,j;
	ll a[50010],n,i;
	memset(isprime,true,sizeof isprime);
	sieve(maxn);
	int cnt = 0;
	for(i=0;i<=maxn;i++){
		if(isprime[i]){prime[cnt] = i; cnt++;}
	}
	scanf("%d",&tc);
	while(tc--){
		map<ll,int> mapper;
		map<ll,int>::iterator it;
		scanf("%lld",&n);
		cnt = 0;
		bool found = true;
		for(i=0;i<n;i++){
			scanf("%lld",&a[i]);
			if(isprime[a[i]]){
				it = mapper.find(a[i]);
				if(it==mapper.end()){mapper[a[i]] =cnt++;}
				else{found = false; break;}
			}else{
				vi ans = factorize(a[i]);
				int ukuran = ans.size();
				for(j=0;j<ukuran;j++){
					ll bil = ans[j];
					//printf("factor: %lld\n",bil);
					it = mapper.find(bil);
					if(it==mapper.end()){mapper[bil] = cnt++;}
					else{found = false; break;}
				}
			}
		}
		if(found){printf("YA\n");}
		else{printf("TIDAK\n");}


	}
	return 0;
}