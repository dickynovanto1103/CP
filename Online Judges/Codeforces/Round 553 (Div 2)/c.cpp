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
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

const ll mod = 1e9 + 7;

ii get(ll batas) {
	bool isGanjil = true;
	ll ganjil = 0, genap = 0;
	// printf("batas %lld\n",batas);
	ll n = 0;
	ll tot = 0;
	while(tot < batas) {
		if(n == 0){
			n = 1;
			tot += n;
			ganjil = 1;
			isGanjil = false;
		}else{
			ll cur = tot;
			// printf("cur: %lld\n",cur);
			n*=2LL;
			tot += n;
			// printf("tot nanti; %lld batas: %lld\n",tot,batas);
			if(tot > batas){
				if(isGanjil){
					ganjil += (batas - cur);
					isGanjil = false;
				}else{
					genap += (batas - cur);
					isGanjil = true;
				}
			}else{
				if(isGanjil){
					ganjil += n;
					isGanjil = false;
				}else{
					genap += n;
					isGanjil = true;
				}	
			}
			
		}
	}
	return ii(ganjil, genap);
}

ll modPow(ll a, ll b){
	if(b == 0){return 1;}
	else{
		if(b % 2 == 1){return a*modPow(a,b-1)%mod;}
		else{
			ll temp = modPow(a,b/2);
			return temp*temp%mod;
		}
	}
}

ll solveGanjil(ll ganjil) {
	ganjil %= mod;
	return ganjil*ganjil % mod;
}

ll solveGenap(ll genap) {
	ll bilGenap = genap * 2LL;
	ll banyakGanjil = bilGenap / 2LL;
	ll pengurangan = solveGanjil(banyakGanjil);

	bilGenap %= mod;
	ll tot = bilGenap*(bilGenap+1) % mod;
	tot *= modPow(2, mod-2);
	tot %= mod;

	tot -= pengurangan;
	if(tot < 0){tot += mod;}
	return tot;
}

ll solve(ll ganjil, ll genap) {
	ll ansGanjil = solveGanjil(ganjil);
	ll ansGenap = solveGenap(genap);
	// printf("ganjil: %lld genap: %lld ansGanjil: %lld ansGenap: %lld\n",ganjil, genap, ansGanjil, ansGenap);
	return (ansGenap + ansGanjil)%mod;
}

int main(){
	ll l,r;
	scanf("%lld %lld",&l,&r);
	ii pas = get(r);
	// printf("pas: %lld %lld\n", pas.first, pas.second);
	ll ans1 = solve(pas.first, pas.second);
	ii pas2 = get(l-1);
	ll ans2 = solve(pas2.first, pas2.second);
	ll ans = ans1 - ans2;
	if(ans < 0){ans += mod;}
	printf("%lld\n",ans);
	return 0;
};