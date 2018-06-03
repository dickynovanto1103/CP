#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define explored 2
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e6 + 6;
int idx[maxn], a[maxn];

vector<vi> AdjList;
int dfs_num[maxn];
ll banyak;
int start[maxn];

void dfs(int node, int banyakDikunjungi) {
	dfs_num[node] = explored;
	start[node] = banyakDikunjungi;
	for(int i=0;i<AdjList[node].size();i++) {
		int v = AdjList[node][i];
		if(dfs_num[v] == unvisited) {
			dfs(v, banyakDikunjungi+1);
		}else if(dfs_num[v] == explored) {
			banyak+=(banyakDikunjungi-start[v]);
			// printf("banyakDikunjungi: %d\n",banyakDikunjungi);
		}
	}
	dfs_num[node] = visited;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	AdjList.assign(n+1,vi());
	banyak = 0;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		idx[a[i]] = i;
		AdjList[i].pb(a[i]);
	}

	memset(dfs_num, unvisited, sizeof dfs_num);
	for(i=1;i<=n;i++) {
		if(dfs_num[i] == unvisited) {
			dfs(i,1);
		}
	}
	// printf("banyak :%lld\n",banyak);
	bool isGenap = (banyak%2==0? true: false);

	if((3*n) % 2==0) {
		if(isGenap){
			printf("Petr\n");	
		}else{
			printf("Um_nik\n");
		}
		
	}else{
		if(isGenap) {
			printf("Um_nik\n");
		}else{
			printf("Petr\n");
		}
		
	}
	// if((3*n) % banyak == 0){
	// 	printf("Petr\n");
	// }else{
	// 	printf("Um_nik\n");
	// }
	return 0;
};