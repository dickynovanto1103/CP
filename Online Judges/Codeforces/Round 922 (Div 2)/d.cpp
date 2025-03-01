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
typedef pair<ll,int> ii;
typedef vector<ii> vii;

const int maxn = 100010;

int a[maxn];
ll pref[maxn];
ll dp[maxn];

ll getSum(int kiri, int kanan) {
	if(kiri > kanan) {
		return 0;
	}
	return pref[kanan] - (kiri == 0 ? 0: pref[kiri - 1]);
}

void solve(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		pref[i] = a[i];
		pref[i] += pref[i-1];
		dp[i] = 0;
	}

	dp[0] = 0;
	//binser the answer 
	ll kiri = 0, kanan = (ll)inf * n, mid, ans;
	while(kiri <= kanan) {
		mid = (kiri + kanan) / 2;
		set<ii> dpSet;
		dpSet.insert({dp[0], 0});
		int idxKiri = 0;
		for(int i=1;i<=n;i++){
			while(getSum(idxKiri + 1, i-1) > mid) {
				dpSet.erase({dp[idxKiri], idxKiri});
				idxKiri++;
			}

			assert(dpSet.size() > 0);
			dp[i] = dpSet.begin()->first + a[i];
			dpSet.insert({dp[i], i});
		}

		bool found = false;
		for(int i=n;i>=1;i--){
			if(dp[i] <= mid && getSum(i+1, n) <= mid) {
				found = true;
				break;
			}
		}

		if(found) {
			// printf("found with mid: %d\n", mid);
			ans = mid;
			kanan = mid - 1;
		}else{
			// printf("not found with mid: %d\n", mid);
			kiri = mid + 1;
		}
	}

	printf("%lld\n", ans);
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};