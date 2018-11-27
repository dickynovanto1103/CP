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
const int maxn = 1e4 + 4;

int dist[maxn];

void bfs(int node){
	fill(dist, dist+maxn,inf);
	dist[node] = 0;
	queue<int> q;
	q.push(node);

	while(!q.empty()){
		int front = q.front(); q.pop();
		for(int i=0;i<AdjList[front].size();i++){
			int v = AdjList[front][i];
			if(dist[v] == inf){
				dist[v] = dist[front] + 1;
				q.push(v);
			}
		}
	}
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	AdjList.assign(n+1,vi());
	for(i=0;i<(n-1);i++){
		int a,b;
		scanf("%d %d",&a,&b);
		AdjList[a].pb(b); AdjList[b].pb(a);
	}

	
	
	bfs(1);
	
	int node, maks = 0;
	for(i=1;i<=n;i++){
		if(dist[i] > maks){
			maks = dist[i];
			node = i;
		}
	}

	bfs(node);
	maks = 0;
	for(i=1;i<=n;i++){
		maks = max(maks, dist[i]);
	}
	printf("%d\n",maks);
	return 0;
};