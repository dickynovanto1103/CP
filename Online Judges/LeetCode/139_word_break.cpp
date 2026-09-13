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
    bool wordBreak(string s, vector<string>& wordDict) {
    	unordered_map<string, bool> mapper;
		for(string s: wordDict) {
			mapper[s] = true;
		}

		int n = s.size();

		int dp[301] = {false};
		dp[0] = true;
		
		for(int i=0;i<n;i++){
			for(int j=0;j<=i;j++){
				int remaining = i - j + 1;
				if(dp[j] && mapper[s.substr(j, remaining)]) {
					dp[i+1] = true;
				}
			}
		}

		return dp[n];
    }
};

void solve(){
	int n;
	string s;
	while(cin>>n>>s) {
		vector<string> wordDict;
		for(int i=0;i<n;i++){
			string temp;
			cin>>temp;
			wordDict.pb(temp);
		}

		Solution sol;
		printf("%d\n", sol.wordBreak(s, wordDict));
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