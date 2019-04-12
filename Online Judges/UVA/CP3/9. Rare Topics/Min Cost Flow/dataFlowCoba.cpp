#include <bits/stdc++.h>

using namespace std;
#define inf 1e18
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> ii;
typedef pair<ii,ll> iii;
typedef vector<ii> vii;

struct Edge {
  int from, to;
  ll cap, flow, cost;
  Edge(int from, int to, ll cap, ll flow, ll cost) :
    from(from), to(to), cap(cap), flow(flow), cost(cost) {}
};

struct MCMF {
  int n, s, t;
  vector< vector< int > > adj;
  vector< int > par;
  vector< Edge > vEdge;
  vector< long long > dist;
  MCMF(int _n, int _s, int _t) : n(_n), adj(n), s(_s), t(_t) {
  }
  void addEdge(int from, int to, int cap, int cost) {
    adj[from].push_back(vEdge.size());
    adj[to].push_back(vEdge.size());
    vEdge.push_back(Edge(from, to, cap, 0, cost));
  }
  long long augment(int v, ll minflow = inf) {
    if(v == s) {
      return minflow;
    }
    if(par[v] < 0) {
      return 0;
    }
    long long flow;
    Edge &e = vEdge[par[v]];
    if(v == e.from) {
      flow = augment(e.to, min(minflow, e.flow));
      e.flow -= flow;
    }
    else {
      flow = augment(e.from, min(minflow, e.cap - e.flow));
      e.flow += flow;
    }
    return flow;
  }
  long long findingPath() {
    //dijkstra
    set< pair< long long , int > > st;
    dist.assign(n, inf);
    par.assign(n, -1);
    dist[s] = 0;
    st.insert(make_pair(dist[s], s));
    while(!st.empty()) {
      set< pair< long long, int > >::iterator begin = st.begin();
      int v = begin->second;
      st.erase(begin);
      for(int i = 0; i<adj[v].size(); i++) {
        Edge &e = vEdge[adj[v][i]];
        if(e.from == v) {
          if(e.cap > e.flow && dist[e.to] > dist[v] + e.cost) {
            st.erase(make_pair(dist[e.to], e.to));
            dist[e.to] = dist[v] + e.cost;
            st.insert(make_pair(dist[e.to], e.to));
            par[e.to] = adj[v][i];
          }
        }
        else {
          if(e.flow > 0 && dist[e.from] > dist[v] - e.cost) {
            st.erase(make_pair(dist[e.from], e.from));
            dist[e.from] = dist[v] - e.cost;
            st.insert(make_pair(dist[e.from], e.from));
            par[e.from] = adj[v][i];
          }
        }
      }
    }
    return augment(t, inf);
  }
  pair< long long, long long > EdmondKarp() {
    long long maxflow = 0, mincost = 0;
    long long flow;
    while(flow = findingPath()) {
      maxflow += flow;
      mincost += flow * dist[t];
    }
    return make_pair(mincost, maxflow);
  }
};

int main(){
	int n,m,i,j;
	while(scanf("%d %d",&n,&m)!=EOF){
		MCMF mcmf(n+1, 0, n);
		vector<iii> v;
		for(i=0;i<m;i++){
			int a,b;
			ll c;
			scanf("%d %d %lld",&a,&b,&c);
			v.pb(iii(ii(a,b), c));
		}
		ll d,k;
		scanf("%lld %lld",&d,&k);
		for(i=0;i<v.size();i++){
			mcmf.addEdge(v[i].first.first, v[i].first.second, k, v[i].second);
			printf("ditambah edge: %lld %lld dengan kapasitas: %lld cost: %lld\n",v[i].first.first, v[i].first.second, k, v[i].second);
		}
		mcmf.addEdge(0,1,d,0);
		printf("ditambah %d %d %d %d\n",0,1,d,0);
		ii ans = mcmf.EdmondKarp();
		printf("first: %lld\n",ans.first);
		if(ans.first == d){printf("%lld\n",ans.second);}
		else{printf("Impossible.\n");}
	}
	return 0;
};