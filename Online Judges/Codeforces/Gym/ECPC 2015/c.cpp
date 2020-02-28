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

const int maxn = 1e5 + 5;

int lo[maxn], hi[maxn];
int type[maxn], a[maxn], b[maxn], ans[maxn];
vector<vi> adj;

void createAdj(int m) {
	int i,j;
	adj.assign(maxn, vi());
	for(i=1;i<=m;i++){
		if(type[i] == 2){
			int mid = (lo[i] + hi[i])/2;
			adj[mid].pb(i);
		}
	}
}

int main(){
	int tc,n,m,i,j;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&m);
		for(i=1;i<=m;i++){
			scanf("%d %d %d",&type[i], &a[i], &b[i]);
			ans[i] = -1;
			if(type[i] == 2){
				lo[i] = 1, hi[i] = i-1;
			}
		}
		while(true){
			UnionFind UF(n+1);
			createAdj(m);
			bool adaBerubah = false;
			for(i=1;i<=m;i++){
				if(type[i] == 1){
					UF.unionSet(a[i], b[i]);
				}
				int mid = i;
				for(j=0;j<adj[mid].size();j++){
					int idx = adj[mid][j];
					if(lo[idx] <= hi[idx]){
						adaBerubah = true;
						int src = a[idx], dest = b[idx];
						if(UF.isSameSet(src, dest)){
							// printf("sama ans[%d]: %d\n",idx,mid);
							ans[idx] = mid;
							hi[idx] = mid - 1;
						}else{
							// printf("beda\n");
							lo[idx] = mid + 1;
						}
					}
				}
			}
			if(!adaBerubah){break;}
		}
		for(i=1;i<=m;i++){
			if(type[i] == 2){
				printf("%d\n",ans[i]);
			}
		}
	}
	return 0;
};