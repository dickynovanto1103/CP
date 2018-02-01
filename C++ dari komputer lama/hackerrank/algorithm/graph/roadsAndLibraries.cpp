#include <bits/stdc++.h>

using namespace std;
#define unvisited -1
#define visited 1
typedef long long ll;
typedef pair<int,int> ii;
typedef vector <int> vi;


vector <vi> AdjList;
vi dfs_num;
ll jalan;


void dfs(int a){
	int i;
	dfs_num[a] = visited;
	for(i=0;i<AdjList[a].size();i++){
		int v = AdjList[a][i];
		if(dfs_num[v]==unvisited){jalan++; dfs(v);}
	}
}


int main(){
	int tc,n,lib,road,u,v;
	ll tot,m,i,cnt;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %lld %d %d",&n,&m,&lib,&road);
		AdjList.assign(n,vi()); 
		for(i=0;i<m;i++){
			scanf("%d %d",&u,&v); u--; v--; 
			AdjList[u].push_back(v); AdjList[v].push_back(u);
		}
		if(lib<=road){
			//printf("n : %d lib: %d\n",n,lib);
			tot = (ll)n*(ll)lib;
			//printf("tot: %lld\n",tot);
		}else{
			//do dfs
			jalan = 0;
			dfs_num.assign(n,unvisited);
			cnt=0;
			for(i=0;i<n;i++){
				if(dfs_num[i]==unvisited){dfs(i); cnt++;}
			}
			//printf("cnt : %lld\n",cnt);
			tot = cnt*(ll)lib + (ll)(jalan)*(ll)road;
			tot = min(tot, (ll)n*(ll)lib);
		}
		AdjList.clear(); dfs_num.clear();
		printf("%lld\n",tot);
		
	}
	return 0;
}