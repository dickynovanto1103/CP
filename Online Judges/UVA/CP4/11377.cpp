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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

void solve(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	bool haveAirport[n+1] = {};
	for(int i=0;i<k;i++){
		int airport;
		scanf("%d",&airport);
		haveAirport[airport] = true;
	}

	vector<vi> adj;
	adj.assign(n+1, vi());
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].pb(b);
		adj[b].pb(a);
	}

	int q;
	scanf("%d",&q);
	while(q--){
		int a,b;
		scanf("%d%d",&a,&b);

		deque<int> q;
		int dist[n+1];
		memset(dist, -1, sizeof dist);

		dist[a] = 0;
		if(!haveAirport[a]) {
			dist[a] = 1;
		}
		q.push_back(a);
		while(!q.empty()){
			int front = q.front(); q.pop_front();
			for(int v: adj[front]) {
				int weight = 0;
				if(!haveAirport[v]) {
					weight = 1;
				}

				if(dist[v] == -1 || dist[v] > dist[front] + weight) {
					dist[v] = dist[front] + weight;
					if(weight == 0) {
						q.push_front(v);
					}else{
						q.push_back(v);
					}
				}
			}
		}

		printf("%d\n", dist[b]);
	}
}

int main(){
	int tc = 1;
	int tt = 1;
	scanf("%d",&tc);
	while(tc--){
		printf("Case %d:\n", tt++);
		solve();
		puts("");
	}

	return 0;
};