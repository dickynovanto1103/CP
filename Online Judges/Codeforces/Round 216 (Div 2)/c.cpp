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

vector<vii> adj;

const int maxn = 1e5 + 5;

int cnt[maxn];
bool vis[maxn];
int parent[maxn];
set<ii> s;

void dfs(int node, int p, int banyak) {
	cnt[node] = banyak;
	parent[node] = p;
	for(int i=0;i<adj[node].size();i++){
		ii pas = adj[node][i];
		int v = pas.first, rusak = pas.second;
		if(v != p){
			if(rusak){
				dfs(v, node, banyak + 1);
			}else{
				dfs(v, node, banyak);
			}
		}
	}
}

bool process(int node) {
	bool ada = false;
	
	while(parent[node] != -1 && !vis[node]) {
		vis[node] = true;
		if(s.find(ii(parent[node], node)) != s.end()){
			s.erase(ii(parent[node], node)); s.erase(ii(node, parent[node]));
			ada = true;
		}
		node = parent[node];
	}
	return ada;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	adj.assign(n+1, vii());
	
	for(i=0;i<n-1;i++){
		int x,y,t;
		scanf("%d %d %d",&x,&y,&t);
		adj[x].pb(ii(y,t-1)); adj[y].pb(ii(x,t-1));
		if(t == 2){
			s.insert(ii(x,y)); s.insert(ii(y,x));
		}
	}
	memset(vis, false, sizeof vis);
	dfs(1,-1,0);
	priority_queue<ii> pq;
	for(i=1;i<=n;i++){
		pq.push(ii(cnt[i], i));
	}
	vi ans;
	while(!pq.empty()) {
		ii front = pq.top(); pq.pop();
		int node = front.second;
		if(process(node)) {
			ans.pb(node);
		}
	}
	int ukuran = ans.size();
	printf("%d\n",ukuran);
	for(i=0;i<ukuran;i++){
		if(i){printf(" ");}
		printf("%d",ans[i]);
	}
	printf("\n");
	return 0;
}; 