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

int ask(int l, int r, int d, int u) {
	printf("? %d %d %d %d\n", l, r, d, u);
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}

int main(){
	int n;
	scanf("%d",&n);
	//urus kiri kanan dulu
	int kiri = 1, kanan = n, x, mid;
	while(kiri < kanan) {
		mid = (kiri + kanan) / 2;
		int jawab1 = ask(kiri, mid, 1, n);
		int jawab2 = ask(mid+1, kanan, 1, n);
		if(jawab1 > jawab2) {
			//berarti bukan area missing node bukan di area kiri - mid, tp di area mid + 1 sampe kanan
			x = mid+1;
			kiri = mid + 1;
		}else{
			//areanya berarti di kiri - mid
			x = mid;
			kanan = mid;
		}
	}

	int bawah = 1, atas = n, y;
	while(bawah < atas) {
		mid = (bawah + atas) / 2;
		int jawab1 = ask(1, n, bawah, mid);
		int jawab2 = ask(1, n, mid+1, atas);
		// printf("jawab1: %d jawab2: %d\n", jawab1, jawab2);
		if(jawab1 > jawab2) {
			y = mid+1;
			bawah = mid+1;
		}else{
			y = mid;
			atas = mid;
		}
	}
	
	printf("! %d %d\n", x, y);
	fflush(stdout);
	return 0;
};