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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

class Solution {
public:
	void solve(vector<vi>& adj, int node) {
		if(!isBip) return;

		for(int i=0;i<adj[node].size();i++){
			int v = adj[node][i];
			if(color[v] == -1) {
				color[v] = 1 - color[node];
				solve(adj, v);
			}

			if(color[node] == color[v]) {
				isBip = false;
				return;
			}
		}
	}

    bool isBipartite(vector<vector<int>>& graph) {
    	isBip = true;
    	memset(color, -1, sizeof color);
    	for(int i=0;i<graph.size();i++) {
    		if(color[i] == -1) {
    			color[i] = 0;
    			solve(graph, i);
    		}
    		
    	}
    	
    	return isBip; 
    }

private:
	bool isBip;
	int color[101];
};

int main(){
	int numNodes;
	while(scanf("%d",&numNodes) != EOF) {
		vector<vi> adj;
		adj.assign(numNodes, vi());
		for(int i=0;i<numNodes;i++){
			int neigh;
			scanf("%d",&neigh);
			for(int j=0;j<neigh;j++){
				int v;
				cin>>v;
				adj[i].pb(v);
			}
		}

		Solution sol;
		cout<<sol.isBipartite(adj)<<endl;
	}
	
	return 0;
};