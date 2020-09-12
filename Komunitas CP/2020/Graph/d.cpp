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
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	vector<vi> adj;
	adj.assign(n+1, vi());
	for(i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a].pb(b); adj[b].pb(a);
	}

	int color[100001];
	memset(color, -1, sizeof color);
	queue<int> q;
	for(i=1;i<=n;i++){
		if(color[i] == -1){
			q.push(i);
			color[i] = 0;
			while(!q.empty()){
				int front = q.front(); q.pop();
				for(j=0;j<adj[front].size();j++){
					int v = adj[front][j];
					if(color[v] == -1){
						color[v] = 1 - color[front];
						q.push(v);
					}else if(color[v] == color[front]){
						printf("-1\n");
						return 0;
					}
				}
			}
		}
	}

	vi list[2];
	for(i=1;i<=n;i++){
		assert(color[i] != -1);
		list[color[i]].pb(i);
	}
	for(i=0;i<2;i++){
		int sz = list[i].size();
		printf("%d\n",sz);
		for(j=0;j<sz;j++){
			if(j){printf(" ");}
			printf("%d",list[i][j]);
		}
		printf("\n");
	}
	
	return 0;
};