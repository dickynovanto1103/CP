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
	bool isClosing(char c) {
		return c == ')' || c == '}' || c == ']';
	}
	char getPair(char c) {
		if(c == ')') {return '(';}
		else if(c == '}') {return '{';}
		else if(c == ']') {return '[';}
		assert(false);
		return '1';
	}
    bool isValid(string s) {
  		stack<char> st;
  		for(int i=0;i<s.size();i++){
  			char c = s[i];

  			if(isClosing(c)) {
  				if(st.empty()) {
  					return false;
  				}

  				if(st.top() != getPair(c)) {return false;}
  				st.pop();
  				continue;
  			}
  			st.push(c);
  		}
  		return st.empty();
    }
};

int main(){
	string s;
	while(cin>>s) {
		Solution sol;
		bool ans = sol.isValid(s);
		cout<<ans<<endl;
	}
	
	return 0;
};