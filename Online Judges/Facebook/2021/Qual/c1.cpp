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
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> adj;

int val[54];
int a[54];

void bfs() {
	queue<int> q;
	q.push(1);
	val[1] = a[1];
	while(!q.empty()) {
		int node = q.front(); q.pop();
		for(int i=0;i<adj[node].size();i++){
			int v = adj[node][i];
			if(val[v] != -1) {continue;}
			val[v] = a[v] + val[node];
			// printf("node: %d, val: %d val[%d] jadi: %d\n", node, val[node], v, val[v]);
			q.push(v);
		}
	}
}

int maks[54];

int dfs(int node, int parent) {
	//leaf
	if(adj[node].size() == 1 && adj[node][0] == parent) {

		return maks[node] = val[node];
	}
	for(int i=0;i<adj[node].size();i++) {
		int v = adj[node][i];
		if(v == parent) {continue;}
		maks[node] = max(maks[node], dfs(v, node));
	}
	return maks[node];
}

bool cmp(int a, int b) {
	return a > b;
}

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ", tt);
		scanf("%d",&n);

		memset(val, -1, sizeof val);
		memset(maks, -1, sizeof maks);

		adj.assign(n+1, vi());
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}

		if(n == 1){
			printf("%d\n", a[1]);
			continue;
		}

		for(i=0;i<n-1;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			adj[x].pb(y); adj[y].pb(x);
		}

		bfs();
		dfs(1, -1);
		// for(i=1;i<=n;i++){
		// 	printf("val[%d]: %d, maks: %d\n", i, val[i], maks[i]);
		// }
		if(adj[1].size() == 1) {
			printf("%d\n", maks[1]);
		}else if(adj[1].size() > 1){
			vi list;
			for(i=0;i<adj[1].size();i++) {
				int v = adj[1][i];
				list.pb(maks[v]);
			}
			sort(list.begin(), list.end(), cmp);
			int ans = list[0] + list[1] - val[1];
			printf("%d\n", ans);
		}else{
			printf("tc: %d, adj size: %d\n", tt, adj[1].size());
			assert(false);
		}
		
	}
	
	return 0;
};