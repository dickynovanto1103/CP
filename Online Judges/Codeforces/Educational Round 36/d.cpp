#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define explored 2
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> AdjList;
vi dfs_num;
bool foundCycle;
const int maxn = 1e5 + 1;

void graphCheck(int u){
	if(foundCycle){return;}
	dfs_num[u] = explored;
	for(int i=0;i<AdjList[u].size();i++){
		int v = AdjList[u][i];
		if(dfs_num[v] == unvisited){
			graphCheck(v);
		}
		if(dfs_num[v] == explored){
			// printf("ketemu cycle saat u: %d v: %d\n",u,v);
			foundCycle = true;
		}
	}
	dfs_num[u] = visited;
}

void graphCheckKhusus(int u, int a, int b){
	if(foundCycle){return;}
	dfs_num[u] = explored;
	for(int i=0;i<AdjList[u].size();i++){
		int v = AdjList[u][i];
		// printf("u: %d v: %d a: %d b: %d\n",u,v,a,b);
		if(u==a && v==b){continue;}
		// printf("lanjut\n");
		if(dfs_num[v] == unvisited){
			graphCheckKhusus(v,a,b);
		}
		// printf("halo\n");
		if(dfs_num[v] == explored){
			// printf("masuk snikah\n");
			// printf("ketemu cycle saat u: %d v: %d\n",u,v);
			foundCycle = true;
		}
	}
	dfs_num[u] = visited;
}

int main(){
	int n,m,i,j;
	int a[maxn],b[maxn];
	scanf("%d %d",&n,&m);
	dfs_num.assign(n+1,unvisited);
	AdjList.assign(n+1,vi());
	for(i=0;i<m;i++){
		scanf("%d %d",&a[i],&b[i]);
		AdjList[a[i]].pb(b[i]);
	}
	//cek graphnya ada cycle apa ngga
	foundCycle = false;
	for(i=1;i<=n;i++){
		if(dfs_num[i]==unvisited){graphCheck(i);}
		if(foundCycle){break;}
	}
	if(!foundCycle){printf("YES\n"); return 0;}
	else{
		//cek masing-masing
		// printf("cek\n");
		for(i=0;i<m;i++){
			for(j=1;j<=n;j++){dfs_num[j] = unvisited;}
			// printf("a[%d]: %d b[%d]: %d\n",i,a[i],i,b[i]);
			foundCycle = false;
			for(j=1;j<=n;j++){
				// printf("j: %d\n",j);
				if(dfs_num[j]==unvisited){graphCheckKhusus(j,a[i],b[i]);}
				if(foundCycle){break;}
			}
			if(!foundCycle){printf("YES\n"); return 0;}
		}
	}

	printf("NO\n");
	return 0;
};