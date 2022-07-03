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
    void reverseString(vector<char>& s) {
    	int n = s.size();
  		for(int i=0;i<n/2;i++) {
  			swap(s[i], s[n-i-1]);
  		}
    }
};

int main(){
	string st;
	while(cin>>st) {
		vector<char> s;
		for(char c: st) {
			s.pb(c);
		}

		Solution sol;
		sol.reverseString(s);
		for(char c : s) {
			printf("%c", c);
		}
		puts("");
	}
	
	return 0;
};