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
    string s, p;
    int sSize, pSize;
    int dp[21][21];

    bool isMatch(string s, string p) {
        this->s = s;
        this->p = p;
        sSize = s.size();
        pSize = p.size();
        memset(dp, -1, sizeof dp);

        return isMatchIdx(0, 0);
    }

    bool isMatchIdx(int idxS, int idxP) {
        if(idxP >= pSize) {return idxS >= sSize;}

        if(dp[idxS][idxP] != -1) {return dp[idxS][idxP];}

        bool firstMatch = idxS < sSize && (s[idxS] == p[idxP] || p[idxP] == '.');

        if((idxP + 2) <= pSize && p[idxP + 1] == '*') {
            //either we ignore this pattern, so it will go to idxP + 2, or we go with next idx of idxS if matching, but not moving idxP
            return dp[idxS][idxP] = isMatchIdx(idxS, idxP + 2) || (firstMatch && isMatchIdx(idxS + 1, idxP));
        }else{
            return dp[idxS][idxP] = firstMatch && isMatchIdx(idxS + 1, idxP + 1);
        }
    }
};

int main(){
    Solution sol;
    string s, p;
    while(cin>>s>>p) {
        cout<<boolalpha<<sol.isMatch(s, p)<<endl;
    }
    
    
    
    return 0;
};

