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
	
	int counter;
};

struct TrieNode *getNode(void) {
	struct TrieNode *pNode = new TrieNode;
	
	for(int i=0;i<ALPHABET_SIZE;i++){
		pNode->counter = 0;
		pNode->children[i] = NULL;
	}
	return pNode;
};

void insert(struct TrieNode *root, string key) {
	struct TrieNode *pCrawl = root;
	for(int i=0;i<key.length();i++){
		int idx = key[i] - 'a';
		if(!pCrawl->children[idx]){
			pCrawl->children[idx] = getNode();
		}
		
		pCrawl = pCrawl->children[idx];
		pCrawl->counter++;
	}
	
}

int numberOfOcc(struct TrieNode *root, string key) {
	struct TrieNode *pCrawl = root;
	for(int i=0;i<key.length();i++){
		int idx = key[i] - 'a';
		if(!pCrawl->children[idx]){
			return 0;
		}
		pCrawl = pCrawl->children[idx];
	}
	return pCrawl->counter;
}

int main(){
	int n,i,j;
	string kata;
	string com;
	scanf("%d",&n);
	struct TrieNode *root = getNode();

	while(n--){
		cin>>com>>kata;
		if(com[0]=='a'){
			insert(root, kata);
		}else{
			int ans = numberOfOcc(root, kata);
			printf("%d\n",ans);
		}
	}

	return 0;
};