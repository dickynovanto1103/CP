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

const ll mod = 1e9 + 7;

const int maxn = 2e5 + 5;

ll fact[maxn], invFact[maxn];

ll modPow(ll a, ll b){
	if(b == 0){return 1;}
	else{
		if(b%2==1){return a*modPow(a,b-1)%mod;}
		else{
			ll temp = modPow(a,b/2);
			return temp*temp%mod;
		}
	}
}

ll inv(ll a){
	return modPow(a,mod-2);
}

ll comb(ll a, ll b){
	return ((fact[a]*invFact[b])%mod)*(invFact[a-b]%mod)%mod;
}

int main(){
	int tc,i,j,n,m;
	scanf("%d",&tc);
	fact[0] = 1; invFact[0] = 1;
	for(i=1;i<maxn;i++){
		fact[i] = fact[i-1] * i;
		fact[i] %= mod;
		invFact[i] = inv(fact[i]);
	}
	
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d %d",&n,&m);
		ll ans = fact[2*n];
		int banyakSlot = 2*n;
		ll tot = 0;
		// printf("ans: %lld\n",ans);
		for(i=1;i<=m;i++){
			int terpakai = 2*i;
			int sisa = banyakSlot - terpakai;
			// printf("sisa: %d\n",sisa);
			ll jawab = fact[2*n-i] %mod;
			// ll jawab = ((fact[i]%mod) * (comb(2*n-i, i)%mod)) % mod;
			// printf("jawab: %lld\n",jawab);
			// jawab*=1000;
			// jawab %= mod;
			// printf("jawab sekarang: %lld\n",jawab);
			// printf("comb dari %d dan %d\n",sisa+i, i);
			jawab *= modPow(2,i);
			jawab %= mod;
			jawab *= comb(m, i);
			jawab %= mod;

			if(i%2 == 0){jawab *= -1;}
			// printf("jawab: %lld\n",jawab);
			tot += jawab;
			if(tot < 0){tot += mod;}
			tot %= mod;
			// printf("tot jadi: %lld\n", tot);
			
		}
		// printf("tot: %lld\n",tot);
		ans -= tot;
		//tadi
		// if(ans < 0){ans += tot;}

		if(ans < 0){ans += mod;}
		
		
		printf("%lld\n",ans);
	}

	return 0;
};