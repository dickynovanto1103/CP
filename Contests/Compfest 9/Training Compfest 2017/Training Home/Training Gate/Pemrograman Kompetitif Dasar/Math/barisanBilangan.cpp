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

ll gcd(ll a, ll b){return b==0? a: gcd(b,a%b);}
ll lcm(ll a, ll b){return a*(b/gcd(a,b));}

int main() {
	ll a,b,n;
	scanf("%lld %lld %lld",&n,&a,&b);
	ll ans = (n/a) + (n/b) - (n/lcm(a,b));
	printf("%lld\n",ans);
	return 0;
}