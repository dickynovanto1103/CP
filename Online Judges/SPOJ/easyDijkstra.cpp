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

const int maxn = 10010;

vector<vii> AdjList;

int main(){
	int k,n,m,o,i,j;
	int tc;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&m);
		AdjList.assign(maxn, vii());
		ll dist[maxn];
		
		for(i=0;i<m;i++){
			int a,b,w;
			scanf("%d %d %d",&a,&b,&w);
			AdjList[a].pb(ii(b,w));
			// AdjList[b].pb(ii(a,w));
		}

		int a,b;
		scanf("%d %d",&a,&b);
		// fill(dist, dist+maxn, inf);
		memset(dist, -1, sizeof dist);
		priority_queue<ii, vii, greater<ii> > pq;
		dist[a] = 0;
		pq.push(ii(dist[a], a));
		while(!pq.empty()){
			ii front = pq.top(); pq.pop();
			int jarak = front.first, node = front.second;
			
			if(jarak > dist[node]){continue;}

			for(i=0;i<AdjList[node].size();i++){
				ii v = AdjList[node][i];
				if(dist[v.first] == -1 || dist[v.first] > (dist[node] + v.second)){
					dist[v.first] = dist[node] + v.second;
					pq.push(ii(dist[v.first], v.first));
				}
			}
		}
		if(dist[b] == -1){
			printf("NO\n");
		}else{
			printf("%lld\n",dist[b]);	
		}
		AdjList.clear();
	}
	
	
	return 0;
};