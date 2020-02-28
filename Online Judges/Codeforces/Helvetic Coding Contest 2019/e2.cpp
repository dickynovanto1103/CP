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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
 
const int maxn = 2e6 + 4;
 
vector<vii> AdjList, adj;
vi parent, depth, heavy, head, pos;
vector<vi> indexx;
int curPos;
int sz[maxn];
int w[maxn], tempW[maxn];
int akhir[maxn];
 
 
int dfs(int node, int p, int dalam) {
	sz[node] = 1;
	int maks = 0;
	depth[node] = dalam;
	for(int i=0;i<AdjList[node].size();i++){
		ii v = AdjList[node][i];
		int tetangga = v.first, berat = v.second;
 
		if(tetangga != p) {
			int idx = indexx[node][i];
			akhir[idx] = tetangga;
 
			parent[tetangga] = node;
			int ukuranTetangga = dfs(tetangga, node, dalam+1);
			sz[node] += ukuranTetangga;
			tempW[tetangga] = berat;
 
			if(maks < ukuranTetangga) {
				maks = ukuranTetangga;
				heavy[node] = tetangga;
			}
		}
 
	}
	return sz[node];
}
 
void decompose(int node, int h) {
	head[node] = h, pos[node] = curPos++;
 
	if(heavy[node] != -1) {
		decompose(heavy[node], h);
	}
 
	for(int i=0;i<AdjList[node].size();i++){
		ii v = AdjList[node][i];
		int tetangga = v.first, berat = v.second;
 
		if(parent[node] != tetangga && heavy[node] != tetangga) {
			decompose(tetangga, tetangga);
		}
	}
}
 
void assignWeight(int n) {
	for(int i=1;i<=n;i++){
		int posisi = pos[i];
		w[posisi] = tempW[i];
	}
}
 
int st[4*maxn];
 
int left(int n){return n<<1;}
int right(int n){return (n<<1) + 1;}
 
void build(int node, int l, int r) {
	if(l == r) {
		st[node] = w[l];
		return;
	}
	int mid = (l+r)/2;
	build(left(node), l, mid);
	build(right(node), mid+1, r);
 
	st[node] = max(st[left(node)], st[right(node)]);
}
 
int query(int node, int l, int r, int i, int j) {
	if(j < l || r < i) {return -inf;}
	if(i <= l && r <= j){return st[node];}
	int mid = (l+r)/2;
	int ans1 = query(left(node), l, mid, i, j);
	int ans2 = query(right(node), mid+1, r, i, j);
	
	return max(ans1, ans2);
}
 
void update(int node, int l, int r, int idx, int val) {
	if(r < idx || l > idx){return;}
	if(idx == r && idx == l){
		st[node] = val;
		return;
	}
	int mid = (l+r)/2;
	update(left(node), l, mid, idx, val);
	update(right(node), mid+1, r, idx, val);
	st[node] = max(st[left(node)], st[right(node)]);
}
 
void updateQuery(int idx, int val) {
	int nodeAkhir = akhir[idx];
	update(1,1,curPos,pos[nodeAkhir], val);
}
 
int jawabQuery(int a, int b) {
	if(a == b){return 0;}
	int ans = -inf;
	for(; head[a] != head[b]; b = parent[head[b]]) {
		if(depth[head[a]] > depth[head[b]]) {
			swap(a,b);
		}
		int cur = query(1,1,curPos,pos[head[b]], pos[b]);
		ans = max(ans, cur);
	}
	if(depth[a] > depth[b]) {
		swap(a,b);
	}
 
	int cur = query(1,1,curPos,pos[a]+1, pos[b]);
	ans = max(ans, cur);
	return ans;
}
 
void preprocess() {
	int n = AdjList.size();
	parent = vi(n+1);
	depth = vi(n+1);
	heavy = vi(n+1, -1);
	head = vi(n+1);
	pos = vi(n+1);
 
	curPos = 1;
	dfs(1, -1,0);
	decompose(1,1);
	assignWeight(n);
	build(1,1,curPos);
}

struct pasangan{
	int jarak, a, b, id;
};

vector<pasangan> edgeList, tempEdgeList;

bool cmp(pasangan a, pasangan b){
	return a.jarak < b.jarak;
}


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

bool vis[maxn];
 
int main(){
 
	int tc,i,j,n,m;
	
	tc = 1;

	while(tc--){
		// cin>>n;
		scanf("%d %d",&n,&m);
		AdjList.assign(n+1, vii());
		indexx.assign(n+1, vi());
		for(i=0;i<m;i++){
			int a,b,c;
			// cin>>a>>b>>c;
			scanf("%d %d %d",&a,&b,&c);
			pasangan pas;
			pas.jarak = c; pas.a = a; pas.b = b; pas.id = i;
			edgeList.pb(pas);
			// adj[a].pb(ii(b,c)); adj[b].pb(ii(a,c));
			tempEdgeList.pb(pas);
		}

		sort(edgeList.begin(),edgeList.end(), cmp);
		
		memset(vis, false, sizeof vis);
		UnionFind UF(n+1);
		for(i=0;i<m;i++){
			pasangan edge = edgeList[i];
			int jarak = edge.jarak, a = edge.a, b = edge.b, id = edge.id;
			if(!UF.isSameSet(a,b)){
				UF.unionSet(a,b);
				indexx[a].pb(i+1);
				indexx[b].pb(i+1);
				AdjList[a].pb(ii(b,jarak));
				AdjList[b].pb(ii(a,jarak));
				vis[id] = true;
			}
		}
 
		preprocess();
 		
 		for(i=0;i<m;i++){
 			if(!vis[i]){
 				int a = tempEdgeList[i].a, b = tempEdgeList[i].b;
 				printf("%d\n",jawabQuery(a,b));
 			}
 		}
		// char kata[10];
		// while(scanf("%s",kata), kata[0]!='D') {
		// 	int a,b;
		// 	// cin>>a>>b;
		// 	scanf("%d %d",&a,&b);
		// 	// printf("kata: "); cout<<kata; printf(" %d %d\n",a,b);
		// 	if(kata[0] == 'Q') {
		// 		// cout << jawabQuery(a,b)<<endl;
		// 		printf("%d\n",jawabQuery(a,b));
		// 	}else{
		// 		updateQuery(a, b);
		// 	}
		// }
	}
	return 0;
};  