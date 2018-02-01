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
const int mod = 1000000007;

ll modPow(ll a, ll b, ll c){
	if(b==0){return 1;}
	else{
		if(b%2==0){
			ll ans = modPow(a,b/2,c);
			return (ans%c * ans%c)%c;
		}else{
			return (a%c*(modPow(a,b-1,c)%c))%c;
		}
	}
}

int main() {
	ll n;
	scanf("%lld",&n);
	ll tot = mod-1;
	ll pangkat = modPow(3,n,tot);
	ll ans = modPow(3,pangkat,mod);
	printf("%lld\n",ans);
	return 0;
}