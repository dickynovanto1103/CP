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
    int cnt1[26];
    int cnt2[26];

    int minSteps(string s, string t) {
    	memset(cnt1, 0, sizeof(cnt1));
    	memset(cnt2, 0, sizeof(cnt2));
        for(int i=0;i<s.size();i++){
            cnt1[s[i] - 'a']++;
            cnt2[t[i] - 'a']++;
        }

        int diff = 0;
        for(int i=0;i<26;i++){
        	// printf("i: %d cnt1: %d , cnt2: %d\n", i, cnt1[i], cnt2[i]);
            diff += abs(cnt1[i] - cnt2[i]);
        }

        // printf("total diff %d\n", diff);

        return diff / 2;
    }
};

int main(){
	Solution s;
	printf("%d\n", s.minSteps("aa", "bb"));
	
	return 0;
};


baaaa