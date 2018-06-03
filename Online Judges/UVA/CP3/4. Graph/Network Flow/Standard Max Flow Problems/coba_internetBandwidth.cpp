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

const int maxn = 1e2 + 2;
int res[maxn][maxn], s,t,mf,f;
vi p;//parent
vector<vi> AdjList;

void augment(int node, int minEdge) {
	if(node == s){f = minEdge; return;}
	else if(p[node] != -1){
		augment(p[node], min(minEdge, res[p[node]][node]));
		res[p[node]][node] -= f; res[node][p[node]] += f;
	}
}

int main(){
	int n,i,j;
	int tc = 1;
	while(scanf("%d",&n), n) {
		printf("Network %d\n", tc++);
		int m;
		scanf("%d %d %d",&s,&t,&m);
		memset(res,0,sizeof res);
		AdjList.assign(n+1, vi());
		for(i=0;i<m;i++){
			int u,v,w;
			scanf("%d %d %d",&u,&v,&w);
			AdjList[u].pb(v);
			AdjList[v].pb(u);
			res[u][v] += w; res[v][u] += w;
		}

		//maxflow
		
		mf = 0;
		while(1) {
			f = 0;
			p.assign(n+1,-1);
			bitset<maxn> isVisited; isVisited[s] = true; p[s] = -1;

			// printf("test\n");
			queue<int> q; q.push(s);

			while(!q.empty()) {
				int front = q.front(); q.pop();
				if(front==t){break;}
				for(i=0;i<AdjList[front].size();i++){
					int v = AdjList[front][i];
					if(res[front][v] > 0 && !isVisited[v]) {
						isVisited[v] = true; q.push(v); p[v] = front;
					}
				}
			}
			augment(t, inf);
			if(f==0){break;}
			mf+=f;
		}

		AdjList.clear();
		p.clear();
		printf("The bandwidth is %d.\n\n",mf);
	}

	return 0;
};