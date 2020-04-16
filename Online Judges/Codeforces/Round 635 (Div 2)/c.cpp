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
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

vector<vi> adj;

bool cmp(ii a, ii b){
	return a.first > b.first;
	// if(a.first.first == b.first.first) {
	// 	return a.first.second < b.first.second;
	// }
	// return a.first.first > b.first.first;
}

bool isIndustry[200001];

int sz[200001];

int dfs(int node, int par) {
	sz[node] = 1;
	for(int i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		if(v != par){
			sz[node] += dfs(v, node);
		}
	}
	return sz[node];
}

int main(){
	int n,k,i,j;
	scanf("%d %d",&n,&k);
	adj.assign(n+1,vi());
	for(i=0;i<n-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a].pb(b); adj[b].pb(a);
	}
	int dist[200001];
	for(i=1;i<=n;i++){dist[i] = inf;}
	queue<int> q;
	q.push(1);
	dist[1] = 0;
	
	for(i=1;i<=n;i++){isIndustry[i] = false;}

	while(!q.empty()){
		int front = q.front(); q.pop();
		for(i=0;i<adj[front].size();i++){
			int v = adj[front][i];
			if(dist[v] == inf){
				dist[v] = dist[front] + 1;
				q.push(v);
			}
		}
	}

	dfs(1, -1);

	vii listJarak;
	for(i=1;i<=n;i++){
		// printf("dist[%d]: %d sz[%d]: %d\n",i, dist[i], i, sz[i]);
		int penambahan = dist[i] - ((sz[i] - 1));
		// printf("i: %d penambahan: %d\n",i, penambahan);
		listJarak.pb(ii(penambahan, i));
	}
	sort(listJarak.begin(), listJarak.end(), cmp);
	ll ans = 0;
	for(i=0;i<k;i++){
		int node = listJarak[i].second;
		isIndustry[node] = true;
	}
	q.push(1);
	int banyak[200001];
	for(i=1;i<=n;i++){dist[i] = inf; banyak[i] = 0;}
	if(!isIndustry[1]){banyak[1] = 1;}
	dist[1] = 0;

	while(!q.empty()){
		int front = q.front(); q.pop();
		for(i=0;i<adj[front].size();i++){
			int v = adj[front][i];
			if(dist[v] == inf){
				dist[v] = dist[front] + 1;
				q.push(v);
				if(!isIndustry[v]){
					banyak[v] = banyak[front] + 1;
				}else{
					banyak[v] = banyak[front];
				}
			}
		}
	}

	for(i=0;i<k;i++){
		int node = listJarak[i].second;
		ans += banyak[node];
		// printf("banyak[%d]: %d\n",node, banyak[node]);
	}

	printf("%lld\n",ans);
	return 0;
};