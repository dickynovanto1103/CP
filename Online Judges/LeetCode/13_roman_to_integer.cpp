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
	unordered_map<char, int> mapper = {
		{'I', 1},
		{'V', 5},
		{'X', 10},
		{'L', 50},
		{'C', 100},
		{'D', 500},
		{'M', 1000}
	};

    int romanToInt(string s) {
  		int ans = 0;
  		for(int i=0;i<s.size();i++){
  			if(i < (int)s.size() - 1 && mapper[s[i]] < mapper[s[i+1]]) {
  				ans += mapper[s[i+1]] - mapper[s[i]];
  				i++;
  				continue;
  			}else{
  				ans += mapper[s[i]];
  			}
  		}

  		return ans;
    }
};

void solve(){
	string s;
	while(cin>>s) {
		Solution sol;
		printf("%d\n",sol.romanToInt(s));
	}
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};