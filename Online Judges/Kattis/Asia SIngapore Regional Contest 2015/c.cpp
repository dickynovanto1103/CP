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
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

// class UnionFind{
// private: 
// 	vi rank,p,setSize;
// 	int numset,i;
// public:
// 	UnionFind(int n){
// 		numset=n; setSize.assign(n,1); rank.assign(n,0); p.assign(n,0);
// 		for(i=0;i<n;i++){p[i]=i;}
// 	}

// 	int findSet(int i){return (p[i]==i) ? i : (p[i]=findSet(p[i]));}
// 	bool isSameSet(int i, int j){return findSet(i)==findSet(j);}
// 	void unionSet(int i, int j){
// 		if(!isSameSet(i,j)){
// 			numset--;
// 			int x=findSet(i), y=findSet(j);
// 			if(rank[x] > rank[y]){p[y]=x; setSize[x]+=setSize[y];}
// 			else{
// 				p[x]=y;
// 				setSize[y]+=setSize[x];
// 				if(rank[x]==rank[y]){rank[y]++;}
// 			}
// 		}
// 	}
// 	int numDisjointSet(){return numset;}
// 	int sizeSetOf(int i){return setSize[findSet(i)];}
// };

int par[500002], sz[500002];

int find_set(int v){
	if(v == par[v])
		return v;
	return par[v] = find_set(par[v]);
}

int union_set(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a != b){
		sz[a] += sz[b];
		par[b] = a;
	}
}

int get_size(int v){
	return sz[find_set(v)];
}

int main(){
	int n,m,i,j;
	scanf("%d",&n);
	// UnionFind UF(500010);
	for(i=0;i<=500000;++i){
		par[i] = i;
		sz[i] = 1;
	}
	int ans = 0;
	set<int> wew;
	for(i=0;i<n;i++){
		scanf("%d",&m);
		int bil;
		vector<int> v;
		map<int, int> s;
		map<int, int>::iterator it;
		// printf("i: %d\n", i);
		for(j=0;j<m;j++){
			scanf("%d",&bil);
			int id = find_set(bil);
			++s[id];
			// printf("bil; %d id: %d counter jadi: %d\n",bil,id, s[id]);
		}
		bool bisa = true;
		for(const ii &x : s){
			// printf("bil: %d counter; %d\n",x.fi, x.se);
			if(get_size(x.fi) != x.se)
				bisa = false;
		}
		if(bisa){
			for(it = ++s.begin();it!=s.end();++it){
				union_set(s.begin()->fi, it->fi);
			}
			++ans;
		}

	}
	printf("%d\n",ans);
	return 0;
};