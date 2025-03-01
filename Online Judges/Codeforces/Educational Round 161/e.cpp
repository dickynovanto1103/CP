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
	ll x;
	scanf("%lld",&x);
	vi ans;
	int maks = 1000, min = 0;
	while(x > 1) {
		if(x % 2 == 0) {
			//I can put maximum number at the end of our answer
			ans.pb(maks--);
			x /= 2;
		}else{
			ans.pb(min++);
			x--;
		}
	}

	reverse(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for(int a: ans) {
		printf("%d ", a);
	}
	puts("");
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};