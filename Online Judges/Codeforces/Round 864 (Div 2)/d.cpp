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

void kuranginDengan(int x) {
	printf("- %d\n", x);
	fflush(stdout);
}

void jawab(int n) {
	printf("! %d\n", n);
	fflush(stdout);
}

int formNum(int startIdx, int banyakBit) {
	int ans = 0;
	for(int i=startIdx; i < startIdx + banyakBit; i++) {
		ans += (1<<i);
	}

	return ans;
}

int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int cntBit;
		scanf("%d",&cntBit);

		int idx = 0;
		int bitMuncul = 0;
		int bitKurang = 0;
		int ans = 0;
		int cntBitThen = cntBit;
		while(cntBit > 0) {
			int cobaBit = min(bitMuncul + 1, cntBit);
			int x = formNum(idx, cobaBit);
			kuranginDengan(x);
			ans += x;
			idx = idx + cobaBit - 1;
			scanf("%d",&cntBit);
			if(cntBit == -1) {
				assert(false);
				return 0;
			} //hopefully we won't go into this case

			bitKurang = cobaBit;
			bitMuncul = cntBit - (cntBitThen - bitKurang);
			cntBitThen = cntBit;
			// printf("cntBit: %d, cntBitThen: %d")
			// printf("bitKurang: %d, bit muncul: %d\n", bitKurang, bitMuncul);
		}

		jawab(ans);
	}
	
	return 0;
};