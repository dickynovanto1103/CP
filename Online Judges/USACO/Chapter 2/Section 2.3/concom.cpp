/*
ID: dickyno1
LANG: C++14
TASK: concom
*/

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

vector<vii> adj(101);
int percentage[101];
bool vis[101];

vector<vi> ans(101);

void bfs(int node) {
	queue<int> q;
	vis[node] = true;
	q.push(node);
	while(!q.empty()) {
		int curr = q.front(); q.pop();
		for(int i=0;i<adj[curr].size();i++){
			ii pas = adj[curr][i];
			int v = pas.first, p = pas.second;

			percentage[v] += p;
			// printf("node: %d v: %d p: %d cur percentage of v: %d\n", node, v, p, percentage[v]);
			if(percentage[v] > 50 && !vis[v]){
				q.push(v);
				ans[node].pb(v);
				vis[v] = true;
				// printf("for node: %d pushed: %d\n", node, v);
			}
		}
	}
}

int main(){
	freopen("concom.in", "r", stdin);
	freopen("concom.out", "w", stdout);

	int numRecords, i,j;
	scanf("%d",&numRecords);
	int maksNode = 0;
	for(i=0;i<numRecords;i++){
		int a, b, p;
		scanf("%d %d %d",&a,&b,&p);
		adj[a].pb(ii(b, p));
	}

	for(int i=1;i<=100;i++){
		memset(percentage, 0, sizeof percentage);
		memset(vis, false, sizeof vis);
		bfs(i);
	}

	for(int i=1;i<=100;i++){
		sort(ans[i].begin(), ans[i].end());
		for(int j=0;j<ans[i].size();j++){
			printf("%d %d\n", i, ans[i][j]);
		}
	}
	
	return 0;
};