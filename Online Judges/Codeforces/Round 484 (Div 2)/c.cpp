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

const int maxn = 1e5 + 4;
vector<vi> AdjList;

int banyakNode[maxn];
bool isVisited[maxn];

int dfs(int u) {
	isVisited[u] = true;
	int ans = 1;
	// printf("u: %d\n", u);
	for(int i=0;i<AdjList[u].size();i++){
		int v = AdjList[u][i];
		// printf("v: %d\n", v);
		if(!isVisited[v]) {
			ans+=dfs(v);
		}
	}
	// printf("banyakNode[%d]: %d\n",u, banyakNode[u]);
	return banyakNode[u] = ans;
}

int ans = 0;

void cari(int node) {
	isVisited[node] = true;
	for(int i=0;i<AdjList[node].size();i++){
		int v =AdjList[node][i];
		if(!isVisited[v]) {
			if(banyakNode[v] % 2 == 0) {
				ans++;
			}
			cari(v);
		}
	}
}

int main(){
	int n,i,j;
	int a,b;	
	scanf("%d",&n);
	if(n%2==1){printf("-1\n"); return 0;}
	AdjList.assign(n+1,vi());
	for(i=0;i<(n-1);i++){
		scanf("%d %d",&a,&b);
		AdjList[a].pb(b);
		AdjList[b].pb(a);
	}
	memset(isVisited,false,sizeof isVisited);
	memset(banyakNode, 0,sizeof banyakNode);
	dfs(1);
	// for(i=1;i<=n;i++){
	// 	printf("banyakNode[%d]: %d\n", i, banyakNode[i]);
	// }
	memset(isVisited, false, sizeof isVisited);
	cari(1);
	printf("%d\n",ans);
	return 0;
};