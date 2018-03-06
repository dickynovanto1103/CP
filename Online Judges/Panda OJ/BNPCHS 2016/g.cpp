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

const int maxn = 1e6 + 1;
const ll mod = 1e9 + 7;
ll fac[maxn];
ll invFac[maxn];

ll modPow(ll a, ll b){
	if(b==0){return 1;}
	else{
		if(b%2==1){return (a*modPow(a,b-1))%mod;}
		else{
			ll temp = modPow(a,b/2);
			return (temp*temp)%mod;
		}
	}
}

ll c(ll a, ll b){
	return ((fac[a]%mod*invFac[b]%mod)%mod*invFac[a-b]%mod)%mod;
}

int main(){
	int tc,n,j;
	ll i;
	scanf("%d",&tc);
	fac[0] = 1;
	invFac[0] = 1;
	for(i=1;i<maxn;i++){
		fac[i] = (i%mod*fac[i-1]%mod)%mod;
		fac[i]%=mod;
		invFac[i] = modPow(fac[i],mod-2)%mod;
	}

	for(int tt=1;tt<=tc;tt++){
		scanf("%d",&n);
		ll ans = 0;
		for(i=1;i<=n;i++){
			ll nilai1 = c(n,i)%mod;
			ll nilai2 = c(n,i-1)%mod;
			// printf("i: %lld\n",i);
			// printf("nilai1: %lld nilai2: %lld\n",nilai1,nilai2);
			ll jawab = (nilai1*nilai2)%mod;
			ans+=jawab;
			ans%=mod;
		}
		printf("Kasus #%d: %lld\n",tt, ans);
	}
	return 0;
};