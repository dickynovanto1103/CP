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

const int maxn = 1e5 + 10;
const ll mod = 1e9 + 7;
ll fac[maxn], invFac[maxn];

ll modPow(ll a, ll b) {
	if(b==0){return 1;}
	else{
		if(b%2==1){return ((a%mod)*(modPow(a,b-1)%mod))%mod;}
		else{
			ll temp = modPow(a,b/2);
			return (temp%mod*temp%mod)%mod;
		}
	}
}

ll c(ll a, ll b){
	return (((fac[a]%mod)*(invFac[b]%mod))%mod*(invFac[a-b]%mod))%mod;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	fac[0]=1;
	invFac[0] = 1;
	for(i=1;i<=n;i++) {
		fac[i] = fac[i-1] * i;
		fac[i]%=mod;

		invFac[i] = modPow(fac[i],mod-2);
	}
	int bil,cntGenap = 0, cntGanjil = 0;
	for(i=0;i<n;i++){
		scanf("%d",&bil);
		if(bil%2==0){cntGenap++;}
		else{cntGanjil++;}
	}
	//printf("cntGenap: %d cntGanjil: %d\n",cntGenap, cntGanjil);
	//menghitung banyak cara memilih dari elemen genap aja
	ll banyakGenap = 0, banyakGanjil = 0, banyakCampuran = 0;
	for(i=1;i<=cntGenap;i++){
		ll temp = (c((ll) cntGenap,(ll) i));
		//printf("i: %d temp: %lld\n",i,temp);
		banyakGenap+=temp;
	}
	//menghitung banyaknya kombinasi dari ganjil saja dan campuran ganjil dan genap
	for(i=2;i<=cntGanjil;i+=2){
		ll temp = (c((ll) cntGanjil, (ll) i));
		banyakGanjil+=temp;
		banyakCampuran+=((temp%mod)*(banyakGenap%mod))%mod;
	}
	//printf("banyakGenap: %lld banyakGanjil: %lld banyakCampuran: %lld\n",banyakGenap, banyakGanjil, banyakCampuran);
	ll total = (((banyakGenap+banyakGanjil)%mod)+(banyakCampuran%mod))%mod;
	printf("%lld\n",total);
	return 0;
};