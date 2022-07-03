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
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
  		int n = popped.size();
  		int idxPushed = 0;
  		stack<int> s;
  		for(int i=0;i<n;i++){
  			if(s.empty()) {
  				if(idxPushed == n) {
  					return false;
  				}
  				s.push(pushed[idxPushed++]);
  			}
  			while(popped[i] != s.top()) {
  				if(idxPushed == n) {
  					return false;
  				}
  				s.push(pushed[idxPushed++]);
  			}
  			s.pop();
  		}


  		return s.empty();
    }
};

int main(){
	Solution sol;
	vector<int> pushed = {1, 2, 3, 4, 5};
	vector<int> popped = {4, 3, 5, 1, 2};
	cout<<sol.validateStackSequences(pushed, popped)<<endl;
	
	return 0;
};