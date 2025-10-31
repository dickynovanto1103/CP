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
#define memory() cerr<<abs(&M2-&M1)/1024.0/1024<<" MB"<<endl

vector<vi> adj;

struct Data {
	int from, to, dist;
};

ii dist[200010][2]; //{from, real dist};

void solve(){
	int n,m;
	int tt = 1;
	while(scanf("%d %d",&n,&m) != EOF) {
		if(tt>1) {
			puts("");
		}
		tt++;
		adj.assign(n+1, vi());
		for(int i=0;i<n+1;i++){
			for(int j=0;j<2;j++){
				dist[i][j] = ii(-1,-1);
			}
		}

		for(int i=0;i<m;i++){
			int a, b;
			scanf("%d %d",&a,&b);
			adj[a].pb(b); adj[b].pb(a);
		}

		string s;
		cin>>s;

		queue<Data> q;
		for(int i=0;i<s.size();i++){
			if(s[i] == 'S') {
				q.push({i+1, i+1, 0});
				dist[i+1][0] = ii(i+1, 0);
			}
		}

		while(!q.empty()) {
			Data d = q.front(); q.pop();
			int from = d.from, to = d.to, jarak = d.dist;
			for(int i=0;i<adj[to].size();i++){
				int v = adj[to][i];
				if(dist[v][0] == ii(-1,-1)) {
					dist[v][0] = ii(from, jarak + 1);
					q.push({from, v, jarak + 1});
					//check yg pertama apakah dari from, if yes, don't process, we want different node...as this is the requirement of the problem
				}else if(dist[v][0].first != from && dist[v][1] == ii(-1,-1)){
					dist[v][1] = ii(from, jarak + 1);
					q.push({from, v, jarak + 1});
				}
			}
		}

		for(int i=0;i<s.size();i++){
			if(s[i] == 'D') {
				assert(dist[i+1][0].first != dist[i+1][1].first);
				printf("%d\n", dist[i+1][0].second + dist[i+1][1].second);
			}
		}
	}
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};