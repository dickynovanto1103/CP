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

const int maxn = 3e5 + 5;

int color[maxn];
int totColor[maxn][3];
vector<vi> AdjList;

void dfs(int node, int p) {
	totColor[node][color[node]] = 1;
	for(int i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		if(v != p){
			dfs(v, node);
			for(int j=0;j<3;j++){
				totColor[node][j] += totColor[v][j];
			}
		}
	}
}

int cnt;

void dfs2(int node, int p) {
	int i,j;
	for(i=0;i<AdjList[node].size();i++) {
		int v = AdjList[node][i];
		if(v != p) {
			int satu = totColor[v][1];
			int dua = totColor[v][2];
			int sisa1 = totColor[1][1] - satu;
			int sisa2 = totColor[1][2] - dua;
			// printf("node: %d v: %d satu: %d dua: %d sisa1: %d sisa2: %d\n",node, v, satu, dua, sisa1, sisa2);
			if((satu > 0 && dua > 0) || (sisa1 > 0 && sisa2 > 0)) {

			}else{

				cnt++;
			}
			dfs2(v, node);
		}
		
	}
}

int main(){
	int n,i,j;
	AdjList.assign(maxn, vi());
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&color[i]);
	}
	for(i=0;i<n-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		AdjList[a].pb(b); AdjList[b].pb(a);
	}
	dfs(1,-1);
	dfs2(1,-1);
	printf("%d\n",cnt);
	return 0;
};