#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000000000LL
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,ll> ii;
typedef vector<ii> vii;

vector<vii> AdjList;
vi dist;

int main() {
	int n,m,i,j,a,b;
	ll w;
	scanf("%d %d",&n,&m);
	AdjList.assign(n+1,vii()); dist.assign(n+1,inf);
	for(i=0;i<m;i++){scanf("%d %d %lld",&a,&b,&w); AdjList[a].pb(ii(b,w)); AdjList[b].pb(ii(a,w));}
	dist[1] = 0; 
	priority_queue<ii,vii,greater<ii> > pq; pq.push(ii(1,0LL));
	while(!pq.empty()){
		ii front = pq.top(); pq.pop();
		int node = front.first;
		ll berat = front.second;
		if(dist[node] < berat){continue;}
		for(i=0;i<AdjList[node].size();i++){
			ii v = AdjList[node][i];
			if(dist[v.first] > dist[node] + v.second){
				dist[v.first] = dist[node] + v.second;
				pq.push(ii(v.first,dist[v.first]));
			}
		}
	}
	printf("%lld\n",dist[n]);
	return 0;
}