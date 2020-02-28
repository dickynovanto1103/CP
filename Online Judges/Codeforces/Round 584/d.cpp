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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

vector<vi> adj;

bool ada[maxn];
int cnt = 0;
void dfs(int node) {
	int i,j;
	ada[node] = false;
	for(i=0;i<adj[node].size();i++){
		int v = adj[node][i];

		if(ada[v]){
			dfs(v);
			cnt++;
		}
	}
	
}

int main(){
	int n,k,i,j;
	scanf("%d %d",&n,&k);
	ii a[maxn];
	adj.assign(maxn, vi());
	for(i=0;i<k;i++){
		scanf("%d %d",&a[i].first, &a[i].second);
		adj[a[i].first].pb(a[i].second); adj[a[i].second].pb(a[i].first);
	}
	sort(a,a+k);
	
	memset(ada, true, sizeof ada);
	for(i=1;i<=n;i++){
		if(ada[i]){
			dfs(i);
		}
	}
	// printf("cnt: %d\n",cnt);
	printf("%d\n",k-cnt);
	return 0;
};