#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int mod = 1e9 + 7;

int main() {
	ll a,b;
	scanf("%lld %lld",&a,&b);
	ll minim = min(a,b);
	ll sum = 0;
	for(ll i=1;i<=minim;i++){
		sum+=(i*(a/i)*(b/i));
		sum%=mod;
	}
	printf("%lld\n",sum);
	return 0;
}