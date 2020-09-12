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
int in[100001];
int label[100001];
int angka;
vi topo;
int vis[100001];
priority_queue<int, vi, greater<int> > pq;

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	adj.assign(n+1, vi());
	for(i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		// printf("a: %d b: %d\n",a,b);
		adj[a].pb(b);
		in[b]++;
	}
	memset(vis, false, sizeof vis);

	for(i=1;i<=n;i++){
		if(in[i] == 0 && !vis[i]){
			pq.push(i);
		}
	}
	while(!pq.empty()){
		int node = pq.top(); pq.pop();
		vis[node] = true;
		label[node] = ++angka;
		for(i=0;i<adj[node].size();i++){
			int v = adj[node][i];
			in[v]--;
			if(in[v] == 0 && !vis[v]) {
				pq.push(v);
			}
		}
	}
	// reverse(topo.begin(), topo.end());
	// for(i=0;i<topo.size();i++){
	// 	label[topo[i]] = i + 1;
	// 	// printf("%d ",topo[i]);
	// }
	// printf("\n");
	for(i=1;i<=n;i++){
		for(j=0;j<adj[i].size();j++){
			int v= adj[i][j];
			assert(label[i] < label[v]);
		}
	}
	set<int> ans;

	for(i=1;i<=n;i++){
		// printf("label[%d]: %d\n", i, label[i]);
		assert(label[i] != 0 && label[i] <= n);
		ans.insert(label[i]);
		if(i>1){printf(" ");}
		printf("%d",label[i]);
	}
	printf("\n");
	assert(ans.size() == n);
	
	return 0;
};