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
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 5e5 + 5;
int x[maxn], y[maxn];
int n;

int findBuildingBruteForce() {
	int i,j;
	int building = -1;
	ll maks = (ll)inf*(ll)inf;
	for(i=0;i<n;i++){
		ll sum = 0;
		for(j=0;j<n;j++){
			int selisihX = abs(x[i] - x[j]);
			int selisihY = abs(y[i] - y[j]);
			int maks = max(selisihY, selisihX);
			sum += maks;
		}
		if(maks > sum){
			maks = sum;
			building = i+1;
		}
	}
	return building;
}

int findAllSameXY() {
	int i,j;
	vii koorBuilding;
	for(i=0;i<n;i++){
		koorBuilding.pb(ii(x[i], i+1));
	}
	sort(koorBuilding.begin(), koorBuilding.end());
	int ans = -1;
	ll jarakKiri = 0, jarakKanan = 0;
	for(i=0;i<n;i++){
		int koor = koorBuilding[i].first, building = koorBuilding[i].second;
		jarakKanan += (koorBuilding[i].first - koorBuilding[0].first);
	}
	ll initialJarakKanan = jarakKanan;
	ll minJarak = jarakKanan;
	ans = koorBuilding[0].second;
	// printf("jarakKiri: %lld jarakKanan: %lld\n", jarakKiri, jarakKanan);
	for(i=1;i<n;i++){
		//tambah kiri
		jarakKiri += ((ll)i * (ll)(koorBuilding[i].first - koorBuilding[i-1].first));
		//kurang kanan
		int kurangBuildingKanan = n-i;
		jarakKanan -= ((ll)kurangBuildingKanan * (ll)(koorBuilding[i].first - koorBuilding[i-1].first));
		ll jarak = jarakKiri + jarakKanan;
		if(minJarak > jarak){
			minJarak = jarak;
			ans = koorBuilding[i].second;
		}else if(minJarak == jarak){
			if(ans > koorBuilding[i].second){
				ans = koorBuilding[i].second;
			}
		}
		// printf("i: %d jarakKiri: %lld jarakKanan: %lld total: %lld\n", i, jarakKiri, jarakKanan, jarak);
	}
	assert(jarakKanan == 0);
	// assert(jarakKiri == initialJarakKanan);
	return ans;
}

int main(){
	int i,j;
	while(scanf("%d",&n) !=EOF){
		for(i=0;i<n;i++){
			scanf("%d %d",&x[i],&y[i]);
		}	
		if(n <= 1000) {
			//n^2 approach
			int building = findBuildingBruteForce();
			assert(building != -1);
			printf("%d\n",building);

			// int building = findAllSameXY();
			// assert(building != -1);
			// printf("%d\n",building);
		}else{
			int building = findAllSameXY();
			assert(building != -1);
			printf("%d\n",building);
		}


	}

	
	
	return 0;
};