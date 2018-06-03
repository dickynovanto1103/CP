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

vector<vi> AdjList;
const int maxn = 110;

int s,t,mf,f, res[2*maxn][2*maxn];
vi p;

void augment(int node, int minEdge) {
	if(node == s){f = minEdge; return;}
	else if(p[node] != -1){
		augment(p[node], min(minEdge, res[p[node]][node]));
		res[p[node]][node] -= f; res[node][p[node]] += f;
	}
}

void maxflow() {
	mf = 0;
	while(1) {
		bitset<2*maxn> isVisited; isVisited[s] = true;
		f = 0;
		p.assign(maxn*2, -1);
		queue<int> q; q.push(s); p[s] = -1;
		while(!q.empty()) {
			int front = q.front(); q.pop();
			for(int i=0;i<AdjList[front].size();i++){
				int v = AdjList[front][i];
				if(!isVisited[v] && res[front][v] > 0){
					q.push(v); p[v] = front; isVisited[v] = true;
				}
			}
		}
		augment(t, inf);
		if(f==0){break;}
		mf+=f;
	}
}

int main(){
	int n,m,waktu,v;
	int i,j;
	double x1[maxn],y1[maxn],x2[maxn],y2[maxn];
	while(scanf("%d %d %d %d",&n,&m,&waktu,&v)!=EOF) {
		AdjList.assign(n+m+2,vi());
		double jarakMaks = (double)waktu*v;
		for(i=1;i<=n;i++){
			scanf("%lf %lf",&x1[i],&y1[i]);
		}
		for(i=1;i<=m;i++){
			scanf("%lf %lf",&x2[i],&y2[i]);
		}
		memset(res,0,sizeof res);
		s = 0; t = n+m+1;
		for(j=n+1;j<=(n+m);j++){
			AdjList[j].pb(t);
			res[j][t] = 1;
		}

		for(i=1;i<=n;i++){
			AdjList[s].pb(i);
			res[s][i] = 1;
			for(j=1;j<=m;j++){
				double jarak = hypot(x1[i] - x2[j], y1[i] - y2[j]);
				if(fabs(jarak-jarakMaks) < eps || jarak < jarakMaks) {
					AdjList[i].pb(n+j);
					AdjList[n+j].pb(i);
					res[i][n+j] = 1;
				}
			}
		}
		maxflow();
		printf("%d\n", n-mf);
	}
	
	return 0;
};