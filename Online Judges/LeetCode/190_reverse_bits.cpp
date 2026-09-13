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
    int reverseBits(int n) {
  		int ans = 0;
  		for(int i=31;i>=0;i--){
  			int bit = (1LL<<i) & n;
  			if(bit == 0) {
  				continue;
  			}
  			ans += (1LL<<(31-i));
  			// printf("ans: %d bit: %d, i: %d\n", ans, bit, i);
  		}  

  		return ans;
    }
};

void solve(){
	Solution sol;
	printf("%d\n",sol.reverseBits(43261596));

	printf("%d\n",sol.reverseBits(2147483644));
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};