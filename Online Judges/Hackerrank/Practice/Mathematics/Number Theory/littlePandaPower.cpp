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

ll mod;
const int maxn = 1e6;
bool isprime[maxn];
int prime[78500];

ll modPow(ll a, ll b){
	if(b==0){return 1;}
	else{
		if(b%2==1){return (a%mod*modPow(a,b-1)%mod)%mod;}
		else{
			ll temp = modPow(a,b/2);
			return (temp%mod*temp%mod)%mod;
		}
	}
}
ll eulerPhi(ll n){
	ll pf_idx = 0, pf = prime[pf_idx], ans = n;
	while(pf*pf<=n){
		if(n%pf==0){ans-=ans/pf;}
		while(n%pf==0){n/=pf;}
		pf = prime[++pf_idx];
	}
	if(n!=1){ans-=ans/n;}
	return ans;
}

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

int main(){
	ll a,b,x;
	memset(isprime,true,sizeof isprime);
	sieve(maxn);
	int cnt = 0;
	for(int i=2;i<=maxn;i++){
		if(isprime[i]){prime[cnt] = i; cnt++;}
	}
	int tc;
	scanf("%d",&tc);
	while(tc--){
		scanf("%lld %lld %lld",&a,&b,&x);
		mod = x;
		if(x==1){printf("0\n"); continue;}
		if(b==0){
			if(mod==1){printf("0\n");}
			else{printf("1\n");}
		}else{
			ll ans;
			if(b<0){
				ll ans1 = modPow(a,eulerPhi(x)-1);
				ans = modPow(ans1,abs(b));
				// printf("ans1: %lld b: %lld ans: %lld\n",ans1,b,ans);
			}else{
				ans = modPow(a,b);
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
};