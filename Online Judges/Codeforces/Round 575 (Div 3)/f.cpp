#include <bits/stdc++.h>

using namespace std;
#define inf 1e15
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef pair<ll, ii> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

vector<vii> adj;

const int maxn = 2e5 + 5;
int mapper[maxn], invMap[maxn];
ll dist[maxn];
int cnt = 0;

vi listAns;

int dijkstra(int n) {
	int i,j;
	priority_queue<ii,vii, greater<ii> > pq;
	int mapping = mapper[n];
	for(i=0;i<cnt;i++){
		dist[i] = inf;
	}
	dist[mapping] = 0;
	pq.push(ii(dist[mapping], n));
	while(!pq.empty()){
		ii front = pq.top(); pq.pop();
		ll weight = front.first, node = front.second;
		int mappingNode = mapper[node];
		if(weight > dist[mappingNode]){continue;}
		for(i=0;i<adj[node].size();i++){
			ii v = adj[node][i];
			int tetangga = v.first;
			int mappingTetangga = mapper[tetangga];
			
			ll w = v.second;
			ll calon = dist[mappingNode] + w;
			if(calon < dist[mappingTetangga]) {
				dist[mappingTetangga] = calon;
				pq.push(ii(dist[mappingTetangga], tetangga));
			}
		}
	}
	int ans = 0;
	for(i=0;i<cnt;i++){
		int node = invMap[i];
		if(node > n){
			listAns.pb(dist[i]);
		}
	}
	return ans;
}

int main(){
	int n,m,k,i,j;
	scanf("%d %d %d",&n,&m,&k);
	adj.assign(maxn, vii());
	vi listBil;
	int x[maxn], y[maxn], w[maxn];
	viii edgeList;
	for(i=0;i<m;i++){
		scanf("%d %d %d",&x[i],&y[i],&w[i]);
		edgeList.pb(iii(w[i], ii(x[i], y[i])));
		listBil.pb(w[i]);
	}
	sort(edgeList.begin(), edgeList.end());
	sort(listBil.begin(), listBil.end());
	k--;

	int maksEdge = listBil[min(k, m-1)];
	memset(mapper, -1, sizeof mapper);
	// int cnt = 0;
	for(i=0;i<m;i++){
		iii pas = edgeList[i];
		ll w = pas.first, x = pas.second.first, y = pas.second.second;
		if(w <= maksEdge) {
			adj[x].pb(ii(y, w)); adj[y].pb(ii(x, w));
			if(mapper[x] == -1){
				invMap[cnt] = x;
				mapper[x] = cnt++;
			}
			if(mapper[y] == -1){
				invMap[cnt] = y;
				mapper[y] = cnt++;
			}
			if(cnt >= 800){break;}
		}
	}
	// assert(cnt <= 10000);
	for(i=0;i<cnt;i++){
		int node = invMap[i];
		dijkstra(node);
	}
	sort(listAns.begin(), listAns.end());
	// for(i=0;i<listAns.size();i++){
	// 	printf("%lld ",listAns[i]);
	// }
	// printf("\n");
	assert(listAns.size() >= (k+1));
	printf("%lld\n",listAns[k]);
	return 0;
};