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
    int countPrefixSuffixPairs(vector<string>& words) {
    	int n = words.size();
    	int ans = 0;
  		for(int i=0;i<n;i++) {
  			for(int j=i+1;j<n;j++){
  				if(isPrefixSuffix(words[i], words[j])) {
  					ans++;
  				}
  			}
  		}

  		return ans;
    }

    bool isPrefixSuffix(string p, string s) {
    	if(p.size() > s.size()) {
    		return false;
    	}
    	string pref = s.substr(0, p.size());
    	string suff = s.substr(s.size() - p.size(), p.size());

    	if(p == pref && p == suff) {
    		return true;
    	}

    	return false;
    }
};

void solve(){

}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};