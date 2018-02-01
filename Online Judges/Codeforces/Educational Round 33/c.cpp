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

const int maxn = 100010;
vector<vi> AdjList;
vi dfs_num;

struct pasangan{
	int idx, gold;
};
bool cmp(pasangan a, pasangan b){return a.gold < b.gold;}

void dfs(int u){
	dfs_num[u] = visited;
	for(int i=0;i<AdjList[u].size();i++){
		int v = AdjList[u][i];
		if(dfs_num[v]==unvisited){
			dfs(v);
		}
	}
}

int main(){
	int n,m,i,j;
	pasangan pas[maxn];
	scanf("%d %d",&n,&m);
	AdjList.assign(n+1,vi());
	dfs_num.assign(n+1,unvisited);
	for(i=0;i<n;i++){scanf("%d",&pas[i].gold); pas[i].idx = i+1;}
	sort(pas,pas+n, cmp);
	// printf("HASIL URUT:\n");
	// for(i=0;i<n;i++){
	// 	printf("%d %d\n",pas[i].idx,pas[i].gold);
	// }
	for(i=0;i<m;i++){
		int bil1,bil2;
		scanf("%d %d",&bil1,&bil2);
		AdjList[bil1].pb(bil2);
		AdjList[bil2].pb(bil1);
	}
	ll ans = 0;
	for(i=0;i<n;i++){
		int idx = pas[i].idx;
		//printf("idx: %d\n",idx);
		if(dfs_num[idx]==unvisited){
			//printf("yang ditambahkan: idx: %d -> %d\n",pas[i].gold);
			ans+=(ll)pas[i].gold;
			dfs(idx);
		}
	}
	printf("%lld\n",ans);
	return 0;
};