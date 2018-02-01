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

const int maxn = 1e5 + 5;
const ll mod = 1e9 + 7;
ll fac[2*maxn + 10];
ll invFac[2*maxn + 10];

ll modPow(ll a, ll b){
	if(b==0){return 1;}
	else{
		if(b%2==1){
			return ((a%mod)*(modPow(a,b-1)%mod))%mod;
		}else{
			ll temp = modPow(a,b/2);
			return ((temp%mod)*(temp%mod))%mod;
		}
	}
}

ll c(ll a, ll b){
	return (((fac[a]%mod)*(invFac[a-b]%mod))%mod*(invFac[b]%mod))%mod;
}

int main(){
	int tc,i,j;
	ll n,m;
	scanf("%d",&tc);
	fac[0] = 1;
	invFac[0] = 1;
	for(i=1;i<=2*maxn;i++){
		fac[i] = ((i%mod)*(fac[i-1]%mod))%mod;
		invFac[i] = modPow(fac[i],mod-2);
	}
	while(tc--){
		scanf("%lld %lld",&n,&m);
		ll selisih = n-2*m;
		if(selisih<0){printf("0\n"); return 0;}
		printf("%lld\n",c(selisih+m-1,m-1));

	}
	return 0;
};