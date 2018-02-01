//using lucas theorem

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
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ll modPow(ll a, ll b, ll mod) {
	if(b==0){return 1;}
	else{
		if(b%2==1){
			return ((a%mod)*(modPow(a,b-1,mod)%mod))%mod;
		}else{
			ll temp = modPow(a,b/2,mod);
			return ((temp%mod)*(temp%mod))%mod;
		}
	}
}

ll modInverse(ll bil, ll mod){
	return modPow(bil,mod-2,mod);
}

ll fac(ll bil, ll mod){
	ll i;
	ll ans = 1;
	for(i=2;i<=bil;i++){
		ans*=i;
		//printf("ans jd: %lld\n",ans);
		ans%=mod;
	}
	return ans;
}

int main(){
	int tc,i,j;
	ll n,k,p;
	scanf("%d",&tc);
	vi a,b;
	while(tc--){
		scanf("%lld %lld %lld",&n,&k,&p);
		ll hasilPangkat[100];
		hasilPangkat[0] = 1;
		int pangkatTertinggi = 0;
		//menentukan pangkat tertinggi
		for(i=1;;i++){
			hasilPangkat[i] = hasilPangkat[i-1]*p;
			pangkatTertinggi++;
			if(hasilPangkat[i]>n){pangkatTertinggi--; break;}
		}
		//printf("pangkatTertinggi: %d\n",pangkatTertinggi);
		for(i=pangkatTertinggi;i>=0;i--){
			ll hasilBagi = n/hasilPangkat[i];
			ll sisa = n%hasilPangkat[i];
			if(i==0){a.pb(n);}
			else{
				n=sisa;
				//printf("n jadi: %lld\n",n);
				a.pb(hasilBagi);
			}
			
			hasilBagi = k/hasilPangkat[i];
			sisa = k%hasilPangkat[i];
			if(i==0){b.pb(k);}
			else{
				k = sisa;
				//printf("k jadi: %lld\n",k);
				b.pb(hasilBagi);
				
			}
			
		}
		ll ans = 1;
		for(i=0;i<a.size();i++){
			ll bil1 = a[i];
			ll bil2 = b[i];
			// printf("bil1: %lld bil2: %lld\n",bil1,bil2);
			if(bil1<bil2){ans*=0;}
			else{
				ans=ans*((fac(bil1,p)*modInverse(fac(bil2,p),p))%p*modInverse(fac(bil1-bil2,p),p))%p;
				// printf("fac: %lld\n",fac(bil1,p));
				ans%=p;
			}
		}
		printf("%lld\n",ans);
		a.clear(); b.clear();
	}
	return 0;
};

