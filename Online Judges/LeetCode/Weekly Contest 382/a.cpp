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
    int countKeyChanges(string s) {
    	char last = '.';
    	int cnt = 0;
  		for(int i = 0; i < s.size();i++){
  			if(isUpperCase(s[i])) {
  				s[i] -= 'A';
  				s[i] += 'a';
  			}

  			if(last != s[i]) {
  				cnt++;
  				last = s[i];
  			}
  		}

  		return cnt-1;
    }

    bool isUpperCase(char c) {
    	return c >= 'A' && c <= 'Z';
    }
};

void solve(){
	
}

int main(){
	// int tc = 1;
	// // scanf("%d",&tc);
	// while(tc--){
	// 	solve();
	// }

	Solution sol;
	string s;
	while(cin>>s) {
		int ans = sol.countKeyChanges(s);
		printf("%d\n", ans);	
	}
	

	return 0;
};