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

ll a[500010];
ll pref[1000010];

void solve(){
	ll n,m,c;
	scanf("%lld %lld %lld",&n,&m,&c);
	if(n == 1) {
		printf("%lld\n", m);
		return;
	}

	set<ll> s;
	set<ll>::iterator it;
	unordered_map<ll, int> cnt;

	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		if(a[i] == 0){
			a[i] = m;
		}

		s.insert(a[i]);
		cnt[a[i]]++;
	}
	s.insert(m);
	if(s.size() == 1) {
		printf("%lld\n", (ll)cnt[m] * m);
		return;
	}
	
	vector<ll> list;
	for(it = s.begin(); it!=s.end();it++){
		list.pb(*it);
	}

	int tempSum = 0;
	for(int i=0;i<list.size();i++) {
		pref[i] = cnt[list[i]];
		tempSum += cnt[list[i]];
	}

	if(tempSum != n) {
		puts("asu");
		return;
	}
	assert(tempSum == n);
	int idx = list.size();

	for(int i=idx;i<=idx*2;i++){
		pref[i] = pref[i - idx];
	}

	for(int i=0;i<=idx*2;i++){
		if(i > 0) {pref[i] += pref[i-1];}
	}
	if(pref[idx*2 - 1] != 2*n) {
		puts("asu");
		return;
	}
	assert(pref[idx*2 - 1] == 2*n);

	ll sum = 0;
	ll prev = 0;
	for(int i=0;i<idx;i++){
		//binser
		int l = 1, r = idx*2 - i, mid, ans = -1;
		while(l <= r) {
			mid = (l + r) / 2;
			ll temp = pref[i + mid - 1] - (i == 0 ? 0 : pref[i-1]);
			if(temp >= c) {
				ans = temp;
				r = mid-1;
			}else{
				l = mid + 1;
			}
		}
		assert(ans > -1);

		ll pengali = list[i] - prev;

		sum += ((ll)ans * pengali);
		prev = list[i];
	}

	printf("%lld\n", sum);
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};