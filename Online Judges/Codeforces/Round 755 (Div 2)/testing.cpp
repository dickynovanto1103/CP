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

ll a[1000000001];
map<ll, bool> mapper;

int main(){

	for(ll i=1;i<=inf;i++){

		if(i % 10000000 == 0) {printf("i: %lld\n", i);}
		ll ans = i *(i-1) / 2LL;
		a[i] = ans;
		mapper[a[i]] = true;
		if(i > 1) {
			ll selisih = a[i] - a[i-1];
			if(mapper.count(selisih)) {
				printf("khusus: %lld selisih: %lld\n", a[i], selisih);
			}

		}
		if(i <= 20) {
			printf("ans: %lld\n", ans);
		}
		ll bil = (ll) sqrt(ans * 2LL);
		if(bil * (bil+1) / 2LL != ans){
			printf("beda untuk idx: %lld, bil: %lld ans: %lld\n", i, bil, ans);
		}

	}
	
	return 0;
};