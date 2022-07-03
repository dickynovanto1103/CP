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
    int calPoints(vector<string>& ops) {
    	vector<int> nums;
        for(string op: ops) {
        	if(op == "C"){
        		nums.pop_back();
        	}else if(op == "D") {
        		nums.pb(nums.back() * 2);
        	}else if(op == "+") {
        		int sz = nums.size();
        		nums.pb(nums[sz-1] + nums[sz-2]);
        	}else{
        		nums.pb(atoi(op.c_str()));
        	}
        }

        return accumulate(nums.begin(), nums.end(), 0);
    }
};

int main(){
	int n;
	while(cin>>n){
		vector<string> ops(n);
		for(int i=0;i<n;i++){
			cin>>ops[i];
		}

		Solution sol;
		cout<<sol.calPoints(ops)<<endl;
	}
	
	return 0;
};