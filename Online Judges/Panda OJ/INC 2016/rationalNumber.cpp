#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool isprime[31701];
int prime[3410];

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

ll gcd(ll a, ll b){return b==0 ? a: gcd(b,a%b);}

ll modPow(ll a, ll b, ll mod){
	if(b==0){return 1;}
	else{
		if(b%2==0){return (modPow(a,b/2,mod)%mod * modPow(a,b/2,mod)%mod)%mod;}
		else{return (a%mod*modPow(a,b-1,mod)%mod)%mod;}
	}
}
ll eulerPhi(ll n){
	ll idx = 0, pf = prime[idx], ans = n;
	while(pf*pf<=n){
		if(n%pf==0){ans-=ans/pf;}
		while(n%pf==0){n/=pf;}
		pf = prime[++idx];
	}
	if(n!=1){ans-=ans/n;}
	return ans;
}

int main() {
	ll i;
	int n = 31700, cnt = 0;
	memset(isprime,true,sizeof isprime);
	sieve(n);
	for(i=0;i<=n;i++){
		if(isprime[i]){prime[cnt] = i; cnt++;}
	}
	int tc;
	ll a,b;
	scanf("%d",&tc);
	int test = 1;
	while(tc--){
		printf("Case #%d: ",test++);
		scanf("%lld %lld",&a,&b);
		a = abs(a); b = abs(b);
		int pembagi = gcd(a,b);
		a/=pembagi; b/=pembagi;
		//ilangin faktor 2 dan 5 dari b;
		while(b%2==0){b/=2;}
		while(b%5==0){b/=5;}
		ll tot = eulerPhi((ll)b);
		ll ans = 0;
		if(b>1){
			//cari bil yang lebih kecil dari totient yang membagi habis totient..order unit theorem 
			ans = tot;
			for(i=1;i*i<=tot;i++){
				if(tot%i==0){
					if(modPow(10,i,b)==1){ans = min(ans,i);}
					ll j = tot/i;
					if(modPow(10,j,b)==1){ans = min(ans,j);}

				}
			}
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}