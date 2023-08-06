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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const ll mod = 1e9 + 7;

ll getSumKuadrat(ll a, ll b) {
	ll ans1 = a * a; ans1 %= mod;
	ll ans2 = b*b; ans2 %= mod;
	return (ans1 + ans2) % mod;
}

int main(){
	int tc;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ", tt);
		int n;
		scanf("%d",&n);
		ll sumKuadrat = 0;
		ll sumAxis = 0, sumOrdinat = 0;

		for(int i=0;i<n;i++){
			ll a, b;
			scanf("%lld %lld",&a,&b);
			sumKuadrat += (a*a); sumKuadrat %= mod;
			sumKuadrat += (b*b); sumKuadrat %= mod;
			sumAxis += a; sumAxis %= mod;
			sumOrdinat += b; sumOrdinat %= mod;
		}

		int q;
		scanf("%d",&q);
		ll sum = 0;
		while(q--){
			int a, b;
			scanf("%d %d",&a,&b);
			sum += sumKuadrat; sum %= mod;

			sum += (ll)n * getSumKuadrat(a, b); sum %= mod;
			sum += (-2LL * a * sumAxis); sum %= mod;
			sum += (-2LL * b * sumOrdinat); sum %= mod;
			if(sum < 0) {sum += mod;}
		}

		printf("%lld\n", sum);
	}
	
	return 0;
};