#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ll z,i,m;

ll f(ll x){
	return ((z*x)+i)%m;
}

ii floydCycleFinding(ll x0){
	//cari k*mu
	ll tortoise = f(x0), hare = f(f(x0));
	while(tortoise!=hare){tortoise = f(tortoise); hare = f(f(hare));}
	//cari mu
	int mu = 0; hare = x0;
	while(tortoise!=hare){tortoise = f(tortoise); hare = f(f(hare)); mu++;}
	//finding lambda
	int lambda = 1;hare = f(tortoise);
	while(tortoise!=hare){hare=f(hare); lambda++;}
	return ii(mu,lambda);
}

int main() {
	ll l;
	int test=1;
	while(scanf("%lld %lld %lld %lld",&z,&i,&m,&l),(z||i||m||l)){
		//printf("%lld %lld %lld %lld\n",z,i,m,l);
		ll x0 = l;
		ii pas = floydCycleFinding(x0);
		printf("Case %d: %d\n",test++,pas.second);
	}
	return 0;
}