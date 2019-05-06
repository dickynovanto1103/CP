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
typedef vector<ii> vii;

vector<vi> AdjList, baru, adj;

const int maxn = 1e5 + 5;

int dfsNumberCounter, dfsRoot, rootChildren;
vi dfs_num, dfs_low, dfs_parent, articulation_vertex;
set<ii> s;
set<ii>::iterator it;
int id[maxn];

void articulationPointAndBridge(int u) {
	int j;
	dfs_num[u] = dfs_low[u] = dfsNumberCounter++;
	for(j=0;j<AdjList[u].size();j++) {
		int v = AdjList[u][j];
		if(dfs_num[v] == unvisited) {
			dfs_parent[v] = u;
			if(u == dfsRoot) {rootChildren++;}

			articulationPointAndBridge(v);

			if(dfs_low[v] >= dfs_num[u]) {
				articulation_vertex[u] = true;
			}
			if(dfs_low[v] > dfs_num[u]) {
				s.insert(ii(min(u,v), max(u,v)));
			}
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}else if(v != dfs_parent[u]){
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

void articulationPointAndBridge2(int u) {
	int j;
	// printf("u: %d\n",u);
	dfs_num[u] = dfs_low[u] = dfsNumberCounter++;
	for(j=0;j<baru[u].size();j++) {
		int v = baru[u][j];
		// printf("j: %d v: %d\n",j,v);
		if(dfs_num[v] == unvisited) {

			dfs_parent[v] = u;
			if(u == dfsRoot) {rootChildren++;}
			// printf("hlo\n");
			articulationPointAndBridge2(v);

			if(dfs_low[v] >= dfs_num[u]) {
				articulation_vertex[u] = true;
			}
			if(dfs_low[v] > dfs_num[u]) {
				// printf("edge: %d %d\n",u,v);
				s.insert(ii(min(u,v), max(u,v)));
			}
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}else if(v != dfs_parent[u]){
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

void dfs(int node, int cnt) {
	id[node] = cnt;
	for(int i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		if(id[v] == -1){
			dfs(v, cnt);
		}
	}
}

int dist[2*maxn];

int main(){
	int tc,i,j,n,m;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&m);
		AdjList.assign(n+1, vi());
		memset(id, -1, sizeof id);
		int a[maxn], b[maxn];
		for(i=0;i<m;i++){
			scanf("%d %d",&a[i],&b[i]);
			a[i]--; b[i]--;
			AdjList[a[i]].pb(b[i]); AdjList[b[i]].pb(a[i]);
		}

		dfsNumberCounter = 0; dfs_num.assign(n+1,unvisited); dfs_low.assign(n+1,0);
		dfs_parent.assign(n+1,0); articulation_vertex.assign(n+1,0);
		for(i=0;i<n;i++) {
			if(dfs_num[i] == unvisited) {
				dfsRoot = i; rootChildren = 0; articulationPointAndBridge(i);
				articulation_vertex[dfsRoot] = (rootChildren > 1);
			}
		}
		adj.assign(n+1, vi());
		for(i=0;i<m;i++){
			if(s.find(ii(min(a[i], b[i]), max(a[i], b[i]))) == s.end()){
				adj[a[i]].pb(b[i]);
				adj[b[i]].pb(a[i]);
			}
		}

		
		memset(id, -1, sizeof id);
		int cnt = n;
		for(i=0;i<n;i++){
			if(id[i] == -1){
				dfs(i, cnt);
				cnt++;
			}
		}
		baru.assign(2*n+1, vi());
		for(it=s.begin(); it!=s.end();it++){
			ii pas = *it;
			int x = pas.first, y = pas.second;
			baru[id[x]].pb(id[y]); baru[id[y]].pb(id[x]);
			for(i=0;i<adj[x].size();i++){
				int v = adj[x][i];
				if(id[v] != -1 && id[v] != id[x]) {
					baru[id[x]].pb(id[v]);
					baru[id[v]].pb(id[x]);
				}
			}
			for(i=0;i<adj[y].size();i++){
				int v = adj[y][i];
				if(id[v] != -1 && id[v] != id[y]) {
					baru[id[y]].pb(id[v]);
					baru[id[v]].pb(id[y]);
				}
			}
		}
		// printf("baru:\n");
		// for(i=0;i<2*n;i++){
		// 	printf("i: %d\n",i);
		// 	for(j=0;j<baru[i].size();j++){
		// 		int v = baru[i][j];
		// 		printf(" %d",v);
		// 	}
		// 	printf("\n");
		// }

		for(i=0;i<2*n;i++){
			dist[i] = inf;
		}
		queue<int> q;
		q.push(n);
		dist[n] = 0;
		while(!q.empty()){
			int front = q.front(); q.pop();
			for(i=0;i<baru[front].size();i++){
				int v = baru[front][i];
				if(dist[v] == inf){
					dist[v] = dist[front] + 1;
					q.push(v);
				}
			}
		}
		// for(i=0;i<2*n;i++){
		// 	printf("dist[%d]: %d\n",i,dist[i]);
		// }
		int idx = 0, maks = -1;
		for(i=0;i<2*n;i++){
			if(dist[i] != inf){
				if(maks < dist[i]){
					maks = dist[i];
					idx = i;
				}
			}
		}
		for(i=0;i<2*n;i++){dist[i] = inf;}
		q.push(idx);
		dist[idx] = 0;
		while(!q.empty()){
			int front = q.front(); q.pop();
			for(i=0;i<baru[front].size();i++){
				int v = baru[front][i];
				if(dist[v] == inf){
					dist[v] = dist[front] + 1;
					q.push(v);
				}
			}	
		}
		// printf("kedua\n");
		// for(i=0;i<2*n;i++){
		// 	printf("dist[%d]: %d\n",i,dist[i]);
		// }
		int idx2 = 0; maks = -1;
		for(i=0;i<2*n;i++){
			if(dist[i] != inf){
				if(maks < dist[i]){
					maks = dist[i];
					idx2 = i;
				}
			}
		}
		printf("idx: %d idx2: %d\n",idx, idx2);
		baru[idx2].pb(idx); baru[idx].pb(idx2);
		// printf("idx: %d idx2: %d\n",idx, idx2);
		//find bridge
		s.clear();
		dfsNumberCounter = 0; dfs_num.assign(2*n+1,unvisited); dfs_low.assign(2*n+1,0);
		dfs_parent.assign(2*n+1,0); articulation_vertex.assign(2*n+1,0);
		for(i=n;i<2*n;i++) {
			if(dfs_num[i] == unvisited) {
				// printf("i: %d\n",i);
				dfsRoot = i; rootChildren = 0; articulationPointAndBridge2(i);
				// printf("hlao\n");
				articulation_vertex[dfsRoot] = (rootChildren > 1);
			}
		}
		printf("%d\n",(int)s.size());		

		s.clear();
	}
	return 0;
};