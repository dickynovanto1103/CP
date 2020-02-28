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
vector<vi> AdjList, centroid;
 
int id[maxn];
int sz[maxn];
 
void dfsSizeSubtree(int node, int p) {
	sz[node] = 1;
	for(int i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		if(v!=p) {
			dfsSizeSubtree(v, node);
			sz[node] += sz[v];
		}
	}
}
 
int findCentroid(int node, int ukuran, int label) {
	bool valid = true;
	for(int i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		if(sz[v] > ukuran/2 && id[v] == -1) {
			//pindah ke centroid itu
			valid = false;
 
			sz[node] = ukuran-sz[v];
			sz[v] = ukuran;
 
			int cen = findCentroid(v, ukuran, label);
			id[cen] = label;
			return cen;
		}
	}
	if(valid) {
		id[node] = label;
		return node;
	}else{
		return -1;
	}
}
 
int dfsCentroid(int node, int label) {
	int root = findCentroid(node, sz[node], label);
	id[root] = label;
	for(int i=0;i<AdjList[root].size();i++){
		int v = AdjList[root][i];
		if(id[v] == -1){
			int cen = dfsCentroid(v, label+1);
			centroid[root].pb(cen); centroid[cen].pb(root);
		}
	}
	return root;
}
 
int main(){
	int n,i,j;
	scanf("%d",&n);
	AdjList.assign(maxn, vi());
	centroid.assign(maxn, vi());
	for(i=0;i<n-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		AdjList[a].pb(b); AdjList[b].pb(a);
	}
	dfsSizeSubtree(1, -1);
	memset(id, -1, sizeof id);
	int rootCentroid = dfsCentroid(1,0);
	
	// for(i=1;i<=n;i++){
	// 	printf("node %d:",i);
	// 	for(j=0;j<centroid[i].size();j++){
	// 		printf(" %d(%d)",centroid[i][j], id[centroid[i][j]]);
	// 	}
	// 	printf("\n");
	// }
	return 0;
};