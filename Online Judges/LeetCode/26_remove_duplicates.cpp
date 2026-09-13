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
    int removeDuplicates(vector<int>& nums) {
  		int idxWrite = 0;
  		int cur = -inf;
  		for(int i=0;i<nums.size();i++){
  			if(cur != nums[i]) {
  				nums[idxWrite++] = nums[i];
  				cur = nums[i];
  			}
  		}

  		return idxWrite;
    }
};

void solve(){
	int n;
	while(scanf("%d",&n) != EOF) {
		vi v(n);
		for(int i=0;i<n;i++){
			scanf("%d",&v[i]);
		}

		Solution sol;
		int num = sol.removeDuplicates(v);
		printf("%d\n", num);
		for(int i=0;i<num;i++){
			printf("%d ", v[i]);
		}
		puts(""); puts("");
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