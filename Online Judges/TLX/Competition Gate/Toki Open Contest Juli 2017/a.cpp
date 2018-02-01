#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int mod = 1e9 + 7;

ll fac[11];

int main() {
	ll ans,n,x,y;
	ll i;
	fac[0] = 1;
	for(i=1;i<=10;i++){
		fac[i] = fac[i-1]*i;
	}
	//for(i=0;i<=10;i++){printf("%lld\n",fac[i]);}
	scanf("%lld",&n);

	if(n%2==0){x=0;}
	else{x=1;}
	ans = 0;
	for(i=x;i<=n;i+=2){
		ll bagi = (n-i)/2;
		ll caraPanti = (fac[n]/((fac[n-i]*(fac[i]))));
		ll sisa = n-i;
		ll caraCucu = (fac[sisa]/(fac[sisa-bagi]*fac[bagi]));

		ans+=(caraPanti*caraCucu);
		ans%=mod;
	}
	printf("%lld\n",ans);
	return 0;
}