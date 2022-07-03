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
    int findUnsortedSubarray(vector<int>& nums) {
        vi sorted = nums;
        sort(sorted.begin(), sorted.end());

        int samaDepan = 0, samaBelakang = 0;

        int n = nums.size();
        for(int i=0;i<n;i++){
        	if(sorted[i] == nums[i]) {
        		samaDepan++;
        	}else{
        		break;
        	}
        }

        for(int i=n-1;i>=0;i--){
        	if(sorted[i] == nums[i]) {
        		samaBelakang++;
        	}else{
        		break;
        	}
        }

        int sumSama = samaDepan + samaBelakang;
        return max(0, n - sumSama);
    }
};

int main(){
	int n;
	while(cin>>n){
		vi v(n);
		for(int i=0;i<n;i++){
			scanf("%d",&v[i]);
		}

		Solution sol;
		cout<<sol.findUnsortedSubarray(v)<<endl;
	}	
	
	return 0;
};