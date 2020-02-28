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
const int maxn = 5e5 + 5;
int a[maxn], b[maxn];

int vertex[300001];
int edge[maxn];
bool vis[maxn];
int degree[maxn];
int cnt[300001];
map<ii,int> mapper;

void dfs(int n, int tingkat) {
	// printf("n: %d\n",n);
	vertex[n] = tingkat % 2;
	vis[n] = true;
	int i,j;
	for(i=0;i<adj[n].size();i++){
		int v = adj[n][i];
		if(!vis[v]){
			int idxEdge = mapper[ii(n,v)];
			edge[idxEdge] = tingkat%2;
			dfs(v, tingkat+1);
		}
	}
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		mapper.clear();
		int n,m;
		scanf("%d %d",&n,&m);
		for(i=1;i<=3*n;i++){
			vis[i] = false;
			degree[i] = 0;
			vertex[i] = 0;
		}
		adj.assign(3*n+1, vi());
		for(i=0;i<m;i++){
			scanf("%d %d",&a[i],&b[i]);
			adj[a[i]].pb(b[i]); adj[b[i]].pb(a[i]);
			mapper[ii(a[i], b[i])] = i;
			mapper[ii(b[i], a[i])] = i;
			degree[a[i]]++;
			degree[b[i]]++;
		}
		
		for(i=1;i<=3*n;i++){
			dfs(i,0);
		}
		vector<set<int>> daftar, listEdge;
		set<int>::iterator it;
		daftar.assign(2, set<int>());
		listEdge.assign(2, set<int>());
		for(i=1;i<=3*n;i++){
			daftar[vertex[i]].insert(i);
		}
		bool valid = false;
		for(i=0;i<2;i++){	
			for(j=0;j<m;j++){
				int x = a[j], y = b[j];
				// printf("x: %d y: %d\n",x,y);
				if(daftar[i].find(x) != daftar[i].end() && daftar[i].find(y) != daftar[i].end()) {
					if(degree[x] > degree[y]){
						daftar[i].erase(x);
						// printf("dihapus %d\n",x);
					}else{
						daftar[i].erase(y);
						// printf("dihapus %d\n",y);
					}
				}
			}
			if(daftar[i].size() >= n){
				bool printed = false;
				valid = true;
				printf("IndSet\n");
				// printf("i: %d\n",i);
				int cnt = 0;
				for(it=daftar[i].begin(); it!=daftar[i].end();it++){
					if(printed){printf(" ");}
					printf("%d",*it);
					cnt++;
					if(cnt == n){break;}
					printed = true;
				}
				printf("\n");
				break;
			}
		}
		for(i=0;i<m;i++){
			listEdge[edge[i]].insert(i);
		}

		for(i=0;i<2;i++){
			for(j=1;j<=3*n;j++){cnt[j] = 0;}
			for(it=listEdge[i].begin();it!=listEdge[i].end();it++){
				int idx = *it;
				int x = a[idx], y = b[idx];
				cnt[x]++; cnt[y]++;

			}
		}
		//buat cari matching
		int minim = inf, idx;
		for(i=1;i<=3*n;i++){
			if(minim > degree[i]){
				minim = degree[i];
				idx = i;
			}
		}
		
		
		//find matching ...bikin edge genap ganjil terus catet semua counter vertex...hilangin sampe semua 1

		//find independent match

	}
	return 0;
};