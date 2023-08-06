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
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int a[1000002];

ll bit[1000002];
ll cntBit[4][1000002];

class BIT {
public:
	BIT(int n) {
		this->n = n;
		
		for(int i=0;i<4;i++){
			for(int j=0;j<=n;j++){
				cntBit[i][j] = 0;
			}
		}

		for(int i=0;i<=n;i++){
			bit[i] = 0;
		}
	}

	void decreaseNumAwal(int idx, int valAwal) {
		for(int i=idx;i<=n;i+=(i & -i)) {
			cntBit[valAwal][i] -= 1;
			bit[i] -= valAwal;
		}
	}

	void update(int idx, int val) {
		for(int i=idx;i<=n;i+=(i & (-i))) {
			bit[i] += val;
			cntBit[val][i] += 1;
		}
	}

	ll query(int idx) {
		ll sum = 0;
		for(int i=idx;i>=1;i -= (i & (-i))) {
			sum += bit[i];
		}

		return sum;
	}

	ll querySum(int l, int r) {
		return query(r) - query(l-1);
	}

	ll queryCnt(int num, int idx) {
		ll ans = 0;
		for(int i=idx;i>=1;i -= (i & -i)) {
			ans += cntBit[num][i];
		}

		return ans;
	}

	int queryCntRange(int num, int l, int r) {
		return queryCnt(num, r) - queryCnt(num, l-1);
	}

	vi getCnts(int l, int r) {
		vi res = vi(4);
		for(int i=1;i<=3;i++){
			res[i] = queryCntRange(i, l, r);
		}

		return res;
	}

private:
	int n;
};

int main(){
	int tc;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		cerr<<"processing case "<<tt<<endl;
		printf("Case #%d: ", tt);

		int n,m;
		scanf("%d %d",&n,&m);
		BIT bit(n);

		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			bit.update(i, a[i]);
		}

		// printf("n: %d m: %d\n", n, m);

		ll ans = 0;
		for(int i=0;i<m;i++){
			int x, y, z;
			scanf("%d %d %d",&x,&y,&z);
			bit.decreaseNumAwal(x, a[x]);
			// printf("decrease num awal a[%d]: %d\n", x, a[x]);
			a[x] = y;
			bit.update(x, y);

			// printf("query %d, x: %d y: %d z: %d\n", i, x, y, z);

			ll sum1 = bit.querySum(1, z);
			ll sum2 = bit.querySum(z+1, n);
			ll selisih = sum1 - sum2;

			// printf("sum1: %lld sum2: %lld selisih: %lld\n", sum1, sum2, selisih);

			if(sum1 == sum2) continue;
			//klo ga sama, harus check apakah impossible
			vi cnts1 = bit.getCnts(1, z);
			vi cnts2 = bit.getCnts(z+1, n);
			// printf("pertama:");
			// for(int bil: cnts1) {
			// 	printf(" %d", bil);
			// }
			// puts("");

			// printf("kedua:");
			// for(int bil: cnts2) {
			// 	printf(" %d", bil);
			// }
			// puts("");

			if(selisih < 0) {
				swap(cnts1, cnts2);
				selisih = -selisih;
			}

			if(selisih % 2 == 1) {
				//ga bs klo selisih ganjil, harus genap
				ans += -1;
				continue;
			}

			//pokoknya move 1 ke 2

			//maksimalin dulu, swap 3 sama 1
			ll selisihBagi4 = selisih / 4;
			ll maksTukar3Dan1 = min(cnts1[3], cnts2[1]);

			ll realTuker3Dan1 = min(maksTukar3Dan1, selisihBagi4);
			selisih -= (4 * realTuker3Dan1);
			assert(selisih >= 0);
			cnts1[3] -= realTuker3Dan1;
			assert(cnts1[3] >= 0);
			cnts2[1] -= realTuker3Dan1;
			assert(cnts2[1] >= 0);

			// printf("setelah 3 dan 1, selisih: %lld, realTuker3Dan1: %lld\n", selisih, realTuker3Dan1);

			//coba tuker 3 dan 2
			ll maxThreeTwo = min(cnts1[3], cnts2[2]);
			ll realThreeTwo = min(selisih/2, maxThreeTwo);
			// printf("realThreeTwo: %lld maxThreeTwo: %lld, selisih/2: %lld, realThreeTwo: %lld\n", realThreeTwo, maxThreeTwo, selisih/2, realThreeTwo);

			selisih -= 2*realThreeTwo;
			assert(selisih >= 0);
			cnts1[3] -= realThreeTwo;
			assert(cnts1[3] >= 0);
			cnts2[2] -= realThreeTwo;
			assert(cnts2[2] >= 0);

			//coba tuker 2 dan 1
			ll maxTwoOne = min(cnts1[2], cnts2[1]);
			ll realTwoOne = min(selisih/2, maxTwoOne);

			selisih -= 2*realTwoOne;
			assert(selisih >= 0);
			cnts1[2] -= realTwoOne;
			assert(cnts1[2] >= 0);
			cnts2[1] -= realTwoOne;
			assert(cnts2[1] >= 0);

			// printf("realTwoOne: %lld\n", realTwoOne);

			if(selisih > 0) {
				//masih ada sisa
				ans += -1;
				// printf("masih ada sisa, ans jd: %lld\n", ans);
			}else{
				ans += realTuker3Dan1;
				ans += realThreeTwo;
				ans += realTwoOne;	
				// printf("ans jd: %lld\n", ans);
			}

		}
		printf("%lld\n", ans);
	}
	
	return 0;
};