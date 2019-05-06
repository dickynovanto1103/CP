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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const ll mod = 1e9 + 7;

ll modPow(ll a, ll b){
	if(b == 0){return 1;}
	else{
		if(b % 2 == 1){
			return a * modPow(a,b-1) % mod;
		}else{
			ll temp = modPow(a,b/2);
			return temp*temp%mod;
		}
	}
}

int main(){
	int n,i;
	ll a[100010];
	a[0] = 1;
	for(i=1;i<=100000;i++){
		// a[i] = (2*i*(2*i-1)*a[i-1])/((i+1)*i);
		ll first = 2LL*(ll)i;
		ll second = (2LL*i-1);
		first *= second;
		first %= mod;
		a[i] = (first*a[i-1]) % mod;
		a[i] *= modPow((i+1), mod-2);
		a[i] %= mod;
		a[i] *= modPow(i, mod-2);
		a[i] %= mod;
		// printf("a[%d]: %lld\n",i,a[i]);
	}
	int idx;
	scanf("%d",&idx);
	// printf("idx: %d\n",idx);
	printf("%lld\n",a[idx]);

	return 0;
};