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

const int maxn = 1e5 + 5;

vector<vii> AdjList;

int col[maxn];

void dfs(int node, int p, int w) {
	// printf("node: %d\n",node);
	col[node] = w;
	for(int i=0;i<AdjList[node].size();i++){
		ii v = AdjList[node][i];
		int tet = v.first, warna = v.second;
		if(tet != p){
			if(warna == 0){
				dfs(tet, node, w);
			}else{
				dfs(tet, node, 1-w);
			}	
		}
		
	}
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	AdjList.assign(n+1,vii());
	for(i=0;i<n-1;i++){
		int a,b,w;
		scanf("%d %d %d",&a,&b,&w);
		w %= 2;
		AdjList[a].pb(ii(b,w)); AdjList[b].pb(ii(a,w));
	}
	dfs(1, -1, 0);
	for(i=1;i<=n;i++){
		printf("%d\n",col[i]);
	}
	return 0;
};