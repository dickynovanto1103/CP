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

int maxSubArray(vector<int>& nums) {
	int sum = 0;
	int maks = nums[0];
	int len = nums.size();
 	for(int i=0;i<len;i++) {
 		maks = max(maks, nums[i]);
 		sum += nums[i];
 		maks = max(maks, sum);
 		if(sum < 0) sum = 0;
 	}

 	return maks;
}

int main(){
	vi a = {-1};
	int ans = maxSubArray(a);
	printf("%d\n", ans);
	
	return 0;
};