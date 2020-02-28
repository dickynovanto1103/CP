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
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

const int maxn = 2e5 + 5;

ll lcm(ll a, ll b){
	return a*(b/__gcd(a,b));
}

ll getGcd(const vi& a) {
	ll gcd = a[0];
	for(int i=1;i<a.size();i++){
		gcd = __gcd(gcd, a[i]);
	}
	return gcd;
}

int main(){
	int n,i,j;
	int a[maxn];
	while(scanf("%d",&n)!=EOF){
		vi v;
		int maks = 0;
		ll tot = 0;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			maks = max(maks, a[i]);
			tot += a[i];
			if(a[i]){
				v.pb(a[i]);
			}
		}

		ll kpk = v[0];
		for(i=1;i<v.size();i++){
			kpk = lcm(kpk, v[i]);
		}
		ll selisih = 0;
		vi listSelisih;
		for(i=0;i<n;i++){
			selisih += (maks - a[i]);
			listSelisih.pb(maks-a[i]);
		}
		ll banyakAmbil = getGcd(listSelisih);
		ll banyakOrang = selisih / banyakAmbil;
		ii ans = ii(banyakOrang, banyakAmbil);
		listSelisih.clear();
		selisih = 0;
		for(i=0;i<n;i++){
			selisih += (kpk - a[i]);
			listSelisih.pb(kpk - a[i]);
		}
		banyakAmbil = getGcd(listSelisih);
		banyakOrang = selisih / banyakAmbil;
		ans = min(ans, ii(banyakOrang, banyakAmbil));
		ll tambahan = ans.first * ans.second;
		tot += tambahan;
		ll maksJadi = tot / (ll)n;
		ll gcdAns = __gcd(ans.first, ans.second);
		ii temp = ans;
		if(gcdAns != 1){
			while(ans.first > 0) {
				ans.first /= gcdAns;
				ans.second *= gcdAns;
				bool valid = true;
				for(i=0;i<n;i++){
					ll selisih = (maksJadi - a[i]);
					if(selisih % ans.second != 0){
						valid =false;
						break;
					}
				}
				if(valid){temp = ii(ans.first, ans.second);}
			}	
		}
		
		printf("%lld %lld\n",temp.first, temp.second);	
	}
	
	
	return 0;
};