#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define explored 2
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e3 + 2;

vector<vi> AdjList;
bool cycleFound;
int dfs_num[maxn], p[maxn], nodeAwalCycle;
int panjangCycle;


void dfs(int node, int parent) {
	if(cycleFound){return;}
	dfs_num[node] = explored;
	// printf("node: %d parent: %d\n",node,parent);
	for(int i=0;i<AdjList[node].size();i++) {
		int v = AdjList[node][i];

		if(v==parent){continue;}
		
		// printf("v: %d\n",v);
		if(cycleFound){return;}
		p[v] = node;
		// printf("p[%d] diassign %d waktu node: %d\n",v,p[v],node);
		if(dfs_num[v] == unvisited) {
			dfs(v,node);
		}
		if(cycleFound){return;}

		if(dfs_num[v] == explored){
			cycleFound = true;
			nodeAwalCycle = v;
			return;
			// printf("nodeAwalCycle: %d\n",nodeAwalCycle);
		}
	}
	dfs_num[node] = visited;
}

set<int> s;

void cariElemenCycle(int node) {
	s.insert(node);
	if(p[node]!=nodeAwalCycle) {
		cariElemenCycle(p[node]);
	}
}

int dist[maxn];

void bfs(int node, int parent, int jarak) {
	dist[node] = jarak;
	for(int i=0;i<AdjList[node].size();i++) {
		int v = AdjList[node][i];
		if(v==parent){continue;}
		if(s.find(v) == s.end()) {
			bfs(v, node, jarak+1);	
		}
		
	}
}

int main(){
	int tc,i,j,n;
	int a,b;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++) {
		printf("Case #%d:",tt);
		scanf("%d",&n);
		AdjList.assign(n+1,vi());
		memset(p,-1,sizeof p);

		for(i=0;i<n;i++) {
			scanf("%d %d",&a,&b);
			AdjList[a].pb(b); AdjList[b].pb(a);	
		}
		memset(dfs_num,-1,sizeof dfs_num);
		cycleFound = false;
		dfs(1,-1);
		
		cariElemenCycle(nodeAwalCycle);

		set<int>::iterator it;
		memset(dist,0,sizeof dist);
		for(it = s.begin(); it!=s.end();it++){
			// printf("%d\n",*it);
			int node = *it;
			for(i=0;i<AdjList[node].size();i++){
				int v = AdjList[node][i];
				if(s.find(v) != s.end()){continue;}
				//iterasi
				bfs(v,-1,1);
			}
		}

		for(i=1;i<=n;i++){
			printf(" %d",dist[i]);
		}
		printf("\n");

		AdjList.clear();
		s.clear();
	}
	return 0;
}; 