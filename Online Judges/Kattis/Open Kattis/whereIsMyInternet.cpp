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

const int maxn = 2e5 + 5;

vector<vi> AdjList;
bitset<maxn> isVisited;

void dfs(int node) {
	isVisited[node] = true;
	for(int i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		if(!isVisited[v]) {
			dfs(v);
		}
	}
}

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	AdjList.assign(n+1,vi());
	for(i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		AdjList[a].pb(b);
		AdjList[b].pb(a);
	}
	dfs(1);
	bool isAllConnected = true;
	for(i=1;i<=n;i++){
		if(!isVisited[i]){
			printf("%d\n",i);
			isAllConnected = false;
		}
	}
	if(isAllConnected){
		printf("Connected\n");
	}
	return 0;
};