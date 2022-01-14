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

ll banyak(ll a){
	return a * (a + 1) / 2LL;
}

ll total(ll a, ll b) {
	return banyak(b) - banyak(a-1);
}

int main(){
	ll n,f,d;
	while(scanf("%lld %lld %lld",&n,&f,&d) !=EOF) {
		if(n < f){puts("NO"); continue;}
		ll minimJarak = (ll)f * (f+1) / 2LL;
		if(d < minimJarak){puts("NO"); continue;}
		ll selisih = d - minimJarak;
		ll selisihWaktu = n - f;
		ll bagi2 = selisihWaktu / 2;

		ll maksTambahan = total(f + 1, f + bagi2) + total(f, f + (selisihWaktu % 2 == 0 ? bagi2 - 1 : bagi2));
		// printf("selisih: %lld selisihWaktu: %lld bagi2: %lld\n", selisih, selisihWaktu, bagi2);
		// printf("maksTambahan: %lld -> %lld %lld and %lld %lld\n", maksTambahan, f + 1, f + bagi2, f, f + (bagi2 % 2 == 0 ? bagi2 - 1 : bagi2));
		if(maksTambahan < selisih){puts("NO"); continue;}
		puts("YES");
	}
	
	
	return 0;
};