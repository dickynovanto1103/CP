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

vi dfs_num, dfs_low, s, visitedNode;
vector<vi> AdjList;
int dfsCounter, numSCC;
vi listAngka;

void tarjan(int u){
	dfs_num[u] = dfs_low[u] = dfsCounter++;
	s.push_back(u);
	visitedNode[u] = visited;
	for(int i=0;i<AdjList[u].size();i++){
		int v = AdjList[u][i];
		if(dfs_num[v]==unvisited) {
			tarjan(v);
		}
		if(visitedNode[v]==visited){
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}	
	}
	if(dfs_num[u] == dfs_low[u]) {
		//printf("SCC %d:",++numSCC);
		int counter = 0;
		while(1){
			int node = s.back(); s.pop_back(); visitedNode[node] = unvisited;
			//printf(" %d",node);
			counter++;
			if(node == u){ break;}
		}
		listAngka.pb(counter);
	}
	
}

int main(){
	int V;
	int i,j;
	scanf("%d",&V);
	AdjList.assign(V+1,vi()); dfs_num.assign(V+1,unvisited); dfs_low.assign(V+1,0); visitedNode.assign(V+1,unvisited);
	for(i=1;i<=V;i++){
		int parent;
		scanf("%d",&parent);
		AdjList[i].pb(parent);
	}

	dfsCounter = numSCC = 0;

	for(i=1;i<=V;i++){
		if(dfs_num[i]==unvisited){
			tarjan(i);
		}
	}
	sort(listAngka.begin(), listAngka.end());
	if(V==1){printf("1\n"); return 0;}
	int cnt = 0, angka = 0;
	bool udah = false;
	while(cnt<2){
		//printf("angka di belakang: %d\n",listAngka.back());
		angka += listAngka.back(); listAngka.pop_back();

		if(listAngka.empty()){	
			udah =true;
			listAngka.pb(angka);
			break;
		}
		cnt++;
	}
	if(!udah){listAngka.pb(angka);}
	ll ans = 0;
	for(i=0;i<listAngka.size();i++){
		//printf("angka: %d\n",listAngka[i]);
		ans+=((ll)listAngka[i]*(ll)listAngka[i]);
	}
	printf("%lld\n",ans);
	return 0;
};