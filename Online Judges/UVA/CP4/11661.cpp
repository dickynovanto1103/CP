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

char s[2000001];

void solve(){
	int len;
	while(scanf("%d",&len) && len) {
		scanf("%s",s);
		bool foundZ = false;
		vi restaurantIdx, drugStoreIdx;
		for(int i=0;i<len;i++){
			if(s[i] == 'Z') {
				foundZ = true;
				break;
			}else if(s[i] == 'R') {
				restaurantIdx.pb(i);
			}else if(s[i] == 'D') {
				drugStoreIdx.pb(i);
			}
		}

		if(foundZ) {
			puts("0");
			continue;
		}

		int idxDrug = 0;
		int prefDrugStoreIdx = -inf, nextDrugStoreIdx = drugStoreIdx[idxDrug];
		int numRestaurants = restaurantIdx.size();
		int minDist = inf;
		for(int i=0;i<numRestaurants;i++){
			while(restaurantIdx[i] > nextDrugStoreIdx && (idxDrug + 1) < drugStoreIdx.size()) {
				prefDrugStoreIdx = nextDrugStoreIdx;
				nextDrugStoreIdx = drugStoreIdx[++idxDrug];
			}

			if(restaurantIdx[i] > nextDrugStoreIdx) { //the case sudah di ujung
				prefDrugStoreIdx = nextDrugStoreIdx;
				nextDrugStoreIdx = inf;
			}

			minDist = min(minDist, min(restaurantIdx[i] - prefDrugStoreIdx, nextDrugStoreIdx - restaurantIdx[i]));
		}

		printf("%d\n", minDist);
		//..D...D...RR..D
	}
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};