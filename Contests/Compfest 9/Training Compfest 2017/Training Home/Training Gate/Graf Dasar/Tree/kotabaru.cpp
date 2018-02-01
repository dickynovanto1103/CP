#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> AdjList;
vi dist;

int main() {
	int n,a,b,i;
	scanf("%d",&n);
	AdjList.assign(n+1,vi());
	dist.assign(n+1,inf);
	for(i=0;i<n-1;i++){scanf("%d %d",&a,&b); AdjList[a].pb(b); AdjList[b].pb(a);}
	queue<int> q; q.push(1);
	dist[1] = 0;
	int maks = -inf;
	while(!q.empty()){
		int front = q.front(); q.pop();
		for(i=0;i<AdjList[front].size();i++){
			int v = AdjList[front][i];
			if(dist[v] == inf){
				dist[v] = dist[front] + 1;
				q.push(v);
				maks = max(maks,dist[v]);
			}
		}
	}
	for(i=1;i<=n;i++){
		if(maks==dist[i]){break;}
	}
	//ketemu node i
	dist.assign(n+1,inf);
	dist[i] = 0;
	q.push(i);
	maks = -inf;
	while(!q.empty()){
		int front = q.front(); q.pop();
		for(i=0;i<AdjList[front].size();i++){
			int v = AdjList[front][i];
			if(dist[v] == inf){
				dist[v] = dist[front] + 1;
				q.push(v);
				maks = max(maks,dist[v]);
			}
		}
	}
	printf("%d\n",maks);
	return 0;
}