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

vi warna;

int main() {
	int n,m,a,b;	
	int i;
	scanf("%d %d",&n,&m);
	//printf("m: %d\n",m);
	AdjList.assign(n+1,vi());
	int minim = inf;
	for(i=0;i<m;i++){
		
		scanf("%d %d",&a,&b);
		AdjList[a].pb(b); AdjList[b].pb(a);
		minim = min(minim,min(a,b));
	}
	
	if(!m){printf("YA\n");}
	else{
		queue<int> q; q.push(minim);
		warna.assign(n+1,inf);
		bool isBipartite = true;
		while(!q.empty() && isBipartite){
			int node = q.front(); q.pop();
			for(i=0;i<AdjList[node].size();i++){
				int v = AdjList[node][i];
				if(warna[v]==inf){
					warna[v] = 1-warna[node];
					q.push(v);
				}else if(warna[v]==warna[node]){
					isBipartite = false; break;
				}
			}
		}
		if(isBipartite){printf("YA\n");}
		else{printf("TIDAK\n");}	
	}
	
	return 0;
}