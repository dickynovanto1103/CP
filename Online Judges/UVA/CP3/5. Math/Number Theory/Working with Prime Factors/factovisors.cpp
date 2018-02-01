#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define intmax 2147483647
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool isprime[46501];
int prime[4810];

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

map<ll,ll> mapper;

vi factorize(ll n){
	vi ans;
	ll cnt = 0, idx = 0, pf = prime[idx];
	while(pf*pf<=n){
		if(n%pf==0){
			mapper[cnt] = pf;
			ans.pb(0);

			while(n%pf==0){n/=pf; ans[cnt]++;}
			cnt++;
			
		}
		pf = prime[++idx];
	}
	if(n!=1){mapper[cnt] = n; ans.pb(0); ans[cnt]++; cnt++;}
	return ans;
}

int main() {
	int n = 46500,i;
	memset(isprime,true,sizeof isprime);
	sieve(n);
	int cnt = 0;
	for(i=0;i<=n;i++){
		if(isprime[i]){prime[cnt] = i; cnt++;}
	}
	//printf("cnt: %d\n",cnt);
	ll a,b;
	while(scanf("%lld %lld",&a,&b)!=EOF){
		vi ans;
		ans = factorize(b);
		int ukuran = ans.size();
		//printf("faktor dari %lld\n",b);
		bool found = true;
		for(i=0;i<ukuran;i++){
			int bil = mapper[i], banyak = ans[i];
			
			//untuk setiap bil..cari di a..
			int pangkat = 1;
			ll bilawal = (ll) pow(bil,pangkat);
			while(bilawal<=a){
				ll offset = bilawal;
				while(offset<=a){
					banyak--;
					if(banyak==0){break;}
					offset+=bilawal;
				}
				if(banyak==0){break;}
				pangkat++;
				bilawal = (ll) pow(bil,pangkat);
			}
			if(banyak>0){printf("%lld does not divide %lld!\n",b,a); found = false; break;}
		}
		if(found){printf("%lld divides %lld!\n",b,a);}
		mapper.clear();
	}
	return 0;
}