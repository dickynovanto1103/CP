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

const int ALPHABET_SIZE = 26;
struct TrieNode {
	struct TrieNode *children[ALPHABET_SIZE];
	int maks;
};

struct TrieNode *getNode() {
	struct TrieNode *pNode = new TrieNode;
	for(int i=0;i<ALPHABET_SIZE;i++){
		pNode->children[i] = NULL;
		pNode->maks = -1;
	}
	return pNode;
}

void insert(struct TrieNode *root, string key, int nilai) {
	struct TrieNode *pCrawl = root;
	for(int i=0;i<key.length();i++){
		int idx = key[i] - 'a';
		if(!pCrawl->children[idx]){
			pCrawl->children[idx] = getNode();
		}
		pCrawl = pCrawl->children[idx];
		pCrawl->maks = max(pCrawl->maks, nilai);
	}
}

int getMax(struct TrieNode *root, string kata) {
	struct TrieNode *pCrawl = root;
	for(int i=0;i<kata.length();i++){
		int idx = kata[i] - 'a';
		if(!pCrawl->children[idx]){
			return -1;
		}
		pCrawl = pCrawl->children[idx];
	}
	return pCrawl->maks;
}

int main(){
	int n,i,j,q;
	scanf("%d %d",&n,&q);
	struct TrieNode *root = getNode();
	
	for(i=0;i<n;i++){
		string kata;
		int nilai;
		cin>>kata;
		scanf("%d",&nilai);
		insert(root, kata, nilai);
	}
	while(q--){
		string kata;
		cin>>kata;
		int ans = getMax(root, kata);
		printf("%d\n",ans);
	}
	return 0;
};