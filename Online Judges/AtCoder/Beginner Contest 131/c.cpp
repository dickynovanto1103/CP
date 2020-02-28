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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	ll a,b,c,d;
	scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
	ll lcm = c*d/__gcd(c,d);
	ll tot = b - a + 1;
	ll tot1 = (b / c) - ((a-1) / c);
	ll tot2 = (b / d) - ((a-1) / d);
	ll tot3 = (b / lcm) - ((a-1) / lcm);
	ll totSemua = tot1 + tot2 - tot3;
	printf("%lld\n",tot - totSemua);
	return 0;
};