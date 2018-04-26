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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> AdjList;
const int maxn = 2e5 + 5;
vi listIdx;
int jumlahTotalNode[maxn];

int countTotalNode(int node, int parent) {
	int ans = 1;
	for(int i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		if(v!=parent) {
			ans+=countTotalNode(v, node);	
		}
		
	}
	return jumlahTotalNode[node] = ans;
}

void dfs(int node, int parent) {
	int i,j;
	for(i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		if(v!=parent) {
			if(jumlahTotalNode[v] % 2==0) {
				dfs(v, node);
			}
		}
	}

	//hapus node
	listIdx.pb(node);
	for(i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		if(v!=parent) {
			if(jumlahTotalNode[v] % 2==1) {
				dfs(v, node);
			}
		}
	}	
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	AdjList.assign(n+3, vector<int>());
	int idxRoot = 0;
	for(i=1;i<=n;i++){
		int parent;
		scanf("%d",&parent);
		if(parent==0){idxRoot = i; continue;}
		AdjList[parent].pb(i); AdjList[i].pb(parent);
	}

	if(n % 2 == 0) {printf("NO\n"); return 0;} //karena jumlah edge ganjil..gamungkin bs dikurangin dengan genap ke 0

	countTotalNode(idxRoot,0);
	
	//proses penghapusan
	dfs(idxRoot, 0);

	printf("YES\n");
	for(i=0;i<listIdx.size();i++){
		printf("%d\n",listIdx[i]);
	}
	return 0;
};