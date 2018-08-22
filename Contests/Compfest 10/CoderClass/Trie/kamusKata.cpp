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

const int maxn = 3e5 + 5;

struct trie{
	int next[26];
	int banyak;
	trie(){
		memset(next, -1, sizeof next);
		banyak = 0;
	}
};
int kedalamanTrie = 1;
trie trie_node[maxn];
string kata;

void add(string kata){
	int i;
	int pjg = kata.length();
	int node = 0;
	trie_node[node].banyak++;
	for(i=0;i<pjg;i++){
		char kar = kata[i];
		int next = trie_node[node].next[kar - 'a'];

		if(next == -1){
			next = trie_node[node].next[kar - 'a'] = kedalamanTrie++;
		}
		node = next;
		trie_node[node].banyak++;
	}
}

int go(int idx){
	int i,pjg = kata.length();
	int node = 0;
	for(i=0;i<pjg;i++){
		char kar = kata[i];
		int next = trie_node[node].next[kar - 'a'];
		if(next == -1){
			return 0;
		}else{
			node = next;
		}
	}
	int cnt = trie_node[node].banyak;
	return cnt;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	set<string> s;
	for(i=0;i<n;i++){
		int com;
		cin>>com>>kata;
		if(com == 1){
			if(s.find(kata) == s.end()){
				add(kata);
				s.insert(kata);
			}
			
		}else{
			int ans = go(0);
			printf("%d\n", ans);
		}
	}
	return 0;
};