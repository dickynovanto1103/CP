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

vector<vi> AdjList;

const int maxn = 2e5 + 5;

int warna[maxn];
bool isBip;

void dfs(int node) {
	if(!isBip){return;}
	int i;
	for(i=0;i<AdjList[node].size();i++) {
		int v = AdjList[node][i];

		if(warna[v] == -1){
			warna[v] = 1 - warna[node];
			dfs(v);
		}else{
			if(warna[node] == warna[v]) {
				isBip = false;
			}
		}
	}
}

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	AdjList.assign(n+1, vi());
	int x[maxn], y[maxn];
	memset(warna, -1, sizeof warna);
	for(i=0;i<m;i++){
		scanf("%d %d",&x[i],&y[i]);
		AdjList[x[i]].pb(y[i]); AdjList[y[i]].pb(x[i]);
	}
	isBip = true;
	warna[1] = 0;
	dfs(1);
	if(isBip){
		printf("YES\n");
		for(i=0;i<m;i++){
			printf("%d",warna[x[i]] < warna[y[i]]);
		}
		printf("\n");
	}else{
		printf("NO\n");
	}
	

	
	return 0;
};