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
const int maxn = 1e5 + 5;

ll fib[maxn];
ll a[maxn], b[maxn];
int main(){
	int tc,i,j;
	ll m,n;

	fib[0] = 0;
	fib[1] = 1;
	for(i=2;i<maxn;i++){
		fib[i] = fib[i-1] + fib[i-2];
		fib[i] %= mod;
	}
	fib[0] = 1;

	scanf("%d",&tc);
	while(tc--){
		scanf("%lld %lld",&m,&n);
		ll totalAtas = 0;
		for(i=0;i<m;i++) {
			scanf("%lld",&a[i]);
			totalAtas+=a[i];
			totalAtas%=mod;
		}

		ll totalBawah = 0;
		for(i=0;i<m;i++) {
			scanf("%lld",&b[i]);
			totalBawah+=b[i];
			totalBawah%=mod;
		}

		ll koefBawah = fib[n-1];
		ll koefAtas;
		if(n==1){
			koefAtas = 1;
			koefBawah = 0;
		}else if(n==2){
			koefAtas = 0;
			koefBawah = 1;
		}else{
			koefAtas = fib[n-2];
		}
		
		
		// printf("koefAtas: %d n-2: %lld\n",koefAtas,n-2);
		ll ans = 0;
		
		ll ans1 = (((m%mod)*(koefAtas%mod))%mod*(totalAtas%mod))%mod;
		ll ans2 = (((totalBawah*koefBawah)%mod) * (m%mod)) %mod;
		ll jawab = (ans1+ans2) %mod;
		ans += jawab;
		ans %= mod;
		
		printf("%lld\n",ans);
	}
	
	return 0;
};