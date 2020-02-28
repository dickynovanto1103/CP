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
typedef vector<ii> vii;

vector<vi> adj;

const int maxn = 2e3 + 3;

int maks = 0;

void dfs(int node, int tinggi) {
	maks = max(maks, tinggi);
	for(int i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		dfs(v, tinggi+1);
	}
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	adj.assign(n+1, vi());
	vi listTua;
	for(i=1;i<=n;i++){
		int parent;
		scanf("%d",&parent);
		if(parent == -1){
			listTua.pb(i);
		}else{
			adj[parent].pb(i);
		}
	}

	for(i=0;i<listTua.size();i++){
		dfs(listTua[i], 1);
	}
	printf("%d\n",maks);

	return 0;
};