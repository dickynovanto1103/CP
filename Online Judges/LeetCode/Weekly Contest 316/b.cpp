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
    int subarrayGCD(vector<int>& nums, int k) {
    	int sz = nums.size();
    	int cnt = 0;
  		for(int i=0;i<sz;i++) {
  			int gcd = 0;
  			for(int j=i;j<sz;j++) {
  				gcd = __gcd(gcd, nums[j]);
  				if(gcd == k) {
  					cnt++;
  				}
  			}
  		}

  		return cnt;
    }
};

int main(){
	
	
	return 0;
};