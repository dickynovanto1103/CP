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

ll modPow(ll a, ll b, ll mod){
	if(b==0){return 1;}
	else{
		if(b%2==1){
			return (a*modPow(a,b-1, mod))%mod;
		}else{
			ll temp = modPow(a,b/2,mod);
			return (temp*temp)%mod;
		}
	}
}

int main(){
	ll a,b,p,x,i,j;
	scanf("%lld %lld %lld %lld",&a,&b,&p,&x);
	ll cnt = 0;
	ll mod = p;
	for(i=1;i<=100;i++){
		ll hasilModPow = modPow(a,i,mod);
		ll hasilModPowMod = hasilModPow%mod;
		ll hasilIMod = i%mod;
		ll ans = (i%mod*hasilModPow%mod)%mod;
		printf("i: %lld hasilModPow: %lld ans: %lld\n",i,hasilModPow,ans);
		printf("hasilIMod: %lld hasilModPowMod: %lld\n",hasilIMod,hasilModPowMod);
		if(ans==b){
			cnt++;
		}
	}
	printf("%lld\n",cnt);
	return 0;
};