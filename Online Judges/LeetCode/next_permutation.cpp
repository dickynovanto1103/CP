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
    void nextPermutation(vector<int>& nums) {
    	// printf("arr awal: ");
    	// for(int num: nums) {
    	// 	printf("%d ", num);
    	// }
    	// puts("");
    	int n = nums.size();
  		for(int i=n-2;i>=0;i--){
  			if(nums[i] < nums[i+1]) {
  				int minimNum = nums[i+1];
  				int idx = i+1;
  				for(int j=i+2;j<n;j++){
  					if(minimNum > nums[j] && nums[j] > nums[i]) {
  						minimNum = nums[j];
  						idx = j;
  					}
  				}

  				// printf("swap a[%d]: %d and a[%d]: %d\n", i, nums[i], idx, nums[idx]);
  				swap(nums[i], nums[idx]);

  				
  				sort(nums.begin()+i+1, nums.end());
  				return;
  			}
  		}
  		sort(nums.begin(), nums.end());
    }
};

int main(){
	int n,i,j;
	while(scanf("%d",&n) != EOF) {
		vi a(n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}

		Solution sol;
		sol.nextPermutation(a);
		for(int num: a) {
			printf("%d ", num);
		}
		puts("");
	}
	
	return 0;
};