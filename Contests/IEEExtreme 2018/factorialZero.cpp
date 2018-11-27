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

ll banyakZero(ll bil, ll base){
	ll ans = 0;
	while(bil > 0){
		bil /= base;
		ans += bil;
	}
	return ans;
}

const int maxn = 100;

bool isprime[maxn + 10];
int prime[30];
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

vii listPangkat;

void factorize(int bil){
	int pf_idx = 0, prima = prime[pf_idx];
	while(prima*prima <= bil){
		if(bil % prime[pf_idx] == 0){
			int cnt = 0;
			int bilPrima = prime[pf_idx];
			while(bil % prime[pf_idx] == 0){
				bil /= prime[pf_idx];
				cnt++;
			}
			// printf("dipush %d %d\n",bilPrima, cnt);
			listPangkat.pb(ii(bilPrima, cnt));
		}
		pf_idx++;
		prima = prime[pf_idx];
	}
	if(bil != 1){
		// printf("halo ukuran sekarang: %d\n",(int)listPangkat.size());
		listPangkat.pb(ii(bil, 1));
	}
}

int main(){
	int tc,b,i,j;
	memset(isprime, true, sizeof isprime);
	sieve(maxn);
	int cnt = 0;
	for(i=0;i<maxn;i++){
		if(isprime[i]){
			prime[cnt++] = i;
		}
	}
	scanf("%d",&tc);
	ll n;

	while(tc--){
		listPangkat.clear();
		scanf("%d %lld",&b,&n);
		
		factorize(b);
		
		ll kiri = 0, kanan = (ll)inf*(ll)inf,mid;
		ll ans = -1;
		while(kiri <= kanan){
			mid = (kiri+kanan) / 2LL;
			ll minim = (ll)inf*(ll)inf;	
			for(i=0;i<listPangkat.size();i++){
				ll banyakNol = banyakZero(mid, listPangkat[i].first) / listPangkat[i].second;
				minim = min(minim,banyakNol);
			}
			if(minim == n){
				ans = mid;
				// printf("banyakNol: %lld ans diassign: %lld\n",banyakNol,mid);
				kanan = mid-1;
			}else{
				if(minim < n){
					kiri = mid+1;
				}else{
					kanan = mid-1;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
};