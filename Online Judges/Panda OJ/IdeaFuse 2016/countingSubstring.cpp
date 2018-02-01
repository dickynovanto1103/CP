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
ll modPow(ll a, ll b){
	if(b==0){return 1LL;}
	else{
		if(b%2==1){
			return ((a%mod)*(modPow(a,b-1)%mod))%mod;
		}else{
			ll temp = modPow(a,b/2);
			return (((temp%mod)*(temp%mod))%mod);
		}
	}
}

ll modInverse(ll a){
	return modPow(a,mod-2)%mod;
}

ll fac(int a){
	ll ans = 1;
	for(int i=2;i<=a;i++){
		ans=ans*i;
		ans%=mod;
	}
	return ans;
}

int main(){
	string kata;
	int k, i,j;
	cin>>kata>>k;
	int pjg = kata.length();
	set<string> listKata;
	for(i=0;i<pjg;i++){
		//printf("i: %d\n",i);
		for(j=1;j<400;j++){
			if((j+i)>pjg){break;}
			string kataTerambil;
			kataTerambil = kata.substr(i,j);
			listKata.insert(kataTerambil);
		}
	}
	//printf("ukuran: %d\n",listKata.size());
	int ukuran = listKata.size();
	if(k>ukuran){printf("0\n");}
	else{
		ll ans = (((fac(ukuran)%mod) *(modInverse(fac(ukuran-k))%mod))%mod * modInverse(fac(k)%mod)%mod)%mod;
		printf("%lld\n",ans);
	}
	return 0;
};