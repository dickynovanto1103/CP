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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e3 + 3;

int tin[maxn], tout[maxn], waktu, batasAtas;

vector<vi> up, AdjList;

bool isAncestor(int u, int v) {
	return tin[u] <= tin[v] && tout[v] <= tout[u];
}

void dfs(int u, int p){
	int i;

	tin[u] = waktu++;
	
	up[u][0] = p;
	for(i=1;i<=batasAtas;i++){
		up[u][i] = up[up[u][i-1]][i-1];
	}

	for(i=0;i<AdjList[u].size();i++){
		int v = AdjList[u][i];
		if(v!=p){
			dfs(v, u);
		}
	}

	tout[u] = waktu++;
}

int lca(int a, int b){
	if(isAncestor(a,b)){return a;}
	if(isAncestor(b,a)){return b;}
	for(int i=batasAtas;i>=0;i--){
		if(!isAncestor(up[a][i], b)) {
			a = up[a][i];
		}
	}
	return up[a][0];
}


void preprocess() {
	waktu = 1;
	batasAtas = ceil(log2(maxn));
	up.assign(maxn, vi(batasAtas+1));
	dfs(1,1);
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case %d:\n",tt);
		int n;
		scanf("%d",&n);
		AdjList.assign(maxn, vi());
		for(i=1;i<=n;i++){
			int banyak;
			scanf("%d",&banyak);
			for(j=0;j<banyak;j++){
				int a;
				scanf("%d",&a);
				AdjList[i].pb(a); AdjList[a].pb(i);
			}
		}
		preprocess();
		// for(i=1;i<=n;i++){
		// 	for(j=0;j<=batasAtas;j++){
		// 		printf("up[%d][%d]: %d\n",i,j,up[i][j]);
		// 	}
		// }
		int q;
		scanf("%d",&q);

		while(q--){
			int a,b;
			scanf("%d %d",&a,&b);
			int nodeLCA = lca(a,b);
			printf("%d\n",nodeLCA);
		}

	}
	return 0;
};