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

const int maxn = 2e6 + 4;
const ll mod = 1e9 + 7;
ll fac[maxn];

ll modPow(ll a, ll b){
	if(b==0){return 1;}
	else{
		if(b%2==1){
			return (a*modPow(a,b-1))%mod;
		}else{
			ll temp = modPow(a,b/2);
			return (temp*temp)%mod;
		}
	}
}

ll c(ll a, ll b){
	return (((fac[a]%mod)*(modPow(fac[a-b],mod-2)%mod))%mod*(modPow(fac[b],mod-2)%mod)%mod);
}

int main(){
	int tc;
	ll n,m,i,j;
	fac[0] = 1;
	for(i=1;i<maxn;i++){
		fac[i] = (i%mod*fac[i-1]%mod)%mod;
	}
	scanf("%d",&tc);
	while(tc--){
		scanf("%lld %lld",&n,&m);
		printf("%lld\n",c(n+m-2,m-1));
	}
	return 0;
};