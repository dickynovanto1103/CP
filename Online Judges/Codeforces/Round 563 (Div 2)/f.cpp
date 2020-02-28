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

const int maxn = 2e5 + 5;

vector<vi> AdjList;

int height[2*maxn], euler[2*maxn], awal[2*maxn], idx, st[8*maxn];
int dalam[maxn], tin[maxn], tout[maxn], waktu;

bool isAncestor(int u, int v) {
	return tin[u] <= tin[v] && tout[v] <= tout[u];
}

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
	tin[node] = waktu++;

	dalam[node] = depth;
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

	tout[node] = waktu++;
}

int lca(int a, int b){
	int idx1 = awal[a], idx2 = awal[b];
	if(idx1 > idx2){swap(idx1,idx2);}
	int indeks = query(1,1,idx,idx1, idx2);

	return euler[indeks];
}

int main(){
	int n,i,j;
	int tc;

	AdjList.assign(maxn, vi());
	scanf("%d",&n);
	for(i=1;i<=(n-1);i++){
		int a,b;
		scanf("%d %d",&a,&b);
		AdjList[a].pb(b); AdjList[b].pb(a);
	}
	memset(euler, -1, sizeof euler);
	memset(awal, -1, sizeof awal);
	for(i=0;i<2*maxn;i++){height[i] = inf;}
	idx = 1;
	dfs(1,0,-1);
	build(1,1,idx);
	
	int second = 1;

	int dist;
	printf("d 1\n"); fflush(stdout);
	scanf("%d",&dist);
	if(dist == -1){return 0;}
	
	
	set<int> candidate;
	set<int>::iterator it;
	int newLca = -1;
	for(i=1;i<=n;i++){
		if(dalam[i] == dist && isAncestor(second, i)){
			candidate.insert(i);
			// printf("i: %d\n",i);
			if(newLca == -1){
				newLca = i;
			}else{
				newLca = lca(i, newLca);
			}
		}
	}
	if(candidate.size() == 1){
		printf("! %d\n",*candidate.begin()); fflush(stdout);
		return 0;
	}
	second = newLca;
	for(i=0;i<35;i++){
		assert(second != -1);
		printf("s %d\n",second); fflush(stdout);
		scanf("%d",&second);
		// if(second == -1){return 0;}
		set<int> newCandidate;
		newLca = -1;
		for(it=candidate.begin();it!=candidate.end();it++){
			int node = *it;
			if(isAncestor(second, node)) {
				if(newLca == -1){
					newLca = node;
				}else{
					newLca = lca(newLca, node);
				}
				newCandidate.insert(node);
				// printf("push newCandidate %d\n",node);
			}
		}
		candidate = newCandidate;

		if(candidate.size() == 1){
			printf("! %d\n",*candidate.begin()); fflush(stdout);
			return 0;
		}
		second = newLca;
	}
	//worst case banget
	int ukuran = candidate.size();
	vi ans;
	for(it=candidate.begin();it!=candidate.end();it++){
		ans.pb(*it);
	}
	srand(time(NULL));
	int idx = rand()%ukuran;
	printf("! %d\n",ans[idx]); fflush(stdout);
	
	

	return 0;
};