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

int height[2*maxn], euler[2*maxn], awal[2*maxn], idx, st[8*maxn];

int left(int n){return 2*n;}
int right(int n){return 2*n+1;}

void build(int node, int l, int r){
	if(l == r){
		st[node] = l;
		return;
	}
	int mid = (l+r)/2;
	build(left(node), l, mid);
	build(right(node), mid+1, r);
	int idxMinKiri = st[left(node)];
	int idxMinKanan = st[right(node)];

	(height[idxMinKiri] < height[idxMinKanan] ? st[node] = idxMinKiri : st[node] = idxMinKanan);
}

int query(int node, int l, int r, int i, int j){

	if(l > j || r < i){return -1;}
	if(i <= l && r <= j){return st[node];}
	int mid = (l+r)/2;
	int ans1 = query(left(node), l, mid, i, j);
	int ans2 = query(right(node), mid+1, r, i,j);
	if(ans1 == -1){return ans2;}
	if(ans2 == -1){return ans1;}

	int idxMinKiri = ans1;
	int idxMinKanan = ans2;

	int ans = (height[idxMinKiri] < height[idxMinKanan] ? idxMinKiri : idxMinKanan);
	return ans;
}

void dfs(int node, int depth, int p) {
	// printf("euler[%d] diassign ke node: %d\n",idx, node);
	height[idx] = depth;
	euler[idx] = node;
	if(awal[node] == -1){awal[node] = idx;}
	idx++;
	for(int i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		if(v!=p){
			dfs(v, depth+1, node);
			height[idx] = depth;
			euler[idx++] = node;
		}
	}
}

int lca(int a, int b){
	int idx1 = awal[a], idx2 = awal[b];
	if(idx1 > idx2){swap(idx1,idx2);}
	int indeks = query(1,1,idx,idx1, idx2);
	return euler[indeks];
}

int anggota[maxn];

void telusuri(int node, int root){
	anggota[node] = root;
	for(int i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		telusuri(v, root);
	}
}

vector<vi> Adj;
bool isVisited[maxn];
int indeks[maxn];

void prepare() {
	Adj.assign(maxn, vi());
	// printf("idx disini: %d\n",idx);
	for(int i=1;i<idx;i++){

		int node = euler[i];
		if(isVisited[node]){continue;}
		isVisited[node] = true;
		Adj[height[i]].pb(node);
		indeks[node] = Adj[height[i]].size() - 1;
	}
}

bool coba(int a, int b, int node, int naikMaks){
	int tinggi = height[awal[node]];
	int node1 = Adj[tinggi][a];
	int node2 = Adj[tinggi][b];
	// printf("tinggi: %d a: %d b: %d node1: %d node2: %d\n",tinggi, a, b, node1, node2);
	if(anggota[node1] != anggota[node2]){return false;}
	int nodeLCA = lca(node1, node2);
	// printf("nodeLCA: %d awal: %d\n",nodeLCA, awal[nodeLCA]);
	int tinggiLCA = height[awal[nodeLCA]];
	int selisih = tinggi - tinggiLCA;
	if(selisih > naikMaks){return false;}
	else{return true;}
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	vi listRoot;
	AdjList.assign(maxn, vi());
	for(i=1;i<=n;i++){
		int parent;
		scanf("%d",&parent);
		if(parent == 0){listRoot.pb(i);}
		else{
			AdjList[parent].pb(i);
		}
	}
	memset(awal, -1, sizeof awal);
	idx = 1;

	int titikAwalEuler[maxn];

	for(i=0;i<listRoot.size();i++){
		int awal = listRoot[i];
		telusuri(awal, awal);
		titikAwalEuler[awal] = idx;
		dfs(awal, 0, -1);
	}
	build(1,1,idx);
	// for(i=1;i<idx;i++){printf("%d ",euler[i]);}
	// printf("\n");
	// for(i=1;i<idx;i++){printf("%d ",height[i]);}
	// printf("\n");
	// for(i=1;i<idx;i++){printf("%d ",awal[i]);}
	// printf("\n");

	memset(isVisited, false, sizeof isVisited);
	prepare();

	int q;

	scanf("%d",&q);
	// printf("q: %d\n",q);
	for(i=0;i<q;i++){
		if(i){printf(" ");}
		// printf("i: %d\n",i);
		int node, naikMaks, grup;
		scanf("%d %d",&node,&naikMaks);
		// printf("node: %d naikMaks: %d\n",node,naikMaks);
		int indeksTengah = indeks[node];
		// printf("awal[%d]: %d\n",node,awal[node]);
		if(naikMaks > height[awal[node]]){printf("0");}
		else{
			// binser kiri
			int kiri = 0, kanan = indeksTengah, ansKiri;
			// printf("binser kiri kiri: %d kanan: %d\n",kiri, kanan);
			while(kiri <= kanan){
				int mid = (kiri + kanan)/2;
				if(coba(indeksTengah, mid, node, naikMaks)){
					ansKiri = mid;
					kanan = mid-1;
				}else{
					kiri = mid+1;
				}
			}

			//binser kanan
			kiri = indeksTengah, kanan = Adj[height[awal[node]]].size() - 1;
			// printf("binser kanan kiri: %d kanan: %d\n",kiri, kanan);
			int ansKanan;
			while(kiri <= kanan){
				int mid = (kiri + kanan)/2;
				if(coba(indeksTengah, mid,node,naikMaks)) {
					ansKanan = mid;
					kiri = mid+1;
				}else{
					kanan = mid-1;
				}
			}

			// printf("ansKiri: %d ansKanan: %d\n",ansKiri, ansKanan);
			printf("%d",ansKanan - ansKiri);
		}
	}
	printf("\n");

	return 0;
};