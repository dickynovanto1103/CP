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

const int maxn = 1010;

vector<vi> AdjList;

vi match, vis;

int Aug(int node) {
	if(vis[node]){return 0;}
	vis[node] = 1;
	for(int i=0;i<AdjList[node].size();i++) {
		int v = AdjList[node][i];
		if(match[v] == -1 || Aug(match[v])) {
			match[v] = node; return 1; // found 1 matching
		}
	}
	return 0; //no matching
}

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	AdjList.assign(maxn, vi());
	for(i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		AdjList[a].pb(b+n);
		AdjList[b].pb(a+n);
	}

	int mcbm = 0;
	match.assign(2*maxn,-1);
	for(i=1;i<=n;i++){
		vis.assign(2*maxn,0);
		mcbm+=Aug(i);
	}
	// printf("mcbm; %d\n",mcbm);
	int pasangan[maxn];
	memset(pasangan, -1, sizeof pasangan);
	if(mcbm == n){
		for(i=n+1;i<=n+n;i++){
			if(match[i] == -1){
				continue;
			}
			int idx = i%n;
			if(idx == 0){idx+=n;}

			pasangan[idx] = match[i];
		}
		
		for(i=1;i<=n;i++){
			printf("%d\n",pasangan[i]);
			if(pasangan[i] == i){assert(false);}
		}
	}else{
		printf("Impossible\n");
	}
	
	return 0;
};