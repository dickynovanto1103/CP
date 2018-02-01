#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> AdjList;

int main() {
	int n,q,i,v,u;
	int warna[1010];
	scanf("%d",&n);
	AdjList.assign(n+1,vi());
	for(i=1;i<=n;i++){scanf("%d",&warna[i]);}
	for(i=1;i<=n-1;i++){scanf("%d %d",&u,&v); AdjList[u].pb(v);}
	scanf("%d",&q);
	while(q--){
		int node,queryWarna;
		scanf("%d %d",&node,&queryWarna);
		int ans = 0;
		for(i=0;i<AdjList[node].size();i++){
			v = AdjList[node][i];
			if(warna[v]==queryWarna){ans++;}
		}
		if(warna[node]==queryWarna){ans++;}
		printf("%d\n",ans);
	}
	return 0;
}