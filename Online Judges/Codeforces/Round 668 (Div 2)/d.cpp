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

vector<vi> adj;
const int maxn = 1e5 + 5;

void bfs(int node, vi& dist) {
	dist[node] = 0;
	queue<int> q;
	q.push(node);
	while(!q.empty()){
		int front = q.front(); q.pop();
		for(int i=0;i<adj[front].size();i++){
			int v = adj[front][i];
			if(dist[v] == inf){
				dist[v] = dist[front] + 1;
				q.push(v);
			}
		}
	}
}

const string alice = "Alice";
const string bob = "Bob";

int main(){
	int tc,i,j,n,a,b,da,db;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %d %d %d",&n,&a,&b,&da,&db);
		adj.assign(n+1, vi());
		vi dista, distb, distc;
		dista.assign(n+1, inf);
		distb.assign(n+1, inf);
		distc.assign(n+1, inf);
		
		for(i=0;i<n-1;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			adj[x].pb(y); adj[y].pb(x);
		}

		if(da >= db){cout<<alice<<endl; continue;}
		if(2*da >= db){cout<<alice<<endl; continue;} //not needed actually, since it will be covered at the last check
		bfs(a, dista);
		bfs(b, distb);
		if(dista[b] <= da){cout<<alice<<endl; continue;}
		// printf("\n");
		// for(i=1;i<=n;i++){
		// 	printf("dista[%d]: %d\n",i, dista[i]);
		// }

		//cari diameter tree
		int nodeTerjauh = -1, jarakA = 0;
		for(i=1;i<=n;i++){
			if(jarakA < distb[i]){
				jarakA = distb[i];
				nodeTerjauh = i;
			}
		}
		assert(nodeTerjauh != -1);
		bfs(nodeTerjauh, distc);
		int diameter = 0, nodeTerjauh2 = -1;
		for(i=1;i<=n;i++){
			if(diameter < distc[i]){
				diameter = distc[i];
				nodeTerjauh2 = i;
			}
		}
		if(diameter <= 2*da){ //this condition can be always winning for alice because she can just wait at the center of the tree, and whatever bob's next move is, alice can just capture bob
			cout<<alice<<endl;
			continue;
		}

		if(db > 2*da){ //bukan diameter >= db...harusnya db > 2*da, this is because there are 2 possible cases:
			//1. after alice's first move, if there is area 
			cout<<bob<<endl;
		}else{
			cout<<alice<<endl;
		}
	}
	
	return 0;
};