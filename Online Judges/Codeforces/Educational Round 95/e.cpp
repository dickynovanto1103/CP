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

ll pref[200001];

const ll mod = 998244353;

ll modPow(ll a, ll b){
	if(b == 0){return 1;}
	else{
		if(b % 2 == 1){return a * modPow(a, b-1)%mod;}
		else{
			ll temp = modPow(a, b/2);
			return temp*temp%mod;
		}
	}
}

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	int d[200001];
	int strong = 0, weak = 0;
	for(i=0;i<n;i++){
		scanf("%d",&d[i]);
	}
	sort(d, d+n);
	for(i=0;i<n;i++){
		pref[i] = d[i];
		if(i){
			pref[i] += pref[i-1];
		}
	}
	while(m--){
		int a,b;
		scanf("%d %d",&a,&b);
		int idx = lower_bound(d, d + n, b) - d;
		ll small = idx, big = n - small;
		//idea: let's say we iterate through all n monster one by one...we can know how much damage this monster can contribute to the final answer...we can use linearity of expectation
		//expected damage monster i can give is d[i] * P(monster i come after a other big monsters).
		// to calculate the probability, we can use rather complex binomial function, but we can come up with a simpler solution
		//if the monster is big...and there are k big monsters, then the probability that this monster can deal damage is max(k - a, 0) / k ...we can do this as all arrangement has the same probability
		//if the monster is small, and there are k big monsters, then the probability that this small monster can deal damage is max(k + 1 - a, 0) / (k+1)
		// this can be calculated this way because now there are k + 1 slots (k monsters + 1 small monster), and we want to know the probability to fill the remaining slots.
		
		//to compute fast...since all probability are in the same formula, then we can use prefix sum to know the total damage for small monsters and big monsters
		ll totSmallDamage = (idx == 0 ? 0 : pref[idx-1]); totSmallDamage %= mod;
		ll totBigDamage = pref[n-1] - totSmallDamage; totBigDamage %= mod;
		
		ll pembilangSmall = totSmallDamage * max(big + 1 - a, 0LL); pembilangSmall %= mod;
		ll penyebutSmall = big + 1;

		ll pembilangBig = totBigDamage * max(big - a, 0LL); pembilangBig %= mod;
		ll penyebutBig = big;

		ll penyebutTotal = penyebutSmall * penyebutBig; penyebutTotal %= mod;
		ll pembilangTotal = pembilangBig * (big + 1); pembilangTotal %= mod;
		pembilangTotal += pembilangSmall * big; pembilangTotal %= mod;

		ll expected = pembilangTotal * modPow(penyebutTotal, mod-2);
		expected %= mod;

		printf("%lld\n",expected);
	}
	
	return 0;
};