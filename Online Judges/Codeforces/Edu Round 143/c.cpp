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

int tea[200001], tester[200001];
ll pref[200001];
ll ans[200001], partialAns[200001];

int main(){
	int tc;
	scanf("%d",&tc);

	while(tc--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<=n;i++){
			ans[i] = partialAns[i] = 0;
		}
		for(int i=0;i<n;i++){
			scanf("%d",&tea[i]);
		}

		for(int i=0;i<n;i++){
			scanf("%d",&tester[i]);
			pref[i] = tester[i];
			if(i) pref[i] += pref[i-1];
		}

		for(int i=0;i<n;i++){
			//focus ke tiap tea
			if(tea[i] <= tester[i]) {
				partialAns[i] += tea[i];
				continue;
			}

			//binary search
			int kiri = i, kanan = n-1, mid, jawab;
			ll ansConsumed;
			while(kiri <= kanan) {
				mid = (kiri + kanan) / 2;
				ll consumed = pref[mid] - (i == 0 ? 0 : pref[i-1]);
				if(tea[i] < consumed) {
					kanan = mid-1;
				}else{
					kiri = mid + 1;
					jawab = mid;
					ansConsumed = consumed;
				}
			}

			int sisa = tea[i] - ansConsumed;
			ans[i] += 1;
			ans[jawab + 1] -= 1;
			partialAns[jawab+1] += sisa;
		}

		for(int i=1;i<=n;i++){
			ans[i] += ans[i-1];
		}

		for(int i=0;i<n;i++){
			ans[i] = ans[i] * (ll)tester[i] + partialAns[i];
			printf("%lld ", ans[i]);
		}
		puts("");
	}
	
	return 0;
};