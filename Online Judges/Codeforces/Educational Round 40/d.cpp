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

const int maxn = 1e3 + 3;
int distAwal[maxn], distAkhir[maxn];

void bfs(int node, int awal) {
	queue<int> q;
	q.push(node);
	if(awal) {
		distAwal[node] = 0;
	}else{
		distAkhir[node] = 0;
	}
	while(!q.empty()) {
		int front = q.front(); q.pop();
		for(int i=0;i<AdjList[front].size();i++) {
			int v = AdjList[front][i];
			if(awal) {
				if(distAwal[v]==inf){
					distAwal[v] = distAwal[front] + 1;
					q.push(v);
				}
			}else {
				if(distAkhir[v] == inf) {
					distAkhir[v] = distAkhir[front] + 1;
					q.push(v);
				}
			}
		}
	}
}

int main(){
	int n,m,s,t;
	int i,j;
	scanf("%d %d %d %d",&n,&m,&s,&t);
	AdjList.assign(n+1,vi());
	for(i=0;i<m;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		AdjList[u].pb(v); AdjList[v].pb(u);
	}
	fill(distAkhir,distAkhir+maxn,inf);
	fill(distAwal,distAwal+maxn,inf);
	//bfs dari awal dan akhir
	bfs(s,1);
	bfs(t,0);
	bool isVisited[maxn];
	int jarakMinimal = distAwal[t];
	int cnt = 0;
	for(i=1;i<=n;i++){
		memset(isVisited,false,sizeof isVisited);
		isVisited[i] = true;
		for(j=0;j<AdjList[i].size();j++){
			int v = AdjList[i][j];
			isVisited[v] = true;
		}
		for(j=1;j<=n;j++) {
			if(!isVisited[j]) {
				//cari jarak
				int jarak1 = distAwal[i] + distAkhir[j] + 1;
				int jarak2 = distAwal[j] + distAkhir[i] + 1;
				int jarak = min(jarak1,jarak2);
				if(jarakMinimal<=jarak) {
					cnt++;
				}
			}
		}
	}
	printf("%d\n",cnt/2);
	return 0;
};