#include <bits/stdc++.h>

using namespace std;

#define inf 2000000000
#define pb push_back
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ii> vii;

vector<vii> adj;
bool isBigNode[200010];
int nodeIdx[200010];
ll maxPassangers[450][200000];

void traverse(int node, int par, int root, int depth, int prevNum) {
	if(depth >= 2) return;
	for(int i=0;i<adj[node].size();i++) {
		ii v = adj[node][i];
		int neigh = v.first, w = v.second;
		if(neigh == par) continue;

		int add = min(prevNum, w);
		maxPassangers[nodeIdx[root]][neigh] += add;
		traverse(neigh, node, root, depth + 1, add);
	}
}

void processAllBigNodes(int numNodes, int numEdges) {
	int limit = (int)sqrt(numEdges);
	int idx = 0;
	for(int i=1;i<=numNodes;i++){
		if(adj[i].size() > limit) {
			isBigNode[i] = true;
			nodeIdx[i] = idx++;

			traverse(i, -1, i, 0, inf);
		}
	}
}

ll processSmallNodes(int a, int b) {
	map<int,int> mapper;
	for(int i=0;i<adj[a].size();i++){
		ii v = adj[a][i];
		int neigh = v.first, w = v.second;
		mapper[neigh] = w;
	}

	ll ans = 0;
	for(int i=0;i<adj[b].size();i++) {
		ii v = adj[b][i];
		int neigh = v.first, w = v.second;
		if(mapper.find(neigh) != mapper.end()) {
			ans += min(mapper[neigh], w);
		}

		if(neigh == a) ans += w * 2;
	}

	return ans;
}

int main() {
	int tc;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d:", tt);

		int n,m,q;
		scanf("%d %d %d",&n,&m,&q);
		adj.assign(n+1, vii());
		for(int i=1;i<=n;i++){
			isBigNode[i] = false;
			for(int j=0;j<450;j++) {
				maxPassangers[j][i] = 0;
			}
		}
		for(int i=0;i<m;i++){
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			adj[a].pb(ii(b, c)); adj[b].pb(ii(a, c));
		}

		//process which one is big nodes

		while(q--){
			int a,b;
			scanf("%d %d",&a,&b);
			if(isBigNode[a] || isBigNode[b]) {
				if(isBigNode[a]) {
					printf(" %lld", maxPassangers[nodeIdx[a]][b]);
				}else{
					printf(" %lld", maxPassangers[nodeIdx[b]][a]);
				}
			}else{
				//2 small nodes
				printf(" %lld", processSmallNodes(a, b));

			}
		}
		puts("");
	}

	return 0;
}