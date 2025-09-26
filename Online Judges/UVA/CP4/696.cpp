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
	///when any of row / column is 1...then the answer is row / column that is > 1 or 1 if row = column = 1
	// if row = column = 2..answer is 4
	// if any of row / column = 2...and if the other dimension is 2/3, answer is 4...else...general rules applies

	// x.x.
	// .x.x -> this one should be 4 only...so if the column / row count is 4, while the other dimension is 2...then no special rule

	// x.x.x
	// .x.x.

	// .x.
	// x.x
	// .x.

	// x.x.
	// .x.x
	// x.x.

	//if odd and odd, then shoudl do ceil(r * c / 2)
	//if one of them is even, then just r * c / 2

	// x.x.x
	// .x.x.
	// x.x.x
	// .x.x.
	// x.x.x

	// x.x.
	// .x.x
	// x.x.
	

	// x.x.
	// .x.x
	// x.x.
	// .x.x
	// x.x.
	// .x.x
	// x.x.

	int r,c;
	while(scanf("%d %d",&r,&c), (r||c)) {
		if(r == 0 || c == 0) {
			printf("0 knights");
		} else if(r == 1 || c == 1) {
			int maks = max(r, c);
			printf("%d",maks);
			if(maks <= 1) {
				printf(" knight");
			}else{
				printf(" knights");
			}
		}else if(r == 2 || c == 2) {
			int maks = max(r, c);
			if(maks <= 3) {
				printf("4 knights");
			}else{
				printf("%d knights",r*c/2);
			}
		}else{
			printf("%d knights",(((r * c) + 1) / 2));
		}


		printf(" may be placed on a %d row %d column board.\n", r,c);
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