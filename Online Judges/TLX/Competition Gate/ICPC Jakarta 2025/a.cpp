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
	int n;
	while(scanf("%d",&n) != EOF) {
		vi v(n+1);
		int gcd = 0;
		for(int i=0;i<n;i++){
			scanf("%d",&v[i]);
			gcd = __gcd(gcd, v[i]);
		}

		vii ans;
		if(gcd > 1) {
			ans.pb(ii(gcd, 1));
		}else{
			ans.pb(ii(4, 2));
			ans.pb(ii(2, 1));
		}

		printf("%d\n",(int)ans.size());
		for(ii el: ans){
			printf("%d %d\n", el.first, el.second);
		}
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