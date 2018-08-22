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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);

const int maxChar = 60;

struct vertex{
	int next[maxChar];
	bool leaf = false;
	int parent = -1;
	char kar;
	int link = -1;
	int go[maxChar];
	vi idx;

	vertex(int parent = -1, char kar = '$') : parent(parent), kar(kar) {
		memset(next, -1, sizeof next);
		memset(go, -1, sizeof go);
	}
};

vector<vertex> trie;

void addString(string word, int idx){
	int node = 0;
	for(char kar: word){
		int bil = kar - 'A';
		if(trie[node].next[bil] == -1){
			trie[node].next[bil] = trie.size();
			trie.emplace_back(node, kar);
		}
		node = trie[node].next[bil];
	}
	trie[node].leaf = true;
	trie[node].idx.pb(idx);
}

int go(int node, char nextChar);

int getLink(int node){
	if(trie[node].link == -1){
		if(node == 0 || trie[node].parent == 0){
			trie[node].link = 0;
		}else{
			trie[node].link = go(getLink(trie[node].parent), trie[node].kar);
		}
	}
	return trie[node].link;
}

int go(int node, char nextChar){
	int bil = nextChar - 'A';
	if(trie[node].go[bil] == -1){
		if(trie[node].next[bil] != -1){
			trie[node].go[bil] = trie[node].next[bil];
		}else{
			trie[node].go[bil] = (node == 0 ? 0: go(getLink(node), nextChar));

		}
	}
	return trie[node].go[bil];
}

const int maxn = 1e3 + 3;

int main(){
	FastSlowInput
	int tc,i,j;
	cin>>tc;
	bool isExist[maxn];
	while(tc--){
		string word;
		string listOfWord[maxn];
		cin>>word;
		int n;
		cin>>n;
		trie.assign(1, vertex());
		for(i=0;i<n;i++){
			cin>>listOfWord[i];
			addString(listOfWord[i],i);
		}
		memset(isExist, false, sizeof isExist);
		int node = 0;
		char lastKar;
		for(char kar : word){
			lastKar = kar;
			node = go(node, kar);
			if(trie[node].leaf){
				for(int idx: trie[node].idx){
					isExist[idx] = true;
				}
			}
		}
		if(node != 0){
			go(node,lastKar);
			while(node>0){
				node = getLink(node);
				if(trie[node].leaf){
					for(int idx: trie[node].idx){
						isExist[idx] = true;
					}
				}
			}
		}

		for(i=0;i<n;i++){
			if(isExist[i]){cout<<"y"<<endl;}
			else{cout<<"n"<<endl;}
		}
		trie.clear();
	}
	return 0;
};