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

int main() {
	ll m,b;
	ll sum = 0;
	scanf("%lld %lld",&m,&b);
	for(ll y=0;y<=b;y++){
		ll x = (b-y)*m;
		ll ans = (x+1)*(y*(y+1)/2) + (y+1)*(x*(x+1)/2);
		sum = max(sum,ans);
	}
	printf("%lld\n",sum);
	return 0;
}