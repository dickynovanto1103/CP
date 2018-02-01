#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 10001;

vector<vi> AdjList;

int main() {
	int tc,n,m,i,j,k;
	scanf("%d",&tc);
	int test = 1;
	while(tc--){
		printf("Case #%d:\n",test++);
		AdjList.assign(maxn,vi());
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&m);
			vi listBil;
			int bil;
			for(j=0;j<m;j++){
				scanf("%d",&bil); listBil.pb(bil);
			}
			for(j=0;j<m-1;j++){
				int bil1 = listBil[j], bil2 = listBil[j+1];
				AdjList[bil1].pb(bil2); AdjList[bil2].pb(bil1);
			}

		}
		int q;
		scanf("%d",&q);
		while(q--){
			int a,b;
			scanf("%d %d",&a,&b);
			vi dist;
			queue<int> q;
			dist.assign(maxn,inf);
			dist[a] = 0; q.push(a);
			while(!q.empty()){
				int u = q.front(); q.pop();
				for(i=0;i<AdjList[u].size();i++){
					int v = AdjList[u][i];
					if(dist[v]==inf){
						dist[v] = dist[u] + 1; q.push(v);
					}
				}
			}
			if(dist[b]==inf){printf("-1\n");}
			else{printf("%d\n",dist[b]);}
		}
		AdjList.clear();
	}
	return 0;
}