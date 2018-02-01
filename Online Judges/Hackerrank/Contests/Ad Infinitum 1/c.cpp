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

const int maxn = 1e3 + 10;
const ll mod = 1e9 + 7;
ll fac[maxn], invFac[maxn];

ll modPow(ll a, ll b) {
	if(b==0){return 1;}
	else{
		if(b%2==1){return ((a%mod)*(modPow(a,b-1))%mod)%mod;}
		else{
			ll temp = modPow(a,b/2);
			return ((temp%mod)*(temp%mod))%mod;
		}
	}
}

ll c(ll a, ll b){
	return (((fac[a]%mod) * (invFac[b]%mod))%mod * (invFac[a-b]%mod))%mod;
}

int main(){
	int tc;
	ll n,k,i,j;
	scanf("%d",&tc);
	fac[0] = 1; invFac[0] = 1;
	for(i=1;i<=1001;i++){
		fac[i] = fac[i-1]*i;
		fac[i]%=mod;

		invFac[i] = modPow(fac[i],mod-2);
	}
	ll s[maxn];
	while(tc--){
		scanf("%lld %lld",&n,&k);
		memset(s,0,sizeof s);
		s[0] = n%mod;
		for(i=1;i<=k;i++){//mencari S i,n
			s[i] = modPow(n+1,i+1) - 1LL;
			if(s[i]<0){s[i]+=mod;}
			ll total = 0;
			for(j=0;j<i;j++){
				ll ans = ((c(i+1,j)%mod)*(s[j]%mod))%mod;
				total+=(ans);
				total%=mod;
			}
			s[i]-=total;
			if(s[i]<0){s[i]+=mod;}
			s[i]*=modPow(i+1,mod-2);
			s[i]%=mod;

		}
		printf("%lld\n",s[k]);
	}
	return 0;
};