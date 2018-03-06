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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

set<string> s;
string temp;

const int ALPHABET_SIZE = 10;

struct TrieNode {
	struct TrieNode *children[ALPHABET_SIZE];

	bool isEndOfWord;
};

struct TrieNode *getNode() {
	struct TrieNode *pNode = new TrieNode;
	int i;
	pNode->isEndOfWord = false;
	for(i=0;i<ALPHABET_SIZE;i++) {
		pNode->children[i] = NULL;
	}

	return pNode;
}

void insert(struct TrieNode *root, string key) {
	struct TrieNode *pCrawl = root;
	int i;
	for(i=0;i<key.length();i++){
		int idx = key[i] - 'a';
		if(!pCrawl->children[idx]) {
			pCrawl->children[idx] = getNode();
		}
		pCrawl = pCrawl->children[idx];
	}
}

bool isPrefixExist(struct TrieNode *root, string key) {
	struct TrieNode *pCrawl = root;
	int i;
	temp = "";
	for(i=0;i<key.length();i++){
		int idx = key[i] - 'a';
		if(!pCrawl->children[idx]) {
			return false;
		}
		pCrawl = pCrawl->children[idx];
		temp+=key[i];
	}
	if(s.find(temp) == s.end()){return false;}
	else{return true;}
}

int main(){
	int n,i,j;
	string kata;
	scanf("%d",&n);
	struct TrieNode *root = getNode();
	for(i=0;i<n;i++){
		cin>>kata;
		//cari dulu di trie

		if(isPrefixExist(root, kata)) {
			printf("BAD SET\n");
			cout<<kata<<endl; return 0;
		}else{
			if(s.find(temp) != s.end()) {
				printf("BAD SET\n");
				cout<<kata<<endl; return 0;	
			}else{
				//klo ga ada prefix...insert to trie
				s.insert(root, kata);
			}
		}
		
	}
	printf("GOOD SET\n");
	return 0;
};