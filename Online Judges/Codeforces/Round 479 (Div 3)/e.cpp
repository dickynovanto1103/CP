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
bool isVisited[maxn];
bool valid;

void dfs(int node, int parent) {
	// if(!valid){return;}
	isVisited[node] = true;
	if(AdjList[node].size() != 2){valid = false;}
	for(int i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		if(v!=parent && !isVisited[v]){
			dfs(v,node);
		}
	}
}

int main(){
	int n,m,i,j,a,b;
	scanf("%d %d",&n,&m);
	memset(isVisited,false,sizeof isVisited);
	AdjList.assign(n+1,vi());
	for(i=0;i<m;i++){
		scanf("%d %d",&a,&b);
		AdjList[a].pb(b); AdjList[b].pb(a);
	}
	int cnt = 0;
	for(i=1;i<n;i++){
		if(!isVisited[i]) {
			valid = true;
			dfs(i,-1);
			if(valid){cnt++;}
		}
	}
	printf("%d\n",cnt);
	return 0;
};