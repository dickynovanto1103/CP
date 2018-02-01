#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vii> AdjList;

int main() {
	int tc,i,j,a,b,n,m,w;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %d %d",&n,&m,&a,&b);
		AdjList.assign(n+1,vii());
		vi dist;
		dist.assign(n+1,inf);
		for(i=0;i<m;i++){
			int u,v,w1,w2;
			scanf("%d %d %d %d",&u,&v,&w1,&w2);
			int berat = w1*a + w2*b;
			AdjList[u].pb(ii(v,berat)); AdjList[v].pb(ii(u,berat));
		}
		int x,y;
		scanf("%d %d",&x,&y);
		dist[x] = 0;
		priority_queue <ii,vii, greater<ii> > pq; pq.push(ii(dist[x],x));
		while(!pq.empty()){
			ii front = pq.top(); pq.pop();
			int d = front.first, u = front.second;
			if(d > dist[u]){continue;}
			for(i=0;i<AdjList[u].size();i++){
				ii v = AdjList[u][i];
				if(dist[v.first] > dist[u] + v.second){
					dist[v.first] = dist[u] + v.second;
					pq.push(ii(dist[v.first],v.first));
				}
			}
		}
		printf("%d\n",dist[y]);
		AdjList.clear();
	}
	return 0;
}