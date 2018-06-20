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
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

ll a;

ii getMandN(ll a) {
	ll n = 1;
	ll m = a/2;
	return ii(m,n);
}	

int main(){
	ll i,j;
	
	scanf("%lld",&a);
	if(a<=2){printf("-1\n"); return 0;}
	if(a%2==0){
		ii ans = getMandN(a);
		ll m = ans.first, n = ans.second;
		printf("%lld %lld\n",m*m - n*n, m*m + n*n);
	}else{
		ll m,n;
		m = (a*a+1LL)/2LL;
		n = (a*a-1LL)/2LL;
		printf("%lld %lld\n",n,m);
	}
	
	return 0;
};
 