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
	int token[5];
    int minimumPushes(string s) {
        int cnt[26] = {0};
        for(int i=0;i<s.size();i++){
        	cnt[s[i] - 'a']++;
        }
        sort(cnt, cnt+26);
        
        token[1] = 8;
        token[2] = 8;
        token[3] = 8;
        token[4] = 2;
        int ans = 0;
        for(int i=25;i>=0;i--){
        	int cost = pickTokenCost();
        	ans += cnt[i] * cost;
        }

        return ans;
    }

    int pickTokenCost() {
    	for(int i=1;i<=4;i++){
    		if(token[i]) {
    			token[i]--;
    			return i;
    		}
    	}
    	assert(false);
    	return -1;
    }
};

void solve(){
	
}

int main(){
	Solution sol;
	string s;
	while(cin>>s){
		printf("%d\n", sol.minimumPushes(s));
	}

	return 0;
};