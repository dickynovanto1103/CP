#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

#define maxn 212

int s,t,f,mf;
vi p;
int res[maxn][maxn];
int cap[maxn], category[maxn];
vector<vi> AdjList,temp;

void augment(int v, int minEdge){
	// printf("v: %d\n",v);
	if(v==s){f = minEdge; return;}
	else if(p[v]!=-1){
		augment(p[v],min(minEdge,res[p[v]][v]));
		res[p[v]][v]-=f; res[v][p[v]]+=f;
	}
}

int main() {
	int n,m,kat,i,j,a,b,w,test=1;
	scanf("%d %d %d",&n,&m,&kat);
	AdjList.assign(maxn+1,vi());
	temp.assign(maxn+1, vi());
	memset(res,0,sizeof res);
	
	s = 0, t = n+m+1;

	for(i=1;i<=n;i++){
		int banyak;
		scanf("%d",&banyak);

		for(j=0;j<banyak;j++){
			int bil;
			scanf("%d",&bil);
			temp[i].pb(bil);
		}

		// scanf("%d %d %d",&a,&b,&w);
		// res[a][b] +=w; res[b][a] += w;
		// AdjList[a].pb(b); AdjList[b].pb(a);
	}
	// for(i=1;i<=n;i++){
	// 	printf("temp %d:",i);
	// 	for(j=0;j<temp[i].size();j++){
	// 		printf(" %d",temp[i][j]);
	// 	}
	// 	printf("\n");

	// 	// scanf("%d %d %d",&a,&b,&w);
	// 	// res[a][b] +=w; res[b][a] += w;
	// 	// AdjList[a].pb(b); AdjList[b].pb(a);
	// }
	bool isVisited[maxn];
	memset(isVisited, false, sizeof isVisited);

	for(i=1;i<=kat;i++){
		int banyak;
		scanf("%d",&banyak);
		for(j=0;j<banyak;j++){
			int bil;
			scanf("%d",&bil);
			isVisited[bil] = true;
			category[bil] = i;

			// printf("category[%d]: %d\n",bil,category[bil]);
		}
		scanf("%d",&cap[i]);
		AdjList[i+n].pb(t);
		res[i+n][t] = cap[i];
	}

	for(i=1;i<=m;i++){
		if(!isVisited[i]){
			category[i] = ++kat;
			// printf("category[%d]: %d\n",i,category[i]);
			AdjList[n+kat].pb(t);
			res[n+kat][t] = 1;
		}
	}


	for(i=1;i<=n;i++){
		int ukuran = temp[i].size();
		for(j=0;j<ukuran;j++){
			int bil = temp[i][j];
			int kategori = category[bil];
			AdjList[i].pb(kategori + n);

			res[i][kategori+n]=inf;
			// printf("dipush %d ke %d\n",i, kategori+n);
			// printf("res[%d][%d] jd: %d\n",i,kategori+n, res[i][kategori+n]);
		}
	}
	// printf("halo\n");
	for(i=1;i<=n;i++){
		AdjList[s].pb(i);
		res[s][i] = 1;
	}

	mf = 0;
	  while (1) {                     // now a true O(VE^2) Edmonds Karp's algorithm
	    f = 0;
	    bitset<maxn> vis; vis[s] = true;            // we change vi dist to bitset!
	    queue<int> q; q.push(s);
	    p.assign(maxn, -1);
	    while (!q.empty()) {
	      int u = q.front(); q.pop();
	      if (u == t) break;
	      for (int j = 0; j < (int)AdjList[u].size(); j++) {  // we use AdjList here!
	        int v = AdjList[u][j];
	        if (res[u][v] > 0 && !vis[v])
	          vis[v] = true, q.push(v), p[v] = u;
	      }
	    }
	    augment(t, inf);
	    if (f == 0) break;
	    mf += f;
	  }
	printf("%d\n",mf);
	
	
	return 0;
}