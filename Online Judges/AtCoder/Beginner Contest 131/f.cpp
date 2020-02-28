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

vector<vi> adj;

bool isVisited[maxn];

set<int> kolUnik, rowUnik;
ii a[maxn];

void dfs(int node) {
	isVisited[node] = true;
	rowUnik.insert(a[node].first); kolUnik.insert(a[node].second);
	int i,j;
	for(i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		if(!isVisited[v]){
			dfs(v);
		}
	}
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	
	vector<vi> row, col;
	map<ii, int> mapper;
	row.assign(maxn, vi()); col.assign(maxn, vi());
	for(i=0;i<n;i++){
		scanf("%d %d",&a[i].first, &a[i].second);
		mapper[a[i]] = i;
		row[a[i].first].pb(a[i].second);
		col[a[i].second].pb(a[i].first);
	}
	if(n < 3){printf("0\n");}
	else{
		memset(isVisited, false, sizeof isVisited);
		adj.assign(maxn, vi());
		for(i=1;i<maxn;i++){
			for(j=0;j<(int)row[i].size()-1;j++){
				int kol = row[i][j];
				ii koor = ii(i,kol);
				int idx1 = mapper[koor];
				int kol2 = row[i][j+1];
				ii koor2 = ii(i, kol2);
				int idx2 = mapper[koor2];
				adj[idx1].pb(idx2); adj[idx2].pb(idx1);
			}
		}

		for(i=1;i<maxn;i++){
			for(j=0;j<(int)col[i].size()-1;j++){
				int row = col[i][j];
				ii koor = ii(row,i);
				int idx1 = mapper[koor];
				int row2 = col[i][j+1];
				ii koor2 = ii(row2, i);
				int idx2 = mapper[koor2];
				adj[idx1].pb(idx2); adj[idx2].pb(idx1);
			}
		}

		//iterasi semua row

		ll ans = 0;
		set<int>::iterator it;
		for(i=0;i<n;i++){
			if(!isVisited[i]){
				// printf("visit node %d\n",i);
				kolUnik.clear(); rowUnik.clear();
				dfs(i);
				int ukuranKol = kolUnik.size();
				for(it=rowUnik.begin(); it!=rowUnik.end();it++){
					int ukuranRow = row[*it].size();
					// printf("ukuranKol: %d ukuranRow: %d\n",ukuranKol, ukuranRow);
					ans += (ukuranKol - ukuranRow);
					// printf("ans jd: %lld\n",ans);

				}
			}
		}

		// ll ans = 0;
		// for(i=1;i<maxn;i++){
		// 	for(i=0)
		// }
		// for(i=1;i<maxn;i++){
		// 	if(col[i].size())
		// 		ans += (tot - col[i].size());
		// }
		printf("%lld\n",ans);

	}
	return 0;
};