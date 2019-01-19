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

const int maxn = 1e5 + 5;

vector<vi> AdjList;
vi head, parent, depth, pos, heavy;
int curPos;
int indeks[maxn];

int dfs(int node, int p, int dalam) {
	depth[node] = dalam;
	parent[node] = p;
	int ukuran = 1;
	int maks = 0;
	for(int i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		if(v != p){
			int ukuranTetangga = dfs(v, node, dalam+1);

			ukuran += ukuranTetangga;
			if(ukuranTetangga > maks) {
				maks = ukuranTetangga;
				heavy[node] = v;
			}
		}
	}
	return ukuran;
}

void decompose(int node, int h) {
	pos[node] = curPos;
	indeks[curPos] = node;
	curPos++;
	head[node] = h;
	if(heavy[node] != -1){
		decompose(heavy[node], h);
	}

	for(int i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		if(v!=parent[node] && v!=heavy[node]) {
			decompose(v, v);
		}
	}
}

int st[4*maxn];

int left(int n){return 2*n;}
int right(int n){return 2*n+1;}

int query(int node, int l, int r, int i, int j){
	if(j < l || r < i){return inf;}
	if(i<=l && r <= j){return st[node];}
	int mid = (l+r)/2;
	int ans1 = query(left(node), l, mid, i, j);
	int ans2 = query(right(node), mid+1, r, i, j);
	return min(ans1,ans2);
}

void update(int node, int l, int r, int idx, int val) {
	if(r < idx || l > idx){return;}
	if(l == idx && r == idx){
		st[node] = val;
		return;
	}
	int mid = (l+r)/2;
	update(left(node), l, mid, idx, val);
	update(right(node), mid+1, r, idx, val);
	st[node] = min(st[left(node)], st[right(node)]);
}

void preprocess() {
	int n = AdjList.size();
	head = vi(n);
	parent = vi(n);
	depth = vi(n);
	pos = vi(n);
	heavy = vi(n, -1);
	curPos = 1;

	dfs(1,-1,0);
	decompose(1,1);
	fill(st, st+4*maxn, inf);
}

int col[maxn];

int jawabQuery(int a, int b) {
	int minim = inf;
	for(; head[a] != head[b]; b = parent[head[b]]) {
		if(depth[head[a]] > depth[head[b]]){
			swap(a,b);
		}
		int ans = query(1,1,curPos, pos[head[b]], pos[b]);

		minim = min(minim, ans);
		// printf("a: %d b: %d minim jadi: %d pos[%d]: %d head[%d]; %d\n",a,b,minim,head[b], pos[head[b]], b, head[b]);
	}
	if(depth[a] > depth[b]){
		swap(a,b);
	}

	int ans = query(1,1,curPos, pos[a], pos[b]);
	minim = min(minim, ans);
	// printf("terakhir a: %d b: %d minim jadi: %d\n",a,b,minim);
	return minim;
}

int main(){
	int n,q,i,j;
	while(scanf("%d %d",&n,&q)!=EOF){
		memset(col, 0, sizeof col); memset(indeks, 0, sizeof indeks);
		AdjList.assign(n+1, vi());
		for(i=0;i<n-1;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			AdjList[a].pb(b); AdjList[b].pb(a);
		}

		preprocess();
		// for(i=1;i<=n;i++){
		// 	printf("pos[%d]: %d head[%d]: %d\n",i,pos[i],i,head[i]);
		// }

		while(q--){
			int com, node;
			scanf("%d %d",&com,&node);
			if(com == 0){
				col[node] = 1 - col[node];
				//update
				// printf("col[%d] jadi: %d\n",node,col[node]);
				int posisi = pos[node];
				// printf("posisi node: %d -> %d\n",node,posisi);
				if(col[node] == 1){
					update(1,1,curPos,posisi, posisi);
				}else{
					update(1,1,curPos,posisi, inf);
				}
			}else{
				int ans = jawabQuery(1,node);
				// printf("ans: %d\n",ans);
				if(ans == inf){printf("-1\n");}
				else{
					printf("%d\n",indeks[ans]);
				}
			}
		}	
	}
	

	return 0;
};