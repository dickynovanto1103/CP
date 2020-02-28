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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> adj;

int main(){
	int n,m,i,j;
	while(scanf("%d %d",&n,&m), (n || m)){
		int a,b;
		adj.assign(n+1, vi());
		int indeg[101];
		memset(indeg, 0, sizeof indeg);
		for(i=0;i<m;i++){
			scanf("%d %d",&a,&b);
			adj[a].pb(b);
			// printf("a pb b: %d %d\n",a, b);
			indeg[b]++;
		}
		
		queue<int> q;
		vi ans;
		for(i=1;i<=n;i++){
			if(indeg[i] == 0){
				// printf("dipush: %d\n",i);
				q.push(i);
			}
		}
		vi can;
		while(true){
			while(!q.empty()){
				int front = q.front(); q.pop();
				// printf("front: %d\n",front);
				for(i=0;i<adj[front].size();i++){
					int v = adj[front][i];
					// printf("v: %d\n",v);
					indeg[v]--;
					if(indeg[v] == 0){
						can.pb(v);
					}
				}
				ans.pb(front);
			}
			for(i=0;i<can.size();i++){
				q.push(can[i]);
			}
			if(can.size() == 0){break;}
			can.clear();
		}
		for(i=0;i<ans.size();i++){
			if(i){printf(" ");}
			printf("%d",ans[i]);
		}
		printf("\n");
		
		adj.clear();
	}
	
	return 0;
};