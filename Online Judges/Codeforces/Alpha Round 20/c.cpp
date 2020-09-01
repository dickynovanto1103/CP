#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000LL
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

vector<vii> adj;
ll dist[100001];

bool done;
vi traceResult;

void trace(int node) {
	if(done){return;}

	traceResult.pb(node);
	if(node == 1){
		done = true;
		return;
	}
	
	for(int i=0;i<adj[node].size();i++){
		ii v = adj[node][i];
		ll tetangga = v.first, jarak = v.second;
		if(dist[tetangga] == (dist[node] - jarak)) {
			trace(tetangga);
		}
	}
}

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++){dist[i] = inf*inf;}
	adj.assign(n+1, vii());
	for(i=0;i<m;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		adj[a].pb(ii(b,c));
		adj[b].pb(ii(a,c));
	}
	priority_queue<ii, vii, greater<ii> > pq;
	dist[1] = 0;
	pq.push(ii(dist[1], 1));
	while(!pq.empty()){
		ii front = pq.top(); pq.pop();
		ll jarak = front.first; int node = front.second;
		if(dist[node] < jarak){continue;}
		for(i=0;i<adj[node].size();i++){
			ii v = adj[node][i];
			int tetangga = v.first, w = v.second;
			if(dist[tetangga] > (dist[node] + w)){
				dist[tetangga] = dist[node] + w;
				pq.push(ii(dist[tetangga], tetangga));
			}
		}
	}

	if(dist[n] == inf*inf) {
		printf("-1\n");
		return 0;
	}
	trace(n);
	reverse(traceResult.begin(), traceResult.end());
	for(i=0;i<traceResult.size();i++){
		if(i){printf(" ");}
		printf("%d",traceResult[i]);
	}
	printf("\n");
	
	return 0;
};