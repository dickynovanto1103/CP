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
ll modPow(ll a, ll b){
	if(b==0){return 1;}
	else{
		if(b%2==1){return (a*modPow(a,b-1))%mod;}
		else{
			ll temp = modPow(a,b/2);
			return (temp*temp)%mod;
		}
	}
}

ll modInverse(ll a){
	return modPow(a,mod-2);
}

int main(){
	printf("%lld\n",modInverse(2048));
	ll pangkat = mod-1-11;

	printf("%lld\n",modPow(2,pangkat));
	return 0;
};