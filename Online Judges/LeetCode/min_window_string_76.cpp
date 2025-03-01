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
    int cnt[52];
    vector<ii> cntList; 
    string minWindow(string s, string t) {
        memset(cnt, 0, sizeof cnt);
        set<int> missingIndexes;
        for(int i=0;i<t.size();i++){
            cnt[getIdx(t[i])]++;
            missingIndexes.insert(getIdx(t[i]));
        }

        int n = s.size();
        //this index is the index that points to char that I will remove / add
        int left = 0, right = 0;
        int curCnt[52];
        memset(curCnt, 0, sizeof curCnt);
        
        int minLen = 1000000;
        int startIdx = -1;
        while((left < n && right < n) || missingIndexes.size() == 0) {
            // printf("left: %d right: %d\n", left, right);
            if(missingIndexes.size() > 0) {
                //take right, then advance right
                int idxAlphabet = getIdx(s[right++]);
                curCnt[idxAlphabet]++;
                if(curCnt[idxAlphabet] >= cnt[idxAlphabet]) {
                    missingIndexes.erase(idxAlphabet);
                }
            }

            if(missingIndexes.size() == 0){
                int len = right - left;
                // printf("found temp ans, right: %d left: %d\n", right, left);
                // cout<<"cdd: "<<s.substr(left, len)<<endl;
                if(minLen > len) {
                    minLen = len;
                    startIdx = left;
                }
                int idxAlphabet = getIdx(s[left++]);
                curCnt[idxAlphabet]--;
                if(curCnt[idxAlphabet] < cnt[idxAlphabet]) {
                    missingIndexes.insert(idxAlphabet);
                }
            }
        }

        if(startIdx == -1) {
            return "";
        }

        return s.substr(startIdx, minLen);
    }

    int getIdx(char c) {
        if(isUpper(c)) {
            return c - 'A' + 26;
        }

        return c - 'a';
    }

    bool isUpper(char c) {
        return c >= 'A' && c <= 'Z';
    }
};

int main() {
    string s,t;
    while(cin>>s>>t) {
        Solution sol;
        string ans = sol.minWindow(s, t);
        cout<<ans<<endl;
    }
    return 0;
}