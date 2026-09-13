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
	int dp[103];

    int numDecodings(string s) {
  		memset(dp, 0, sizeof dp);
  		dp[0] = 1;
  		for(int i=0;i<s.size();i++){
  			if(isValidStr(s.substr(i, 1))) {
  				dp[i+1] += dp[i];
  				// cout<<"string 1: "<<s.substr(i, 1)<<endl;
  				// printf("plus 1 dp[%d] becomes: %d\n", i+1, dp[i+1]);
  			}

  			if(i < (int)s.size() - 1 && isValidStr(s.substr(i, 2))) {
  				dp[i+2] += dp[i];
  				// printf("plus 2 dp[%d] becomes: %d\n", i+2, dp[i+2]);
  			}
  		}
  		return dp[s.size()];
    }

    bool isValidStr(string s) {
    	if(s.size() == 0) {return false;}
    	if(s[0] == '0') {return false;}

    	int num = convertStrToInt(s);
    	return (num >= 1 && num <= 26);
    }

    int convertStrToInt(string s) {
    	int num = 0;
    	for(int i=0;i<s.size();i++) {
    		num *= 10;
    		num += s[i] - '0';
    	}

    	return num;
    }
};

void solve(){
	Solution sol;
	printf("%d\n", sol.numDecodings("12"));
	printf("%d\n", sol.numDecodings("226"));
	printf("%d\n", sol.numDecodings("06"));
	printf("%d\n", sol.numDecodings("6"));
	printf("%d\n", sol.numDecodings("10"));
	printf("%d\n", sol.numDecodings("100"));
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};