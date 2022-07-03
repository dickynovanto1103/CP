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
	bool can(vi& nums, int m, int batas) {
		int sum = 0;
		int cnt = 1;
		// printf("m: %d batas: %d\n", m, batas);
		for(int i=0;i<nums.size();i++) {
			if(nums[i] > batas){
				return false;
			}
			sum += nums[i];
			if(sum > batas) {
				cnt++;
				sum = nums[i];
			}
			// printf("i: %d sum: %d cnt: %d\n", i, sum, cnt);

			if(cnt > m) {
				return false;
			}
		}

		return true;
	}

    int splitArray(vector<int>& nums, int m) {
        int l = 0, r = inf, mid, ans = -1;
        // printf("awal awal, m: %d\n", m);
        while(l <= r) {
        	mid = (l + r) / 2;
        	// printf("mid: %d\n", mid);
        	if(can(nums, m, mid)) {
        		ans = mid;
        		r = mid-1;
        	}else{
        		l = mid+1;
        	}
        }

        assert(ans != -1);

        return ans;
    }
};

int main(){
	int n, m;
	while(scanf("%d %d",&n, &m) != EOF) {
		vi a(n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		
		Solution sol;
		cout<<sol.splitArray(a, m)<<endl;

	}
	
	return 0;
};