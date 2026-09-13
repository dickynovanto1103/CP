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

class Trie {
public:
	Trie* children[26];
	bool isEndOfWord;
    Trie() {
    	for(int i=0;i<26;i++){
    		children[i] = NULL;
    	}
        isEndOfWord = false;
    }
    
    void insert(string word) {
    	Trie* cur = this;
        for(char c: word) {
        	if(cur->children[c-'a'] == NULL)  {
        		cur->children[c-'a'] = new Trie();
        	}
        	cur = cur->children[c-'a'];
        }
        cur->isEndOfWord = true;
    }
    
    bool search(string word) {
        Trie* cur = this;
        for(char c: word) {
        	if(cur->children[c-'a'] == NULL) {return false;}
        	cur = cur->children[c-'a'];
        }

        return cur->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        Trie* cur = this;
        for(char c: prefix) {
        	if(cur->children[c-'a'] == NULL) {return false;}
        	cur = cur->children[c-'a'];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

void solve(){
	Trie* trie = new Trie();
	trie->insert("apple");
	trie->insert("apple");
	trie->insert("bab");
	printf("%d\n", trie->search("apple"));   // return True
	printf("%d\n", trie->search("app"));     // return False
	printf("%d\n", trie->startsWith("app")); // return True
	trie->insert("app");
	printf("%d\n", trie->search("app"));     // return True
	printf("%d\n", trie->search("ap"));     // return False
	printf("%d\n", trie->search("babi"));     // return False
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};