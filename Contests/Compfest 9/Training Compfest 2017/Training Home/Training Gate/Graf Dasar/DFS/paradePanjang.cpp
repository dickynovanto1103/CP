#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

vector<vii> AdjList;
vi dist, dfs_num;
stack<int> Stack;
void toposort(int awal){
	dfs_num[awal] = visited;
	int i;
	for(i=0;i<AdjList[awal].size();i++){
		ii v = AdjList[awal][i];
		if(dfs_num[v.first]==unvisited){
			toposort(v.first);
		}
	}
	Stack.push(awal);
}

void longestPathInDAG(int awal){
	//reverse(Stack.begin(), Stack.end());
	while(!Stack.empty()){
		int u = Stack.top(); Stack.pop();
		if(dist[u]!=-inf){
			for(int i=0;i<AdjList[u].size();i++){
				ii v = AdjList[u][i];
				if(dist[v.first] < dist[u] + v.second){
					dist[v.first] = dist[u] + v.second;
				}
			}
		}
	}
}

int main() {
	int n,m,i;
	ll u,v,w;
	scanf("%d %d",&n,&m);
	AdjList.assign(n+1,vii());
	dist.assign(n+1,-inf);
	dfs_num.assign(n+1,unvisited);
	for(i=0;i<m;i++){
		scanf("%lld %lld %lld",&u,&v,&w);
		AdjList[u].pb(ii(v,w));
	}
	dist[1]=0;
	for(i=1;i<=n;i++){
		if(dfs_num[i]==unvisited){
			toposort(i);
		}
	}
	longestPathInDAG(1);

	//for(i=1;i<=n;i++){printf("dist[%d]: %lld\n",i,dist[i]);}
	if(dist[n]==-inf){printf("-1\n");}
	else{printf("%lld\n",dist[n]);}
	
	return 0;
}