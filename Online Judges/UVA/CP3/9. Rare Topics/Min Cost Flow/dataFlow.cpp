#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000000000000LL
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

struct Edge {
	int from, to, capacity, cost;
	Edge(int from, int to, int capacity, int cost) : from(from), to(to), capacity(capacity), cost(cost) {}
};

vector<vi> AdjList, cost, capacity;

void shortest_path(int n, int v0, vi& dist, vi& p) {
	dist.assign(n,inf);
	dist[v0] = 0;
	priority_queue<ii,vii,greater<ii> > pq;
	pq.push(ii(dist[v0],v0));
	p.assign(n,-1);
	while(!pq.empty()){
		ii front = pq.top(); pq.pop();
		ll u = front.second, jarak = front.first;
		if(jarak > dist[u]){continue;}
		for(int i=0;i<AdjList[u].size();i++){
			int v = AdjList[u][i];
			if(capacity[u][v] > 0 && dist[v] > (dist[u] + cost[u][v])) {
				dist[v] = dist[u] + cost[u][v];
				p[v] = u;
				pq.push(ii(dist[v],v));
			}
		}
	}
	// d.assign(n,inf);
	// d[v0] = 0;
	// vector<int> m(n,2);
	// deque<int> q;
	// q.pb(v0);
	// p.assign(n,-1);

	// while(!q.empty()) {
	// 	int u = q.front(); q.pop_front();
	// 	m[u] = 0;
	// 	for(int v : AdjList[u]) {
	// 		if(capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
	// 			d[v] = d[u] + cost[u][v];
	// 			p[v] = u;
	// 			if(m[v] == 2){
	// 				m[v] = 1;
	// 				q.pb(v);
	// 			}else if(m[v] == 0){
	// 				m[v] = 1;
	// 				q.push_front(v);
	// 			}
	// 		}
	// 	}
	// }
}

ll min_cost_flow(int N, vector<Edge> edges, ll K, int s, int t) {
	AdjList.assign(N, vi());
	cost.assign(N,vi(N,0));
	capacity.assign(N, vi(N,0));
	for(Edge e: edges) {
		AdjList[e.from].pb(e.to);
		AdjList[e.to].pb(e.from);
		cost[e.from][e.to] = e.cost;
		cost[e.to][e.from] = -e.cost;
		capacity[e.from][e.to] = e.capacity;
	}

	ll flow = 0;
	ll cost = 0;
	vi d,p;
	while(flow < K) {
		shortest_path(N,s,d,p);
		if(d[t] == inf)
			break;
		//find max flow on that path
		ll f = K - flow;
		int cur = t;
		while(cur != s) {
			f = min(f, capacity[p[cur]][cur]);
			cur = p[cur];
		}

		//apply flow
		flow += f;
		cost += f*d[t];
		cur = t;
		while(cur != s) {
			capacity[p[cur]][cur] -= f;
			capacity[cur][p[cur]] += f;
			// printf("capacity[%d][%d] jadi %d dan capacity[%d][%d] jadi %d\n",p[cur], cur, capacity[p[cur]][cur], cur,p[cur], capacity[cur][p[cur]]);
			cur = p[cur];
		}
	}
	// printf("flow: %lld K: %lld\n",flow, K);
	if(flow != K) {
		return -1;
	}else{
		return cost;
	}
}

int main(){
	int n,m,i,j;
	while(scanf("%d %d",&n,&m) != EOF) {
		vector<Edge> edgeList;
		for(i=0;i<m;i++){
			int u,v,w;
			scanf("%d %d %d",&u,&v,&w);
			edgeList.pb(Edge(u,v,0,w));

		}

		ll neededFlow,cap;
		scanf("%lld %lld",&neededFlow, &cap);
		edgeList.pb(Edge(0,1,cap,0));
		edgeList.pb(Edge(n,n+1,cap,0));
		for(int i = 0; i < edgeList.size();i++){
			edgeList[i].capacity = cap;

		}
		// for(Edge e: edgeList) {
		// 	printf("%d %d %d %d\n",e.from, e.to, e.capacity, e.cost);
		// }

		ll ans = min_cost_flow(n+5,edgeList,neededFlow,1,n);
		if(ans == -1){printf("Impossible.\n");}
		else{printf("%lld\n", ans);}
		AdjList.clear(); cost.clear(); capacity.clear();
	}
	return 0;
};