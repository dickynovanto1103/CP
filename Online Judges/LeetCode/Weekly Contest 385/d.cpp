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

ll ans = 0;

struct TrieNode {
	unordered_map<int, TrieNode*> child;
	int count;
	TrieNode() {
		count = 0;
	}
};

void insertWordToTrie(TrieNode* root, string word) {
	int n = word.size();
	for(int i=0;i<n;i++){
		int num = (word[i] - 'a') * 26 + (word[n - 1 - i] - 'a');
		if(!root->child[num]) {
			root->child[num] = new TrieNode();
		}

		root = root->child[num];
		ans += root->count;
		if(i == (n-1)) {
			root->count++;
		}
	}
}

class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
    	ans = 0;
        TrieNode* root = new TrieNode();

        for(string word: words) {
        	insertWordToTrie(root, word);
        }

        return ans;
    }
};

void solve(){

}

int main(){
	// int tc = 1;
	// scanf("%d",&tc);
	// while(tc--){
	// 	solve();
	// }

	int n;
	while(cin>>n) {
		vector<string> words(n, "");
		for(int i=0;i<n;i++){
			cin>>words[i];
		}

		Solution s;
		ll jawab = s.countPrefixSuffixPairs(words);
		printf("%lld\n", jawab);
	}

	return 0;
};