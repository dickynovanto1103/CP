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

class Solution {
public:
    long long flowerGame(int n, int m) {
        return (n/2 * ((m + 1) / 2)) + (((n + 1) / 2) * (m / 2));
    }
};

int main(){
	// int tc = 1;
	// scanf("%d",&tc);
	// while(tc--){
	// 	solve();
	// }

	Solution s;
	int n, m;
	while(scanf("%d %d",&n, &m)!=EOF) {

		ll ans = s.flowerGame(n, m);
		printf("%lld\n", ans);
	}

	return 0;
};