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
	scanf("%d",&n);
	int a[n+1];
	int maks = 0;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		maks = max(maks, a[i]);
	}

	int kiri = 0, kanan = maks, mid, ans;

	while(kiri <= kanan) {
		mid = (kiri + kanan) / 2;
		vii groups;
		int startGroup = 0, endGroup = 0;
		bool valid = true;
		for(int i=0;i<n-1;i++){
			if(abs(a[i] - a[i+1]) <= mid) {
				endGroup=i+1;
			}else{
				//berarti groupnya sudah berakhir
				//check for the group...berapa minimum
				int minimHeight = inf + 1;
				for(int j=startGroup;j<=endGroup;j++){
					minimHeight = min(minimHeight, a[j]);
				}

				if(minimHeight > mid) {
					//berarti ga bs
					valid = false;
					break;
				}else{
					//berarti bisa
					startGroup = endGroup = i+1;
				}
			}
		}

		if(!valid) {
			kiri = mid + 1;
			continue;
		}

		//have checked for all
		//berarti groupnya sudah berakhir
		//check for the group...berapa minimum
		int minimHeight = inf + 1;
		for(int j=startGroup;j<=endGroup;j++){
			minimHeight = min(minimHeight, a[j]);
		}

		if(minimHeight > mid) {
			//berarti ga bs
			kiri = mid + 1;
		}else{
			//berarti bisa
			ans = mid;
			kanan = mid-1;
		}
	}

	printf("%d\n", ans);
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	int tt =1;
	while(tc--){
		printf("Case #%d: ", tt++);
		solve();
	}

	return 0;
};