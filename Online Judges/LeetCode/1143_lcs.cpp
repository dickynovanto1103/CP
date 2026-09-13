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
	int dp[1001][1001];
	string text1, text2;
	int n,m;
    int longestCommonSubsequence(string text1, string text2) {
        n = text1.size(), m = text2.size();
        this->text1 = text1;
        this->text2 = text2;
        memset(dp, -1, sizeof dp);


        return solve(0, 0);
    }

    int solve(int idx1, int idx2) {
    	if(idx1 == n || idx2 == m) {return 0;}
    	if(dp[idx1][idx2] != -1) {
    		return dp[idx1][idx2];
    	}

    	if(text1[idx1] == text2[idx2]) {
    		return dp[idx1][idx2] = 1 + solve(idx1 + 1, idx2 + 1);
    	}

    	return dp[idx1][idx2] = max(solve(idx1 + 1, idx2), solve(idx1, idx2 + 1));
    }
};

void solve(){
	puts("halo1");
	Solution sol;
	Solution sol1;
	Solution sol2;
	Solution sol3;
	puts("halo");
	printf("%d\n", sol.longestCommonSubsequence("abcde", "ace"));
	printf("%d\n", sol1.longestCommonSubsequence("abc", "abc"));
	printf("%d\n", sol2.longestCommonSubsequence("abc", "def"));
	printf("%d\n", sol3.longestCommonSubsequence("", "def"));
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};