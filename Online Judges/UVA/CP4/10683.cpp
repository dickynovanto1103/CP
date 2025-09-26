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
	int num;
	while(scanf("%d",&num) != EOF) {
		// printf("%d\n",num);
		int small = num % 100;
		num /= 100;
		int second = num % 100;
		num /= 100;
		int minute = num % 100;
		num /= 100;
		int hour = num % 100;
		num /= 100;

		int totSmallSeconds = small + second * 100 + minute * 60 * 100 + hour * 60 * 60 * 100;
		ll converted = 100000ll * totSmallSeconds / 86400LL;
		printf("%.7lld\n", converted);
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