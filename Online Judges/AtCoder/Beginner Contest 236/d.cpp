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


int n;
int a[17][17];

vii listPas;
int cnt;
int maks;

void solve(int n, int bit) {
	// printf("n: %d bit: %d\n", n, bit);
	if(bit == ((1<<(2*n)) - 1)) {
		int ans = 0;
		for(ii pas: listPas) {
			assert(pas.first < pas.second);
			ans ^= a[pas.first][pas.second];
		}
		maks = max(maks, ans);
		cnt++;
		// puts("");
		return;
	}
	int pertama = -1;
	for(int i=0;i<2*n;i++) {
		int nilai = (1<<i) & bit;
		if(!nilai) {
			pertama = i;
			break;
		}
	}

	if(pertama == -1) assert(false);

	bit |= (1<<pertama);
	for(int i=pertama + 1;i<2*n;i++){
		int nilai = (1<<i) & bit;
		if(!nilai) {
			listPas.pb(ii(pertama, i));

			solve(n, bit | (1<<i));
			listPas.pop_back();
		}
	}
}

int main(){
	int i,j;
	scanf("%d",&n);
	for(int i=0;i<2*n-1;i++){
		for(j=i+1;j<2*n;j++){
			scanf("%d",&a[i][j]);
		}
	}

	// printf("n: %d\n", n);

	solve(n, 0);
	// printf("cnt: %d\n", cnt);
	printf("%d\n", maks);
	
	return 0;
};