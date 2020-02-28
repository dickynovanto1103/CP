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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const ll mod = 1e9 + 7;
const int maxn = 1e6 + 6;
ll fac[maxn];
ll invFac[maxn];

ll modPow(ll a, ll b) {
	if(b == 0){return 1;}
	else{
		if(b%2 == 1){return a*modPow(a,b-1)%mod;}
		else{
			ll temp = modPow(a,b/2);
			return temp*temp%mod;
		}
	}
}

ll modInv(ll a){
	return modPow(a,mod-2);
}

ll c(int a, int b){
	return (fac[a]*invFac[b]%mod)*invFac[a-b]%mod;
}

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	fac[0] = 1, invFac[0] = 1;
	for(i=1;i<maxn;i++){
		fac[i] = i*fac[i-1];
		fac[i] %= mod;
		invFac[i] = modInv(fac[i]);
	}
	ll ans = 0;
	for(i=0;i<=n;i++){
		int sisa = n-i;
		int banyak1 = i;
		if(sisa % 2 == 1){continue;}
		int banyak2 = sisa/2;
		int banyak = banyak1 + banyak2;
		int totY = banyak1*2 + banyak2;
		if(totY == m){
			ans += c(banyak, banyak1);
			ans %= mod;
		}
	}
	printf("%lld\n",ans);
	return 0;
};