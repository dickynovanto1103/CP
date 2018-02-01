#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vii> AdjList;
vi dist;

int main() {
	int n,m,i,j,u,v,a,b;
	scanf("%d %d",&u,&v);
	scanf("%d %d",&n,&m);
	dist.assign(n+1,inf); AdjList.assign(n+1,vii());
	int w;
	for(i=0;i<m;i++){scanf("%d %d %d",&a,&b,&w); AdjList[a].pb(ii(b,w));}
	dist[u] = 0;
	for(i=0;i<n-1;i++){
		for(int k = 1;k<=n;k++){
			for(j=0;j<AdjList[k].size();j++){
				ii v = AdjList[k][j];
				dist[v.first] = min(dist[v.first],dist[k] + v.second);
			}
		}
	}
	bool hasCycle = false;
	for(int k = 1;k<=n;k++){
		for(j=0;j<AdjList[k].size();j++){
			ii v = AdjList[k][j];
			if(dist[v.first] > dist[k]+v.second){hasCycle = true; break;}
		}
		if(hasCycle){break;}
	}
	if(hasCycle){printf("TIDAK\n");}
	else{printf("BISA\n");}
	return 0;
}