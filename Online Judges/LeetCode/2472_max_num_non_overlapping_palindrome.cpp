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

const int maxn = 2010;

bool isPalindrome[maxn][maxn];

class Solution {
public:
	int dp[maxn];
    int maxPalindromes(string s, int k) {
    	memset(isPalindrome, false, sizeof isPalindrome);
    	memset(dp, 0, sizeof dp);
    	// odd length palindrome
    	for(int i=0;i<s.size();i++){
    		isPalindrome[i][i] = true;
    		// printf("ODD isPalindrome[%d][%d] is true\n", i,i);
    		
    		for(int j=1;j<s.size() && (i - j >= 0) && (i + j < s.size());j++) {
    			// printf("i %d -j %d: %d\n", i,j,i-j);
    			if(s[i-j] == s[i+j]) {
    				isPalindrome[i-j][i+j] = true;
    				// printf("ODD isPalindrome[%d][%d] is true\n", i-j,i+j);
    			}else{
    				break;
    			}
    		}
    	}    

    	// even length palindrome
		for(int i=0;i<(int)s.size() - 1;i++){
			int j = i + 1;
			if(s[i] != s[j]) {
				continue;
			}
			for(int add = 0;add<s.size() && (i - add >= 0 && j + add < s.size()); add++) {
				// printf("i: %d j: %d add: %d, i-add: %d j + add: %d\n", i,j,add, i-add, j+add);
				if(s[i - add] != s[j + add]) {
    				break;
    			}

    			isPalindrome[i-add][j+add] = true;
    			// printf("EVEN isPalindrome[%d][%d] is true\n", i-add,j+add);
			}
		}

    	//find answer
		// dp[i] = number of maximum palindrome ending at i, 0, if no palindrome ending at i
		// later we need to iterate through all i (0 ... n-1) to find the maximum number
		for(int i=0;i<s.size();i++){
			int maxDp = 0;
			for(int j=0;j<=i-k+1;j++){
				// printf("j: %d i: %d, k: %d\n", j,i, k);
				if(isPalindrome[j][i]) {
					dp[i] = max(dp[i], maxDp + 1);

					
					// printf("dp[%d]: %d maxDp: %d\n", i, dp[i], maxDp);
				}
				maxDp = max(maxDp, dp[j]);
			}
		}

		int ans = 0;
		for(int i=0;i<s.size();i++){
			ans = max(ans, dp[i]);
		}

		return ans;
    }
};

void solve(){
	string s;
	int k;
	while(cin>>s>>k) {
		Solution sol;
		printf("%d\n", sol.maxPalindromes(s,k));
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