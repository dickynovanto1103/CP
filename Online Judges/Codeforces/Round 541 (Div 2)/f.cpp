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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 150010;

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

int main(){
	int n,i,j;
	scanf("%d",&n);
	int arr[maxn];
	
	int next[maxn], prev[maxn], nextGlobal[maxn], prevGlobal[maxn];
	// memset(next, -1, sizeof next); memset(prev, -1, sizeof prev);
	// memset(nextGlobal, -1, sizeof nextGlobal); memset(prevGlobal, -1, sizeof prevGlobal);
	for(i=1;i<=n;i++){
		next[i] = i; prev[i] = i;
		nextGlobal[i] = i, prevGlobal[i] = i;
	}
	UnionFind UF(n+1);
	for(i=0;i<n-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		
		int id1 = UF.findSet(a), id2 = UF.findSet(b);
		int kanan = nextGlobal[id1], kiri = prevGlobal[id2];
		int palingKiri = prevGlobal[id1], palingKanan = nextGlobal[id2];
		next[kanan] = kiri;
		prev[kiri] = kanan;
		UF.unionSet(a,b);
		int id = UF.findSet(a);
		prevGlobal[id] = palingKiri, nextGlobal[id] = palingKanan;
	}

	int start = -1;
	// for(i=1;i<=n;i++){
	// 	printf("prev[%d]: %d next[%d]: %d\n", i,prev[i], i, next[i]);
	// }
	for(i=1;i<=n;i++){
		if(prev[i] == i){start = i; break;}
	}
	bool first = true;
	while(next[start] != start) {
		if(!first){printf(" ");}
		printf("%d",start);
		start = next[start];
		first = false;
	}
	printf(" %d\n",start);

	return 0;
};