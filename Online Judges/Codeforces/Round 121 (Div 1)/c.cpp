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

vector<vi> AdjList, naik;

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
	if(ans1 == ans2 && ans1 == -1){assert(false);}
	if(ans1 == -1){return ans2;}
	if(ans2 == -1){return ans1;}

	int idxMinKiri = ans1;
	int idxMinKanan = ans2;

	int ans = (height[idxMinKiri] < height[idxMinKanan] ? idxMinKiri : idxMinKanan);
	return ans;
}

void dfs(int node, int depth, int p) {
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

vi listLeaf;
int counter[maxn];

void dfs1(int node,int p){
	bool isMasuk = false;
	for(int i=0;i < AdjList[node].size();i++){
		int v = AdjList[node][i];
		if(v != p){
			isMasuk = true;
			naik[v].pb(node);
			dfs1(v, node);
		}
	}
	if(!isMasuk){listLeaf.pb(node);}
}

int ans[maxn];
map<ii, int> mapper;

int updateTree(int node, int p){
	for(int i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		if(v!=p){
			counter[node] += updateTree(v, node);
		}
	}
	return counter[node];
}

void updateAns(int front, int v, int jumlah) {
	int minim = min(front,v);
	int maks = max(front,v);
	int indeks = mapper[ii(minim,maks)];
	ans[indeks] = jumlah;
}

void dfs2(int node, int p){
	for(int i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		if(v!=p){
			updateAns(node, v, counter[v]);
			dfs2(v, node);
		}
	}	
}

int main(){
	int n,i,j;
	
	scanf("%d",&n);
	AdjList.assign(maxn, vi()); naik.assign(maxn, vi());
	
	for(i=0;i<n-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		int minim = min(a,b);
		int maks = max(a,b);
		mapper[ii(minim,maks)] = i;
		AdjList[a].pb(b);
		AdjList[b].pb(a);
	}

	dfs1(1,-1);
	idx = 1;
	memset(awal, -1, sizeof awal);
	dfs(1,0,-1);
	build(1,1,idx);

	int query;
	scanf("%d",&query);

	while(query--){
		int a,b;
		scanf("%d %d",&a,&b);
		int nodeLCA = lca(a,b);
		counter[a]++;
		counter[b]++;
		counter[nodeLCA]-=2;
	}

	updateTree(1,-1);
	dfs2(1,-1);
	
	for(i=0;i<n-1;i++){
		if(i){printf(" ");}
		printf("%d",ans[i]);
	}
	printf("\n");


	return 0;
};