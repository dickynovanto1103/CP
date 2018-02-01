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

const int maxn = 1e6 + 100;
bool isprime[maxn+10];
ll prime[78500];

void sieve(ll n){
	ll i,j;
	isprime[0] = isprime[1] = false;
	for(i=2;i*i<=n;i++){
		if(isprime[i]){
			for(j=i*2;j<=n;j+=i){
				isprime[j] = false;
			}	
		}
	}
}

ll getFirstDivisor(ll n){
	
	ll idx = 0, pf = prime[idx];
	while(pf*pf<=n) {
		
		if(n%pf==0){
			
			return pf;
		}
		while(n%pf==0){n/=pf;}
		pf = prime[++idx];
	}
	//if(n!=1){return n;}
	//if(n<=0){return 1;}
	return n;
}

ll solve(ll bil) {
	//if(bil==1){return 1;}
	
	ll ans = 0;
	while(bil>1){
		ll pembagi = getFirstDivisor(bil);
		ans+=(bil);
		//printf("bil: %lld\n",bil);
		//if(pembagi==0){break;}
		bil = bil/pembagi;
	}
	ans++;
	return ans;

}

int main(){
	memset(isprime,true,sizeof isprime);
	sieve(maxn);
	int cnt = 0,i;
	for(i=0;i<=maxn;i++){
		if(isprime[i]){
			prime[cnt] = (ll)i;
			cnt++;
		}
	}
	int tc;
	ll n;
	
	scanf("%d",&tc);
	ll ans = 0;
	while(tc--){
		scanf("%lld",&n);
		//printf("n: %lld\n",n);
		ll jawab = solve(n);
		//printf("n: %lld jawab: %lld\n",n,jawab);
		ans+=(jawab);
		
	}
	printf("%lld\n",ans);
	return 0;
};