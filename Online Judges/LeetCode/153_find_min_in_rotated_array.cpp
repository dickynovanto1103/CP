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
    int findMin(vector<int>& nums) {
  		int n = nums.size();

  		bool isRotated = nums[0] > nums[n-1];
  		if(!isRotated) {return nums[0];}

  		int kiri = 1, kanan = n-1, mid, ans;
  		while(kiri <= kanan) {
  			mid = (kiri + kanan) / 2;
  			if(nums[mid] > nums[0]) {
  				kiri = mid + 1;
  			}else{
  				ans = nums[mid];
  				kanan = mid - 1;
  			}
  		}

  		return ans;
    }
};

void solve(){
	Solution sol;
	vector<int> v = {3,4,5,1,2};
	printf("%d\n", sol.findMin(v));
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};