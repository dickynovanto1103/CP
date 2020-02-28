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

ll findLCM(ll a, ll b){
	return (a/__gcd(a,b))*b;
}

const ll mod = 1e9 + 7;

int main(){
	int n,i,j;
	scanf("%d",&n);
	ll a[10001];
	ll lcm;
	ll gcd = 0;
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
		gcd = __gcd(a[i], gcd);
		if(i == 0){lcm = gcd;}
		else{
			lcm = findLCM(lcm, a[i]);
		}
	}
	// printf("%lld\n",lcm);
	bool sama = true;
	for(i=1;i<n;i++){
		if(a[i] != a[i-1]){
			sama = false;
		}
	}
	if(sama){printf("%d\n",n);}
	else{
		ll ans = 0;
		for(i=0;i<n;i++){
			ll bagi = lcm / a[i];
			ans += bagi;
			ans %= mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
};