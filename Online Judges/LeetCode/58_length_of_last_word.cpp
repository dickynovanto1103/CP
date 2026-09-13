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
    int lengthOfLastWord(string s) {
    	bool isSpace = true;
    	int ans = 0;
    	for(int i=(int)s.size()-1;i>=0;i--){
    		// printf("s[%d]: %c\n", i, s[i]);
    		if(!isSpace) {
    			if(s[i] == ' ') {
    				break;	
    			}else{
    				ans++;
    				continue;
    			}
    			
    		}

    		if(s[i] != ' '){
    			isSpace = false;
    			ans++;
    		}
    	}
    	return ans;    
    }
};

void solve(){
	Solution sol;
	string s;
	while(getline(cin, s)) {
		// cout<<"string: "<<s<<endl;
		printf("%d\n", sol.lengthOfLastWord(s));
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