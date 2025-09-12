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

int v[1000001];

int digits[1000001][2], res[1000001], tempOutput[1000001];

const int base = (1<<15);
const int baseLog2 = 15;
int cnt[base + 1];

void putIntoDigits(int idx, int v) {
	int idxPlace = 1;
	while(v) {
		int digit = v%base;
		digits[idx][idxPlace--] = digit;
		v /= base;
	}
}

void stableSortDigits(int n) {
	//process dari idx ke 10 sampe ke 0
	for(int idx=1;idx>=0;idx--){
		memset(cnt, 0, sizeof cnt);
		// std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
		// do counting sort
		
		for(int i=0;i<n;i++){
			digits[i][idx] = (v[i]>>((1 - idx) * baseLog2)) & (base - 1);
			cnt[digits[i][idx]]++;
		}

		for(int i=1;i<base;i++){
			cnt[i] += cnt[i-1];
		}

		for(int i=n-1;i>=0;i--){
			int placedIdx = --cnt[digits[i][idx]];
			tempOutput[placedIdx] = v[i];
			// memcpy(tempOutput[placedIdx], digits[i],2 * sizeof(int));
			// for(int j=0;j<2;j++){
			// 	tempOutput[placedIdx][j] = digits[i][j];
			// }
		}


		memcpy(v, tempOutput, n * sizeof(int));
		// for(int i=0;i<n;i++){
		// 	v[i] = tempOutput[i];
		// }
		// memcpy(digits, tempOutput, n * 2 * sizeof(int));
		// for(int i=0;i<n;i++){
		// 	for(int j=0;j<2;j++) {
		// 		digits[i][j] = tempOutput[i][j];	
		// 	}
		// }

		// std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
		// std::cout << "idx: " << idx << ", Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

	}
}

void convertBackToVector(int n) {
	for(int i=0;i<n;i++){
		int ans = 0;
		int multiplier = 1;
		for(int j=1; j>=0;j--){
			ans += multiplier * digits[i][j];
			multiplier *= base;
		}
		res[i] = ans;
	}
	
	// return res;
}

void printDigits(int n) {
	for(int i=0;i<n;i++){
		for(int j=0;j<=1;j++){
			printf("%d ", digits[i][j]);
		}
		puts("");
	}
}

void solve(){
	int n;
	int a, b, c;
	int x, y;
	scanf("%d",&n);
	scanf("%d %d %d",&a,&b,&c);
	scanf("%d %d",&x,&y);
	// std::chrono::steady_clock::time_point begin1 = std::chrono::steady_clock::now();
	v[0] = a;
	// printf("v[0]: %d\n", v[0]);
	putIntoDigits(0, v[0]);
	for(int i=1;i<n;i++){
		v[i] = (((ll)v[i-1] * (ll)b) % c + (ll)a) % c;
		// printf("v[%d]: %lld\n", i, v[i]);
		putIntoDigits(i, v[i]);
	}
	// std::chrono::steady_clock::time_point end1 = std::chrono::steady_clock::now();
	// std::cout << "Time put into digits difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end1 - begin1).count() << "[ms]" << std::endl;
	// printf("printing digits\n");
	// printDigits(n);
	// vector<ll> awal = convertBackToVector(n);
	// printf("printing awal\n");
	// for(ll el: awal) {
	// 	printf("%lld ", el);
	// }
	// puts("");

	// printf("before stable sort\n");
	// std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	stableSortDigits(n);
	// std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	// std::cout << "Time stable sort difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
	// printf("after stable sort\n");
	// printf("printing digits again\n");
	// printDigits(n);

	// std::chrono::steady_clock::time_point begin2 = std::chrono::steady_clock::now();
	// convertBackToVector(n);
	// std::chrono::steady_clock::time_point end2 = std::chrono::steady_clock::now();
	// std::cout << "Time generate res difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end2 - begin2).count() << "[ms]" << std::endl;
	// printf("res after sorted\n");
	// for(ll el: res) {
	// 	printf("%lld ", el);
	// }
	// puts("");

	ll hash = 0;
	for(int i=0;i<n;i++){
		hash = (((hash) * ((ll)x)) % y + (v[i])) % y;
	}
	printf("%lld\n", hash);
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	while(tc--){
		// std::chrono::steady_clock::time_point begin3 = std::chrono::steady_clock::now();
		memset(digits, 0, sizeof digits);
		solve();
		// std::chrono::steady_clock::time_point end3 = std::chrono::steady_clock::now();
		// std::cout << "Time 1 tc difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end3 - begin3).count() << "[ms]" << std::endl;
	}

	return 0;
};