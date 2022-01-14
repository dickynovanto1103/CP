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

map<ii, ll> mapper;

ll ask(int l, int r) {
	if(mapper.count(ii(l,r)) > 0){
		return mapper[ii(l, r)];
	}
	printf("? %d %d\n", l, r);
	fflush(stdout);
	ll ans;
	scanf("%lld",&ans);
	if(ans == -1){
		exit(0);
	}
	mapper[ii(l,r)] = ans;
	return ans;
}

bool isValid(ll bil) {
	ll num = (ll)sqrt(bil * 2LL);
	return (num * (num + 1)) / 2LL == bil;
}

ll banyakBil(ll bil) {
	ll num = (ll)sqrt(bil * 2LL);
	return num + 1;
}

void answer(ll i, ll j, ll k) {
	printf("! %lld %lld %lld\n", i,j,k);
	fflush(stdout);
}

int main(){
	int tc,n;
	scanf("%d",&tc);
	while(tc--){
		mapper.clear();
		scanf("%d",&n);
		ll ansAll = ask(1, n);

		//cari dari kiri dulu
		int kiri = 1, kanan = n, ans = 1, mid;

		//find most kanan first dari kiri
		ll ansKiri = 0;
		while(kiri <= kanan) {
			mid = (kiri + kanan) / 2LL;
			ll jawab = ask(1, mid);
			if(jawab == ansAll) {
				kanan = mid - 1;
				continue;
			}else if(jawab == 0){
				kiri = mid + 1;
				continue;
			}

			if(isValid(jawab)) {
				//perlu divalidate lagi
				if(mid > 1) {
					jawab = ask(1, mid-1);
					ll jawabPertama = jawab;
					if(isValid(jawab)) {
						//berarti masih valid kiri ini
						ans = max(ans, mid);
						ansKiri = max(ansKiri, jawabPertama);
						kiri = mid + 1;
					}else{
						kanan = mid-1;
					}
					continue;
				}
				
				ans = max(ans, mid);
				ansKiri = max(ansKiri, jawab);
				kiri = mid + 1;
			}else{
				kanan = mid - 1;
			}
		}
		// printf("ans akhir: %d\n", ans);
		ll ansKanan = ansAll - ansKiri;
		ll banyakKanan = banyakBil(ansKanan);
		ll k = ans + banyakKanan - 1;
		ll banyakKiri = banyakBil(ansKiri);
		ll i = ans - banyakKiri;
		assert(ans >= 1 && ans <= n);
		assert(i >= 1 && i <= n);
		assert(k >= 1 && k <= n);
		answer(i, ans, k);
	}
	
	return 0;
};