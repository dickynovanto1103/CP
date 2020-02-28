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

vector<vi> adj, listIdx;
const int maxn = 2e5 + 5;

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

struct query{
	int val, idx;
};

bool cmp(query a, query b){
	return a.val < b.val;
}

int main(){
	int n,q,i,j;
	scanf("%d %d",&n,&q);
	listIdx.assign(maxn, vi());
	adj.assign(maxn, vi());
	int a[maxn], b[maxn];
	for(i=0;i<n-1;i++){
		int w;
		scanf("%d %d %d",&a[i],&b[i],&w);
		listIdx[w].pb(i);
	}
	query qu[maxn];
	for(i=0;i<q;i++){
		int val;
		scanf("%d",&val);
		qu[i].val = val; qu[i].idx = i;
	}

	sort(qu, qu + q, cmp);
	int weightNow = 0;
	UnionFind UF(n);
	ll cur = 0;
	ll ans[maxn];
	for(i=0;i<q;i++){
		int val = qu[i].val;
		while(weightNow <= val) {
			for(j=0;j<listIdx[weightNow].size();j++){
				int idx = listIdx[weightNow][j];
				int x = a[idx], y = b[idx];
				if(!UF.isSameSet(x, y)) {
					ll sizeX = UF.sizeSetOf(x);
					ll sizeY = UF.sizeSetOf(y);
					cur -= (sizeX*(sizeX-1))/2LL;
					cur -= (sizeY*(sizeY-1))/2LL;

					UF.unionSet(x,y);
					ll sz = UF.sizeSetOf(x);
					cur += (sz*(sz-1))/2LL;
				}
			}
			weightNow++;
		}
		int idx = qu[i].idx;
		ans[idx] = cur;
	}
	for(i=0;i<q;i++){
		if(i){printf(" ");}
		printf("%lld",ans[i]);
	}
	printf("\n");
	return 0;
};