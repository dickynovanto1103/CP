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

ll modPow(ll a, ll b, ll c){
	if(b==0){return 1;}
	else{
		if(b%2==0){
			ll ans = modPow(a,b/2,c)%c;
			return ((ans%c * ans%c)%c);
		}else{
			return ((a%c*modPow(a,b-1,c)%c)%c);
		}
	}
}

int main() {
	ll n;
	ll mod = 1e9 + 7;
	scanf("%lld",&n);
	printf("%lld\n",modPow(2,n,mod) - 1);
	return 0;
}