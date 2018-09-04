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

class UnionFind{
private: 
	vi rank,p,setSize;
	int numset,i;
public:
	UnionFind(int n){
		numset=n; setSize.assign(n,1); rank.assign(n,0); p.assign(n,0);
		for(i=0;i<n;i++){p[i]=i;}
	}

	int findSet(int i){return (p[i]==i) ? i : (p[i]=findSet(p[i]));}
	bool isSameSet(int i, int j){return findSet(i)==findSet(j);}
	void unionSet(int i, int j){
		if(!isSameSet(i,j)){
			numset--;
			int x=findSet(i), y=findSet(j);
			if(rank[x] > rank[y]){p[y]=x; setSize[x]+=setSize[y];}
			else{
				p[x]=y;
				setSize[y]+=setSize[x];
				if(rank[x]==rank[y]){rank[y]++;}
			}
		}
	}
	int numDisjointSet(){return numset;}
	int sizeSetOf(int i){return setSize[findSet(i)];}
};

const int maxn = 2e5 + 5;

int bit[maxn];
int n;
int update(int idx, int val){
	for(int i=idx;i<=n;i+=(i&-i)){
		bit[i] += val;
	}
}

ll query(int idx){
	ll sum = 0;
	for(int i=idx;i>=1;i-=(i&-i)){
		sum += bit[i];
	}
	return sum;
}

int main(){
	int m,k,i,j;
	scanf("%d %d %d",&n,&m,&k);
	UnionFind UF(n+1);
	multiset<int> s;
	multiset<int>::iterator it;
	for(i=1;i<=n;i++){
		update(i,1);
	}
	k++;
	for(i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		int ukuranA = sizeSetOf(a);
		int ukuranB = sizeSetOf(b);
		update(ukuranA, -ukuranA);
		it = s.find(ukuranA);
		s.erase(it);
		it = s.find(ukuranB);
		s.erase(it);
		UF.unionSet(a,b);
		int ukuranA = sizeSetOf(a);
		s.insert(ukuranA);
		//cari berapa banyak yang at least

	}
	return 0;
};