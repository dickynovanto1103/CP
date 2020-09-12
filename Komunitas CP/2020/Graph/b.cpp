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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,t,i,j;
	scanf("%d %d",&n,&t);
	vector<vi> adj;
	adj.assign(n+1, vi());
	for(i=1;i<=n-1;i++){
		int a;
		scanf("%d",&a);
		adj[i].pb(i + a);
	}
	int dist[30001];
	memset(dist, -1, sizeof dist);
	queue<int> q;
	q.push(1);
	dist[1] = 0;
	while(!q.empty()){
		int front = q.front(); q.pop();
		for(i=0;i<adj[front].size();i++){
			int v = adj[front][i];
			if(dist[v] == -1){
				dist[v] = dist[front] + 1;
				q.push(v);
			}
		}
	}
	if(dist[t] == -1){
		printf("NO\n");
	}else{
		printf("YES\n");
	}
	
	return 0;
};