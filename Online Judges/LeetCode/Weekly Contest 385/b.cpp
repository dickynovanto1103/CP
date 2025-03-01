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

// Structure of Trie
struct TrieNode {
    // Stores characters of
    // each string
    TrieNode* child[10];
 
    TrieNode() {
        for(int i=0;i<10;i++){
            child[i] = NULL;
        }
    }
};

vi getDigits(int num) {
    vi digits;

    while(num) {
        int digit = num % 10;
        digits.pb(digit);
        num /= 10;
    }

    reverse(digits.begin(), digits.end());
    return digits;
}

void insertTrie(TrieNode* root, int num) {
    vi digits = getDigits(num);
    for(int digit: digits) {
        if(!root->child[digit]) {
            root->child[digit] = new TrieNode();
        }

        root = root->child[digit];
    }
}

int findMaxPrefixLen(TrieNode* root, int num) {
    vi digits = getDigits(num);
    int len = 0;
    for(int i=0;i<digits.size();i++){
        if(root->child[digits[i]]) {
            root = root->child[digits[i]];
            len++;
        }else{
            return len;
        }
    }

    return len;
}

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* root = new TrieNode();
        TrieNode* dummy = root;
        for(int num: arr2) {
            insertTrie(dummy, num);
            dummy = root;
        }

        int maks = 0;
        for(int i=0;i<arr1.size();i++){
            maks = max(maks, findMaxPrefixLen(dummy, arr1[i]));
            dummy = root;
        }

        return maks;
    }
};

void solve(){

}

int main(){
    // int tc = 1;
    // scanf("%d",&tc);
    // while(tc--){
    //     solve();
    // }

    int n,m;
    while(scanf("%d %d",&n,&m) != EOF) {
        vi arr1(n, 0);
        vi arr2(m, 0);
        for(int i=0;i<n;i++){
            scanf("%d",&arr1[i]);
        }
        for(int i=0;i<m;i++){
            scanf("%d",&arr2[i]);
        }

        Solution s;
        int ans = s.longestCommonPrefix(arr1, arr2);
        printf("%d\n",ans);
    }

    return 0;
};