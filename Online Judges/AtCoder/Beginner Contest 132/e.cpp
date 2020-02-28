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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> AdjList, adj;
int dist[100010];
queue<int> q;

void dfs(int node, int dalam, int nextJarak) {
	// printf("node: %d dalam: %d\n",node, dalam);
	if(dalam == 3){
		if(dist[node] == inf){
			dist[node] = nextJarak;
			q.push(node);
		}
		return;
	}else if(dalam > 3){
		return;
	}
	for(int i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		dfs(v, dalam+1, nextJarak);
	}
}

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	AdjList.assign(n+1, vi());
	adj.assign(n+1, vi());
	for(i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		AdjList[a].pb(b);
	}
	int s,t;
	scanf("%d %d",&s,&t);
	for(i=1;i<=n;i++){dist[i] = inf;}
	
	dist[s] = 0;
	q.push(s);
	vi listBil;
	int iterasi = 1;
	while(true) {
		listBil.clear();
		while(!q.empty()){
			int front = q.front(); q.pop();
			listBil.pb(front);
		}
		for(i=0;i<listBil.size();i++){
			int bil = listBil[i];
			dfs(bil, 0, iterasi);
		}
		iterasi++;
		if(q.empty()){break;}
	}
	
	
	if(dist[t] == inf){
		printf("-1\n");
	}else{
		printf("%d\n",dist[t]);
	}
	return 0;
};