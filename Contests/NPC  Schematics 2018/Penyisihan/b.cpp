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

int main(){
	int tc,i,j;
	ll fib[100];
	fib[0] = fib[1] = 1;
	set<ll> s;
	for(i=2;i<100;i++){
		fib[i] = fib[i-1] + fib[i-2];
		// printf("fib[%d]: %lld\n",i,fib[i]);

		if(fib[i] > 1e18){
			break;
		}
		s.insert(fib[i]);
	}
	scanf("%d",&tc);
	ll n;
	
	while(tc--){
		scanf("%lld",&n);
		if(n > 10 && s.find(n)!=s.end()){
			printf("YEY\n");
			continue;
		}
		if(n==1){
			printf("6\n");
		}else{
			ll pangkat = n-1;
			ll bil1 = (modPow(2,pangkat)-1)%mod;
			if(bil1<0){bil1+=mod;}
			ll penambahan = (4LL*(bil1%mod))%mod;
			ll ans = 6LL + penambahan;
			printf("%lld\n",ans);
		}
	}
	return 0;
};