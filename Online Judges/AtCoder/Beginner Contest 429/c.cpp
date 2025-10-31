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

void solve(){
	int n;
	int a[200010];
	int cnt[200010] = {0};
	ll comb[200010] = {0};
	scanf("%d",&n);
	set<int> s;
	set<int>::iterator it;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
		s.insert(a[i]);
	}

	vi list;
	for(it=s.begin(); it!=s.end();it++){
		list.pb(*it);
	}

	ll sumAllComb = 0;
	for(int num: list) {
		comb[num] = (ll)(cnt[num]) * (ll)(cnt[num] - 1) / 2LL;
		sumAllComb += comb[num];
	}

	ll ans = 0;

	for(int num: list) {
		ans += ((ll)cnt[num] * (sumAllComb - comb[num]));
	}

	printf("%lld\n", ans);
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};