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
    int maximumTop(vector<int>& nums, int k) {
     	int ans = 0;

     	int n = nums.size();
     	if(k % 2 == 1 && n == 1){return -1;}
     	if(n > k) {
     		for(int i=0;i<k-1;i++){
	     		ans = max(ans, nums[i]);
	     	}
	     	ans = max(ans, nums[k]);
     	}else if(n == k){
     		for(int i=0;i<(n-1);i++){
	     		ans = max(ans, nums[i]);
	     	}
     	}else{
     		for(int i=0;i<n;i++){
	     		ans = max(ans, nums[i]);
	     	}
     	}
     	

     	return ans;   
    }
};

int main(){
	
	
	return 0;
};