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
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const ll mod = 1e9 + 7;

ll modPow(ll a, ll b) {
	if(b == 0){return 1;}
	else{
		if(b%2 == 1){return a * modPow(a,b-1) % mod;}
		else{
			ll temp = modPow(a, b/2);
			return temp * temp % mod;
		}
	}
}

int main(){
	int k;
	scanf("%d",&k);

	ll ans = 6;
	ll banyakNode = 0;
	for(int i=1;i<=k-1;i++) {
		banyakNode += (1LL<<i); // pangkat ga bs dimod
	}
	ll tambahan = modPow(4, banyakNode);
	tambahan %= mod;
	// printf("tambahan: %lld\n", tambahan);
	ans *= tambahan;
	ans %= mod;
	printf("%lld\n", ans);
	
	return 0;
};