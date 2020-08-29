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

ll a[200001];
ll pref[200001];

const ll mod = 1e9 + 7;

int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%lld",&a[i]);}
	pref[0] = a[0];
	for(i=1;i<n;i++) {
		pref[i] = pref[i-1] + a[i];
		pref[i] %= mod;
	}
	ll ans = 0;
	for(i=0;i<n-1;i++){
		ll jum = pref[n-1] - pref[i];
		jum %= mod;
		if(jum < 0){
			jum += mod;
		}
		ll num = a[i] * jum;
		num %= mod;
		ans += num;
		ans %= mod;
	}
	printf("%lld\n",ans);
	return 0;
};