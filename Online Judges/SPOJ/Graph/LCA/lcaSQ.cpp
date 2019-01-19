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

const int maxn = 1e4 + 5;

vector<vi> AdjList;

int height[2*maxn], euler[2*maxn], awal[2*maxn], idx, st[8*maxn];

int left(int n){return 2*n+1;}
int right(int n){return 2*n+2;}

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
	int indeks = query(0,0,idx,idx1, idx2);
	return euler[indeks];
}

int main(){
	int n,i,j;
	int tc = 1;

	for(int tt=1;tt<=tc;tt++){
		AdjList.assign(maxn, vi());
		scanf("%d",&n);
		for(i=0;i<n;i++){
			int ukuran;
			scanf("%d",&ukuran);
			for(j=0;j<ukuran;j++){
				int anak;
				scanf("%d",&anak);
				AdjList[i].pb(anak);
				// AdjList[anak].pb(i);
			}
		}
		memset(awal, -1, sizeof awal);
		idx = 0;
		dfs(0,0,-1);
		build(0,0,idx);
		// for(i=0;i<idx;i++){printf("%d ",euler[i]);}
		// printf("\n");
		// for(i=0;i<idx;i++){printf("%d ",height[i]);}
		// printf("\n");
		int q;
		scanf("%d",&q);
		while(q--){
			int a,b;
			scanf("%d %d",&a,&b);

			int ans = lca(a,b);
			printf("%d\n",ans);
		}
	}
	

	return 0;
};