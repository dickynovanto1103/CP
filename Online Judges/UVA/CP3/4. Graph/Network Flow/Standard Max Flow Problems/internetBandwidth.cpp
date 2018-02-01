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

#define maxn 102

int s,t,f,mf;
vi p;
int res[maxn][maxn];
vector<vi> AdjList;

void augment(int v, int minEdge){
	if(v==s){f = minEdge; return;}
	else if(p[v]!=-1){
		augment(p[v],min(minEdge,res[p[v]][v]));
		res[p[v]][v]-=f; res[v][p[v]]+=f;
	}
}

int main() {
	int n,i,j,a,b,w,test=1;
	while(scanf("%d",&n),n){
		AdjList.assign(n+1,vi());
		printf("Network %d\n",test++);
		memset(res,0,sizeof res);
		int m;
		scanf("%d %d %d",&s,&t,&m); s--; t--;
		for(i=0;i<m;i++){
			scanf("%d %d %d",&a,&b,&w); a--; b--;
			res[a][b] +=w; res[b][a] += w;
			AdjList[a].pb(b); AdjList[b].pb(a);
		}

		/*for(i=1;i<=n;i++){
			printf("node %d:",i);
			for(j=0;j<AdjList[i].size();j++){
				ii v = AdjList[i][j];
				printf(" %d(%d)",v.first,AdjList[i][j].second);
			}
			printf("\n");
		}*/
		/*mf = 0;
		while(1){
			f = 0;
			p.assign(maxn,-1);
			bitset<maxn> vis; vis[s] = true;
			queue<int> q; q.push(s);
			while(!q.empty()){
				int u = q.front(); q.pop();
				if(u==t){break;}
				for(i=0;i<AdjList[u].size();i++){
					int v = AdjList[u][i];
					if(res[u][v] > 0 && !vis[v]){
						vis[v] = true; q.push(v); p[v] = u;
					}
				}
			}
			augment(t,inf);
			//printf("f: %d\n",f);
			if(f==0){break;}

			mf+=f;
		}*/
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
		printf("The bandwidth is %d.\n\n",mf);
		AdjList.clear(); p.clear();
	}
	
	return 0;
}