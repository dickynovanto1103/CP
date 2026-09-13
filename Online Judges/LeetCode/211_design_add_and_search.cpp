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

struct Trie {
	Trie* children[26];
	bool isEnd;

	Trie() {
		for(int i=0;i<26;i++){
			children[i] = NULL;
		}

		isEnd = false;
	}
	~Trie() {
		for(int i=0;i<26;i++){
			delete children[i];
		}
	}

	void insert(string word) {
		Trie* cur = this;

		for(char c: word) {
			if(cur->children[c-'a'] == NULL) {
				cur->children[c-'a'] = new Trie();
			}
			cur = cur->children[c-'a'];
		}

		cur->isEnd = true;
	}

	bool match(string word) {
		Trie* cur = this;

		return dfs(0, word, cur);
	}

	bool dfs(int idx, const string& word, Trie* cur) {
		if(idx == word.size()) {
			return cur->isEnd;
		}

		char c = word[idx];
		if(c != '.'){
			if(cur->children[c-'a'] == NULL) {
				return false;
			}

			return dfs(idx+1, word, cur->children[c-'a']);
		}

		int ans = false;
		for(int i=0;i<26;i++){
			if(cur->children[i] == NULL) {continue;}
			ans |= dfs(idx+1, word, cur->children[i]);
		}

		return ans;
	}
};

class WordDictionary {
public:
	Trie* trie;
    WordDictionary() {
        trie = new Trie();
    }
    ~WordDictionary() {
    	delete trie;
    }
    
    void addWord(string word) {
        trie->insert(word);
    }
    
    bool search(string word) {
        return trie->match(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

void solve(){
	WordDictionary* wordDictionary = new WordDictionary();
	wordDictionary->addWord("bad");
	wordDictionary->addWord("dad");
	wordDictionary->addWord("mad");
	printf("%d\n", wordDictionary->search("pad")); //false
	printf("%d\n", wordDictionary->search("bad")); //true
	printf("%d\n", wordDictionary->search("dad")); //true
	printf("%d\n", wordDictionary->search("mad")); //true
	printf("%d\n", wordDictionary->search(".ad")); //true
	printf("%d\n", wordDictionary->search("..d")); //true
	printf("%d\n", wordDictionary->search("...")); //true
	printf("%d\n", wordDictionary->search("....")); //false
	printf("%d\n", wordDictionary->search(".a.")); //false
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};