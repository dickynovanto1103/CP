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

ll gcdExtended(ll a, ll b, ll &x, ll &y) {
	if(a==0LL){
		x = 0LL;
		y = 1LL;
		return b;
	}
	ll x1,y1;
	
	ll hasilGCD = gcdExtended(b%a, a, x1,y1);
	x = y1 - (b/a)*x1;
	y = x1;
	return hasilGCD;
}

bool findSolution(ll a, ll b, ll c, ll &x, ll &y, ll &gcd) {
	ll aSebenernya = (a < 0LL)? -a: a;
	ll bSebenarnya = (b<0LL)? -b: b;

	gcd = gcdExtended(aSebenernya,bSebenarnya,x,y);
	if(c%gcd){
		return false;
	}
	x*=(c/gcd);
	y*=(c/gcd);
	
	if(a<0LL){x = -x;}
	if(b<0LL){y = -y;}
	return true;
}

int main(){
	ll n,m,a,k;
	while(scanf("%lld %lld %lld %lld",&n,&m,&a,&k)) {
		if(n==0 && m==0 && a==0 && k==0){break;}
		ll selisih = a+k-n;
		ll x,y;
		ll ans;
		if(m==0 && a==0){printf("Impossible\n"); continue;}
		
		if(findSolution(m,-a,selisih, x,y,ans)) {
			// printf("n: %lld m: %lld a: %lld x: %lld y: %lld m*x: %lld\n",n,m,a,x,y,m*x);
			ll pengali = (y*ans)/m;
			// printf("k: %lld\n",pengali);

			ll xJawaban = x+pengali*(-a/ans);
			ll yJawaban = y-pengali*(m/ans);
			// xJawaban = x;
			// yJawaban = y;
			ll jawab1 = n+m*xJawaban;
			ll jawab2 = a+k + a*yJawaban;
			
			
			printf("%lld\n",jawab1);
			// printf("%lld\n",jawab2);
		}else{
			printf("Impossible\n");
		}
	}
	return 0;
};