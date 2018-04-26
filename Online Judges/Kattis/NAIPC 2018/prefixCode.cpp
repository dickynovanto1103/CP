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

const int maxn = 1e6;
string kata[maxn];
int banyakTrie = 1;

struct trie_node{
	int next[26];
	int index;

	trie_node() {
		fill(next, next + 26, -1);
		index = -1;
	}
};

void insertTrie(int index, string kata) {
	int pjg = kata.length();
	int root = 0;
	for(int i = 0; i < pjg; i++) {
		char kar = kata[i];
		int next = trie[root].next[kar-'a'];
		if(next == -1) {
			trie[root].next[kar-'a'] = banyakTrie;
			next = banyakTrie++;
		}
		root = next;
	}
	trie[root].index = index;
}

trie_node trie[maxn];

int main(){
	int n,k,i,j;
	printf("%d\n",trie[10].index);
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){
		cin>>kata[i];
	}
	sort(kata,kata+n);
	
	for(i=0;i<n;i++){
		cout<<kata[i]<<endl;
	}
	
	string q;
	cin>>q;

	

	return 0;
};