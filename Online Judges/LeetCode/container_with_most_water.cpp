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
    int maxArea(vector<int>& height) {
    	int l = 0, r = height.size() - 1;
    	int ans = 0;
    	while(l < r) {
    		ans = max(ans, min(height[l], height[r]) * (r - l));
    		if(height[l] < height[r]) {
    			//we eliminate the possibilities of (l, r-1), (l, r-2) because these possibilities will yield same / less values
    			l++;
    		}else{
    			r--;
    		}
    	}

        return ans;
    }
};

int main(){
	int n;
	while(cin>>n) {
		vi a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}

		Solution sol;
		cout<<sol.maxArea(a)<<endl;
	}
	
	return 0;
};