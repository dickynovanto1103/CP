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

vii findRanges(int a[], int n, int k, int x, int dist) {
	int sum = 0;
	vii ans;
	if(dist == 0) {
		for(int i=0;i<k;i++){
			ans.pb(ii(i, i));
		}

		assert(ans.size() == k);

		return ans;
	}

	if((a[0] - dist + 1) > 0) {
		ans.pb(ii(0, a[0] - dist));
	}

	for(int i=0;i<n-1;i++){
		int left = a[i] + dist;
		int right = a[i+1] - dist;
		if(right - left + 1 > 0) {
			ans.pb(ii(left, right));
		}
	}

	if((x - (a[n-1] + dist) + 1) > 0) {
		ans.pb(ii(a[n-1] + dist, x));
	}

	return ans;
}

bool canFormK(int a[], int n, int k, int x, int dist) {
	int sum = 0;
	sum += max(0, a[0] - dist + 1);
	sum += max(0, x - (a[n-1] + dist) + 1);
	for(int i=0;i<n-1;i++){
		int left = a[i] + dist;
		int right = a[i+1] - dist;
		sum += max(0, right - left + 1);
	}

	return sum >= k;
}

void solve(){
	int n,k,x;
	scanf("%d%d%d",&n,&k,&x);
	int a[n+1];
	for(int i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}

	sort(a, a+n);
	int kiri = 0, kanan = x, mid, ans = -1;
	while(kiri <= kanan) {
		mid = (kiri + kanan) / 2;
		if(canFormK(a, n, k, x, mid)) {
			ans = mid;
			kiri = mid + 1;
		}else{
			kanan = mid - 1;
		}
	}

	assert(ans != -1);
	// printf("ans: %d\n", ans);
	vii ranges = findRanges(a, n, k, x, ans);

	vi indexes;
	for(ii range: ranges) {
		// printf("range: %d %d\n", range.first, range.second);
		for(int i=range.first;i<=range.second && indexes.size() < k;i++){
			indexes.pb(i);
		}

		if(indexes.size() == k){
			break;
		}
	}

	for(int el: indexes) {
		printf("%d ", el);
	}
	puts("");
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};